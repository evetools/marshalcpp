//==========================================================================
// Name        : reader.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "reader.h"

namespace evetools {

namespace marshal {

python::pybase* (reader::* const reader::m_loadPyMethods[MASK + 1])() = {
	&reader::loadError, //0x00
	&reader::loadNone,//0x01
	&reader::loadGlobal,//0x02
	&reader::loadInt64,//0x03
	&reader::loadInt32,//0x04
	&reader::loadInt16,//0x05
	&reader::loadInt8,//0x06
	&reader::loadMinusOne,//0x07
	&reader::loadZero,//0x08
	&reader::loadOne,//0x09
	&reader::loadDouble,//0x0a
	&reader::loadDoubleZero,//0x0b
	&reader::loadError,//0x0c
	&reader::loadError,//0x0d
	&reader::loadString0,//0x0e
	&reader::loadString1,//0x0f
	&reader::loadString,//0x10
	&reader::loadStringRef,//0x11
	&reader::loadUnicode,//0x12
	&reader::loadBuffer,//0x13
	&reader::loadTuple,//0x14
	&reader::loadList,//0x15
	&reader::loadDict,//0x16
	&reader::loadInstance,//0x17
	&reader::loadError,//0x18
	&reader::loadError,//0x19
	&reader::loadError,//0x1a
	&reader::loadReference,//0x1b
	&reader::loadError,//0x1c
	&reader::loadError,//0x1d
	&reader::loadError,//0x1e
	&reader::loadTrue,//0x1f
	&reader::loadFalse,//0x20
	&reader::loadError,//0x21
	&reader::loadReduce,//0x22
	&reader::loadObjectEX,//0x23
	&reader::loadTupleEmpty,//0x24
	&reader::loadTupleOne,//0x25
	&reader::loadListEmpty,//0x26
	&reader::loadListOne,//0x27
	&reader::loadUnicode0,//0x28
	&reader::loadUnicode1,//0x29
	&reader::loadPacked,//0x2a
	&reader::loadSubStream,//0x2b
	&reader::loadTupleTwo,//0x2c
	&reader::loadMarker,//0x2d
	&reader::loadBuffer,//0x2e // utf8
	&reader::loadVarInt,//0x2f
	&reader::loadError,//0x30
	&reader::loadError,//0x31
	&reader::loadError,//0x32
	&reader::loadError,//0x33
	&reader::loadError,//0x34
	&reader::loadError,//0x35
	&reader::loadError,//0x36
	&reader::loadError,//0x37
	&reader::loadError,//0x38
	&reader::loadError,//0x39
	&reader::loadError//0x3a
};

reader::reader() :
		m_stream(NULL), m_storage(NULL), m_objects(NULL) {
}

reader::reader(const std::string& path) :
		m_stream(NULL), m_storage(NULL), m_objects(NULL) {

	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		std::stringstream stream;
		stream << "Unable to open file : " << path;
		throw std::runtime_error(stream.str().c_str());
	}

	m_stream = new istream(ifs);

	ifs.close();

	m_iterator = m_stream->begin();
}

reader::reader(const istream& stream) :
		m_stream(NULL), m_storage(NULL), m_objects(NULL) {
	m_iterator = stream.begin();
}

reader::~reader() {
	if (m_stream) {
		delete (m_stream);
	}
	if (m_storage) {
		delete (m_storage);
	}
	if (m_objects) {
		delete (m_objects);
	}
}

void reader::store(python::pybase* base, size_t position) {

	if (!m_storage) {
		throw std::runtime_error("shared storage empty");
	}

	python::pybase** py = &m_storage->at(--position);

	*py = base;
}

python::pybase* reader::stored(size_t position) {

	if (!m_storage) {
		throw std::runtime_error("shared storage empty");
	}

	if (position > m_storage->capacity()) {
		std::stringstream stream;
		stream << "storaged exceeded position: ";
		stream << --position << " size:";
		stream << m_storage->capacity();
		throw std::range_error(stream.str());
	}

	return (m_storage->at(--position));
}

python::pyobjectex* reader::replace(python::pybase* header, python::pyobjectex* object,
		bool reduce) {

	if (header && object && object->isObjectEx()
			&& header->isTuple() && header->asTuple()->size() > 0) {

		if (header->asTuple()->at(0)->isGlobal()) {
			if (header->asTuple()->at(0)->asGlobal()->str().compare(
					"blue.DBRowDescriptor") == 0) {
				return (new python::pydbrowdescriptor(reduce));
			} else {
				//throw loadErrorException(header->asTuple()->at(0)->asGlobal()->str());
			}
		} else if (header->asTuple()->at(0)->isTuple()
				&& header->asTuple()->at(0)->asTuple()->size() > 0
				&& header->asTuple()->at(0)->asTuple()->at(0)->isGlobal()) {
			if (header->asTuple()->at(0)->asTuple()->at(0)->asGlobal()->str().compare(
					"dbutil.RowList") == 0) {
				return (new python::pydbrowlist(reduce));
			} else if (header->asTuple()->at(0)->asTuple()->at(0)->asGlobal()->str().compare(
					"dbutil.CRowset") == 0) {
				return (new python::pydbcrowset(reduce));
			} else {
//				std::stringstream stream;
//				dumpvisitor visitor(stream);
//				header->visit(visitor);
//				throw loadErrorException(stream.str());
			}
		} else {
//			std::stringstream stream;
//			dumpvisitor visitor(stream);
//			header->visit(visitor);
//			throw loadErrorException(stream.str());
		}
	} else {
//		std::stringstream stream;
//		dumpvisitor visitor(stream);
//		header->visit(visitor);
//		throw loadErrorException(stream.str());
	}

	return (object);
}

void reader::replace(python::pybase* objectOld, python::pybase* objectNew) {

	std::vector<python::pybase*>::iterator iterator = m_storage->begin();
	std::vector<python::pybase*>::iterator end = m_storage->end();

	size_t pos = 0;

	for (; iterator != end; ++iterator) {

		if ((*iterator) == objectOld) {
			python::pybase** py = &m_storage->at(pos);
			*py = objectNew;
		}
		++pos;
	}
}

bool reader::isStored(python::pybase* object) {

	std::vector<python::pybase*>::iterator iterator = m_storage->begin();
	std::vector<python::pybase*>::iterator end = m_storage->end();

	for (; iterator != end; ++iterator) {

		if ((*iterator) == object) {
			return true;
		}
	}

	return false;
}

python::pybase* reader::read() {

	const uint8_t protocol = m_iterator.read<uint8_t>();

	if (protocol != TYPE_PROTOCOL) {
		throw std::runtime_error("Invalid stream.");
	}

	const uint32_t shared = m_iterator.read<uint32_t>();

	m_shareIterator = (m_iterator);
	m_shareIterator +=
			(m_iterator.max() - (sizeof(uint8_t) + sizeof(uint32_t)));
	m_shareIterator -= (sizeof(uint32_t) * shared);

	m_storage = new std::vector<python::pybase*>(shared, NULL);
	m_objects = new std::stack<python::pybase*>();

	python::pybase* py = NULL;

	py = loadPy();

	return (py);
}

python::pybase* reader::loadPy() {

	m_magic = m_iterator.read<uint8_t>();

	const bool shared = (m_magic & SHARED) != 0;
	m_type = (m_magic & MASK);

	if ((m_magic & UNKNOWN) != 0) {
		loadError();
	}

	python::pybase* py = (this->*m_loadPyMethods[m_type])();

	if (shared) {
		if (py->type() == python::PYTYPE_GLOBAL
				&& (py->asGlobal()->str().compare("blue.DBRowDescriptor") == 0)) {
			assert(m_objects->top());
			store(m_objects->top(), m_shareIterator.read<uint32_t>());
		} else {
			store(py, m_shareIterator.read<uint32_t>());
		}
	}

	return (py);
}

python::pybase* reader::loadError() {
	std::stringstream stream;
	std::ios::fmtflags flags = stream.flags();
	stream << "Magic: ";
	stream << "0x" << std::hex << std::setw(2);
	stream << std::setfill('0') << (int) m_magic;
	stream.setf(flags);
	stream << " Type: ";
	stream << "0x" << std::hex << std::setw(2);
	stream << std::setfill('0') << (int) m_type;
	stream.setf(flags);
	stream << " Offset:";
	stream << " 0x" << std::hex << std::setw(8) << m_iterator.pos() - 1;
	stream.setf(flags);
	stream << " (" << std::setw(8) << m_iterator.pos() - 1 << ")";
	throw loadErrorException(stream.str());
}

python::pybase* reader::loadNone() {
	return (new python::pynone());
}

python::pybase* reader::loadMarker() {
	return loadError();
}

python::pybase* reader::loadTrue() {
	return (new python::pybool(true));
}

python::pybase* reader::loadFalse() {
	return (new python::pybool(false));
}

python::pybase* reader::loadZero() {
	return (new python::pyint(0));
}

python::pybase* reader::loadOne() {
	return (new python::pyint(1));
}

python::pybase* reader::loadMinusOne() {
	return (new python::pyint(-1));
}

python::pybase* reader::loadInt8() {
	return (new python::pyint(m_iterator.read<int8_t>()));
}

python::pybase* reader::loadInt16() {
	return (new python::pyint(m_iterator.read<int16_t>()));
}

python::pybase* reader::loadInt32() {
	return (new python::pyint(m_iterator.read<int32_t>()));
}

python::pybase* reader::loadInt64() {
	return (new python::pylong(m_iterator.read<int64_t>()));
}

python::pybase* reader::loadVarInt() {

	size_t size = loadLength();

	char* buffer = m_iterator.read<char>(size);

	if (sizeof(int8_t) >= size) {
		int8_t intval = 0;
		memcpy(&intval, &*buffer, size);
		delete [] buffer;
		return new python::pyint(intval);
	} else if (sizeof(int16_t) >= size) {
		int16_t intval = 0;
		memcpy(&intval, &*buffer, size);
		delete [] buffer;
		return new python::pyint(intval);
	} else if (sizeof(int32_t) >= size) {
		int32_t intval = 0;
		memcpy(&intval, &*buffer, size);
		delete [] buffer;
		return new python::pyint(intval);
	} else if (sizeof(int64_t) >= size) {
		int64_t intval = 0;
		memcpy(&intval, &*buffer, size);
		delete [] buffer;
		return new python::pylong(intval);
	} else {
		python::pybase* py = new python::pybuffer(buffer, size);
		delete [] buffer;
		return (py);
	}
}

python::pybase* reader::loadDouble() {
	return (new python::pydouble(m_iterator.read<double>()));
}

python::pybase* reader::loadDoubleZero() {
	return (new python::pydouble(0.0f));
}

python::pybase* reader::loadBufferN(size_t size) {

	char* buffer = m_iterator.read<char>(size);

	if (buffer[0] == COMPRESSED) {

		uint8_t factor = 0;
		unsigned char* ubuffer = NULL;
		size_t usize = size;
		int res = 0;

		do {

			if (ubuffer) {
				delete[] ubuffer;
			}

			usize = size << ++factor;

			ubuffer = new unsigned char[usize];

			res = uncompress((Bytef*) ubuffer, (uLongf*) &usize,
					(const Bytef*) buffer, (uLongf) size);

		} while (Z_BUF_ERROR == res);

		if (res == Z_OK) {

			delete[] buffer;

			if (ubuffer[0] == TYPE_PROTOCOL) {

				istream stream((char*) ubuffer, usize);

				reader subreader(stream);

				delete[] ubuffer;

				return (subreader.read());
			} else {

				python::pybuffer* element = new python::pybuffer(
						(char*) ubuffer, usize);

				delete[] ubuffer;

				return (element);
			}
		} else {
			delete[] ubuffer;
		}
	}

	python::pybuffer* element = new python::pybuffer(buffer, size);
	delete[] buffer;

	return (element);
}

python::pybase* reader::loadBuffer() {
	size_t size = loadLength();
	return (loadBufferN(size));
}

python::pybase* reader::loadUnicodeN(size_t size) {

	python::pybuffer* element = NULL;

	if (size > 0) {
		unsigned short* buffer = m_iterator.read<unsigned short>(size);

		std::vector<unsigned char> utf8result;
		utf8::utf16to8(buffer, buffer + size, std::back_inserter(utf8result));
		delete[] buffer;
		std::stringstream stream;
		std::vector<unsigned char>::const_iterator begin = utf8result.begin();
		std::vector<unsigned char>::const_iterator end = utf8result.end();

		for (; begin != end; ++begin) {
			stream << (*begin);
		}

		element = new python::pybuffer(stream.str().c_str(),
				stream.str().length());
	} else {
		element = new python::pybuffer(NULL, 0);
	}

	return (element);
}

python::pybase* reader::loadUnicode() {
	return (loadUnicodeN(loadLength()));
}

python::pybase* reader::loadUnicode1() {
	return (loadUnicodeN(1));
}

python::pybase* reader::loadUnicode0() {
	return (loadUnicodeN(0));
}

python::pybase* reader::loadString0() {
	return (loadStringN(0));
}

python::pybase* reader::loadString1() {
	return (loadStringN(1));
}

python::pybase* reader::loadString() {
	size_t size = loadLength();
	return (loadStringN(size));
}

python::pybase* reader::loadStringN(size_t size) {
	return (loadBufferN(size));
}

python::pybase* reader::loadGlobal() {

	size_t size = loadLength();
	char* buffer = m_iterator.read<char>(size);

	python::pyglobal* global = new python::pyglobal(buffer, size);

	delete[] buffer;

	return (global);
}

python::pybase* reader::loadStringRef() {

	size_t pos = loadLength();

	if (!strings::has(pos)) {
		std::stringstream stream;
		stream << "Loading STRINGREF - pos: " << pos << std::endl;
		throw loadErrorException(stream.str());
	}

	std::string str = strings::get(pos);

	return (new python::pybuffer(str.c_str(), str.length()));
}

python::pybase* reader::loadTupleEmpty() {
	return loadTupleN(0);
}

python::pybase* reader::loadTupleOne() {
	return loadTupleN(1);
}

python::pybase* reader::loadTupleTwo() {
	return loadTupleN(2);
}

python::pybase* reader::loadTuple() {
	return loadTupleN(loadLength());
}

python::pybase* reader::loadTupleN(size_t size) {

	python::pytuple *container = new python::pytuple();
	size_t current = size;
	python::pybase* child = NULL;

	while (current > 0) {
		try {
			child = loadPy();
		} catch (std::exception& exception) {
			std::stringstream stream;
			stream << "Loading TUPLE - size: " << size << " current ";
			stream << (size - current) << std::endl << exception.what();
			container->decRef();
			throw loadErrorException(stream.str());
		}
		container->push_back(child);
		--current;
	}

	return (container);
}

python::pybase* reader::loadListEmpty() {
	return loadListN(0);
}

python::pybase* reader::loadListOne() {
	return loadListN(1);
}

python::pybase* reader::loadList() {
	return loadListN(loadLength());
}

python::pybase* reader::loadListN(size_t size) {

	python::pylist *container = new python::pylist();
	size_t current = size;
	python::pybase* child = NULL;

	while (current > 0) {
		try {
			child = loadPy();
		} catch (std::exception& exception) {
			std::stringstream stream;
			stream << "Loading LIST - size: " << size << " current ";
			stream << (size - current) << std::endl << exception.what();
			container->decRef();
			throw loadErrorException(stream.str());
		}
		container->push_back(child);
		--current;
	}

	return (container);
}

python::pybase* reader::loadDict() {

	size_t size = loadLength();
	size_t current = size;
	python::pybase* key = NULL;
	python::pybase* value = NULL;
	python::pydict *container = new python::pydict();

	while (current > 0) {

		try {
			value = loadPy();
			key = loadPy();
		} catch (std::exception& exception) {
			std::stringstream stream;
			stream << "Loading DICT ";
			if (value) {
				stream << "key";
				// handle case where value is a reference to a stired object
				if (!isStored(value)) {
					value->decRef();
				}
			} else {
				stream << "value";
			}
			stream << " - size: " << size << " current " << (size - current);
			stream << std::endl << exception.what();
			container->decRef();
			throw loadErrorException(stream.str());
		}

		container->push_back(key, value);

		--current;

		key = NULL;
		value = NULL;
	}

	return (container);
}

python::pybase* reader::loadInstance() {

	python::pybase* header = NULL;
	python::pybase* content = NULL;

	python::pyobject* object = new python::pyobject();
	m_objects->push(object);

	try {
		header = loadPy();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading OBJECT header " << std::endl << exception.what();
		object->decRef();
		throw loadErrorException(stream.str());
	}

	object->header(header);

	try {
		content = loadPy();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading OBJECT content " << std::endl << exception.what();
		object->decRef();
		throw loadErrorException(stream.str());
	}

	object->content(content);

	m_objects->pop();

	return (object);
}

python::pybase* reader::loadNewClassObject(bool reduce) {

	python::pybase* header = NULL;
	python::pybase* key = NULL;
	python::pybase* value = NULL;

	python::pyobjectex* object = new python::pyobjectex(reduce);
	python::pyobjectex* replaced = NULL;
	m_objects->push(object);

	try {
		header = loadPy();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading OBJECTEX header " << std::endl << exception.what();
		object->decRef();
		throw loadErrorException(stream.str());
	}

	replaced = replace(header, object, reduce);

	if (replaced != object) {
		m_objects->pop();
		m_objects->push(replaced);
		replace(object, replaced);
		object->decRef();
		object = replaced;
	}

	try {
		object->header(header);
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading OBJECTEX header " << std::endl << exception.what();
		if (!isStored(header)) {
			header->decRef();
		}
		object->decRef();
		throw loadErrorException(stream.str());
	}

	while (TYPE_MARKER != m_iterator.peek<uint8_t>()) {
		try {
			value = loadPy();
		} catch (std::exception& exception) {
			std::stringstream stream;
			stream << "Loading OBJECTEX LIST " << object->list()->size();
			stream << std::endl << exception.what();
			object->decRef();
			throw loadNullException(stream.str());
		}
		object->push_back_list(value);
	}
	m_iterator.read<uint8_t>();

	while (TYPE_MARKER != m_iterator.peek<uint8_t>()) {
		try {
			value = loadPy();
			key = loadPy();
		} catch (std::exception& exception) {
			std::stringstream stream;
			stream << "Loading OBJECTEX DICT ";
			if (value) {
				stream << "key";
				// handle case where value is a reference to a stired object
				if(!isStored(value)) {
					value->decRef();
				}
			} else {
				stream << "value";
			}
			stream << " - size: " << object->dict()->size();
			stream << std::endl << exception.what();
			object->decRef();
			throw loadErrorException(stream.str());
		}

		object->push_back_dict(key, value);

		key = NULL;
		value = NULL;
	}
	m_iterator.read<uint8_t>();

	m_objects->pop();

	return (object);
}

python::pybase* reader::loadObjectEX() {
	return loadNewClassObject(false);
}

python::pybase* reader::loadReduce() {
	return loadNewClassObject(true);
}

python::pybase* reader::loadReference() {
	size_t pos = loadLength();

	python::pybase* ref = stored(pos);

	if (ref == NULL) {
		std::stringstream stream;
		stream << "Loading reference " << pos;
		throw loadNullException(stream.str());
	} else {
		return (ref);
	}
}

python::pybase* reader::loadSubStream() {

	size_t size = loadLength();

	char* buffer = m_iterator.read<char>(size);

	python::pybase* element = NULL;

	istream substream(buffer, size);

	delete[] buffer;

	reader subreader(substream);

	try {
		element = subreader.read();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading SUBSTREAM" << std::endl << exception.what();
		throw loadNullException(stream.str());
	}

	return (element);
}

size_t reader::loadLength() {

	size_t size = m_iterator.read<uint8_t>();

	if (0xFF == size) {
		size = m_iterator.read<uint32_t>();
	}

	return (size);
}

python::pybase* reader::loadPacked() {

	python::pybase* header = NULL;
	python::pybase* buffer = NULL;
	python::pydbrow* row = NULL;
	python::pydbrowdescriptor* descriptor = NULL;

	try {
		header = loadPy();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading PACKED header ";
		stream << std::endl << exception.what();
		throw loadNullException(stream.str());
	}

	if (!header->isDBRowDescriptor()) {
		header = findDBRowDescriptor(header->asObjectEx());
	}

	if (!header->isDBRowDescriptor()) {
		std::stringstream stream;
		stream << "Loading PACKED header - not DBRowDescriptor.";
		stream << std::endl;
		if (!isStored(header)) {
			header->decRef();
		}
		throw loadNullException(stream.str());
	}

	descriptor = header->asDBRowDescriptor();

	try {
		buffer = loadBuffer();
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading PACKED buffer ";
		stream << std::endl << exception.what();
		if (!isStored(descriptor)) {
			descriptor->decRef();
		}
		throw loadNullException(stream.str());
	}

	if (!buffer->isBuffer()) {
		std::stringstream stream;
		stream << "Loading PACKED buffer - not a pybuffer object";
		if (!isStored(descriptor)) {
			descriptor->decRef();
		}
		buffer->decRef();
		throw loadNullException(stream.str());
	}

	size_t size = descriptor->size();

    unsigned char* obuffer = new unsigned char[size];
    memset(obuffer, 0, size);

	zerouncompress(
			reinterpret_cast<const unsigned char*>(buffer->asBuffer()->value()),
			buffer->asBuffer()->size(), obuffer);

	buffer->decRef();

	try {
		row = loadDBRow(obuffer, size, descriptor);
	} catch (std::exception& exception) {
		std::stringstream stream;
		stream << "Loading DBROW.";
		stream << std::endl << exception.what();
		delete[] obuffer;
		if (!isStored(descriptor)) {
			descriptor->decRef();
		}
		throw loadNullException(stream.str());
	}

	delete[] obuffer;

	return (row);
}

python::pybase* reader::findDBRowDescriptor(python::pyobjectex* object) const {

	if (!object) {
		std::stringstream stream;
		stream << "Finding DBRowDescriptor header.";
		stream << "Object is NULL.";
		throw python::loadPyException(stream.str());
	}

	if (object->isDBRowDescriptor()) {
		return object;
	}

	const python::pybase* header = object->header();

	if (!header) {
		std::stringstream stream;
		stream << "Finding DBRowDescriptor header.";
		stream << "Header is NULL.";
		throw python::loadPyException(stream.str());
	}

	if (!header->isTuple()) {
		std::stringstream stream;
		stream << "Finding DBRowDescriptor header.";
		stream << "Header not a TUPLE.";
		throw python::loadPyException(stream.str());
	}

	if (header->asTuple()->size() == 0) {
		std::stringstream stream;
		stream << "Finding DBRowDescriptor header.";
		stream << "Header TUPLE size == 0.";
		throw python::loadPyException(stream.str());
	}

	if (!header->asTuple()->at(0)->isDBRowDescriptor()) {
		std::stringstream stream;
		stream << "Finding DBRowDescriptor header.";
		stream << "Header not a TUPLE::DBROWDESCRIPTOR.";
		throw python::loadPyException(stream.str());
	}

	return header->asTuple()->at(0);
}

void reader::zerouncompress(const unsigned char* buffer, int size,
		unsigned char* ubuffer) const {

	if (size == 0)
		return;

	const unsigned char *end = buffer + size;
	unsigned char pos = 0;
	const char zero = 0;

	while (buffer < end) {

		const zero_compressed opcap =
				*(reinterpret_cast<const zero_compressed*>(buffer++));
		if (opcap.azero) {
			unsigned char count = opcap.alen + 1;
			for (; count > 0; count--) {
				memcpy(ubuffer + pos, &zero, 1);
				pos++;
			}
		} else {
			unsigned int count = 8 - opcap.alen;
			for (; count > 0 && buffer < end; count--) {
				::memcpy(ubuffer + pos, (buffer++), 1);
				pos++;
			}
		}
		if (opcap.bzero) {
			unsigned char count = opcap.blen + 1;
			for (; count > 0; count--) {
				memcpy(ubuffer + pos, &zero, 1);
				pos++;
			}
		} else {
			unsigned int count = 8 - opcap.blen;
			for (; count > 0 && buffer < end; count--) {
				::memcpy(ubuffer + pos, (buffer++), 1);
				pos++;
			}
		}
	}
}

void reader::cleanValues(std::map<const python::pybase*, python::pybase*>* values) {

	if (!values) {
		return;
	}

	std::map<const python::pybase*, python::pybase*>::iterator iterator = values->begin();
	std::map<const python::pybase*, python::pybase*>::iterator end = values->end();

	for (; iterator != end; ++iterator) {
		(*iterator).second->decRef();
	}
}

python::pydbrow* reader::loadDBRow(const unsigned char* ibuffer,
		const size_t size, python::pydbrowdescriptor* descriptor) {

	python::pydbrow* row = new python::pydbrow();

	std::multimap<int8_t, uint32_t, std::greater<uint8_t> > map =
			descriptor->sizeSortedColumns();

	std::multimap<int8_t, uint32_t, std::greater<uint8_t> >::iterator iterator =
			map.begin();
	std::multimap<int8_t, uint32_t, std::greater<uint8_t> >::iterator end =
			map.end();

	istream streamU((const char*) ibuffer, size);
	streamiterator siterator = streamU.begin();

	uint32_t boolcount = 0;
	uint8_t boolstore = 0;

	std::map<const python::pybase*, python::pybase*>* values
		= new std::map<const python::pybase*, python::pybase*>();

	const python::pytuple* tuple = NULL;
	size_t position = 0;

	try {
		for (; iterator != end; ++iterator) {

			position = iterator->second;

			tuple = descriptor->get(position)->asTuple();

			switch (tuple->at(1)->asInt()->value()) {

			case python::DBTYPE_INT8:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyint((int) siterator.read<int8_t>())));
				break;
			case python::DBTYPE_UINT8:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyuint((unsigned int) siterator.read<uint8_t>())));
				break;
			case python::DBTYPE_INT16:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyint((int) siterator.read<int16_t>())));
				break;
			case python::DBTYPE_UINT16:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyuint((unsigned int) siterator.read<uint16_t>())));
				break;
			case python::DBTYPE_INT32:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyint(siterator.read<int32_t>())));
				break;
			case python::DBTYPE_UINT32:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyuint(siterator.read<uint32_t>())));
				break;
			case python::DBTYPE_FLOAT:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyfloat(siterator.read<float>())));
				break;
			case python::DBTYPE_DOUBLE:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pydouble(siterator.read<double>())));
				break;
			case python::DBTYPE_CURRENCY:
			case python::DBTYPE_INT64:
			case python::DBTYPE_WINFILETIME:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pylong(siterator.read<int64_t>())));
				break;
			case python::DBTYPE_UINT64:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pyulong(siterator.read<uint64_t>())));
				break;
			case python::DBTYPE_BOOL:
				if (boolcount == 0) {
					boolstore = siterator.read<uint8_t>();
				}
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						new python::pybool(
								(boolstore >> boolcount++) & 0x01 ? true : false)));
				if (boolcount == 8) {
					boolcount = 0;
				}
				break;
			case python::DBTYPE_STRING:
			case python::DBTYPE_WSTRING:
				values->insert(std::pair<python::pybase*, python::pybase*>(
						(python::pybase*)tuple,
						loadPy()));
				break;
			default:
				std::stringstream stream;
				stream << "Unknow DBType: ";
				stream << tuple->at(1)->asInt()->value();
				throw loadErrorException(stream.str());
			}
		}

	} catch (std::exception& exception) {
		cleanValues(values);
		delete(values);
		row->decRef();
		throw exception;
	}

	tuple = descriptor->getColumns();

	python::pytuple::const_iterator tupleIterator = tuple->begin();
	python::pytuple::const_iterator tupleEnd = tuple->end();

	for (; tupleIterator != tupleEnd; ++tupleIterator) {

		if (!values->at((*tupleIterator))) {
			std::stringstream stream;
			stream << "DB Coulumn not found: ";
			cleanValues(values);
			delete(values);
			row->decRef();
			throw loadErrorException(stream.str());
		}

		row->push_back_dict((*tupleIterator)->asTuple()->at(0),
				(python::pybase*)(values->at((*tupleIterator))));
	}

	row->header(descriptor);

	delete values;

	return (row);
}

} /* namespace marshal */

} /* namespace evetools */
