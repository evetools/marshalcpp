//==========================================================================
// Name        : reader.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef MARSHAL_READER_H_
#define MARSHAL_READER_H_

#include <stack>
#include <wchar.h>

#include "streamiterator.h"

#include "../python/py.h"
#include "dumpvisitor.h"

#include "strings.h"
#include "iconv.h"

namespace marshal {

class loadErrorException : public std::runtime_error {

public:

	loadErrorException(const std::string& msg) : std::runtime_error(msg) {}
    virtual ~loadErrorException() throw() {}
};

class loadNullException : public loadErrorException {

public:

	loadNullException(const std::string& msg) : loadErrorException(msg) {}
    virtual ~loadNullException() throw() {}
};

typedef enum streamtypes {
	TYPE_PROTOCOL = 0x7e,
	TYPE_MARKER = 0x2d,
	MASK = 0x3f,
	SHARED = 0x40,
	COMPRESSED = 0x78,
	UNKNOWN = 0x80
} streamtypes;

struct zero_compressed {
	unsigned char alen :3;
	bool azero :1;
	unsigned char blen :3;
	bool bzero :1;
};

class reader {

public:

	reader(const std::string& path);
	reader(const istream& stream);

	virtual ~reader();

	python::pybase* read();

protected:

	python::pybase* loadPy();

	size_t loadLength();
	python::pybase* loadError();

	python::pybase* loadNone();
	python::pybase* loadMarker();
	python::pybase* loadTrue();
	python::pybase* loadFalse();
	python::pybase* loadZero();
	python::pybase* loadOne();
	python::pybase* loadMinusOne();
	python::pybase* loadInt8();
	python::pybase* loadInt16();
	python::pybase* loadInt32();
	python::pybase* loadInt64();
	python::pybase* loadVarInt();
	python::pybase* loadDouble();
	python::pybase* loadDoubleZero();
	python::pybase* loadStringRef();
	python::pybase* loadBufferN(size_t size);
	python::pybase* loadBuffer();
	python::pybase* loadString0();
	python::pybase* loadString1();
	python::pybase* loadString();
	python::pybase* loadStringN(size_t size);
	python::pybase* loadUnicodeN(size_t size);
	python::pybase* loadUnicode();
	python::pybase* loadUnicode0();
	python::pybase* loadUnicode1();
	python::pybase* loadTupleEmpty();
	python::pybase* loadTupleOne();
	python::pybase* loadTupleTwo();
	python::pybase* loadTuple();
	python::pybase* loadTupleN(size_t size);
	python::pybase* loadListEmpty();
	python::pybase* loadListOne();
	python::pybase* loadList();
	python::pybase* loadListN(size_t size);
	python::pybase* loadDict();
	python::pybase* loadInstance();
	python::pybase* loadNewClassObject(bool reduce);
	python::pybase* loadObjectEX();
	python::pybase* loadReduce();
	python::pybase* loadSubStream();
	python::pybase* loadGlobal();
	python::pybase* loadReference();
	python::pybase* loadPacked();

	void store(python::pybase*, size_t pos);
	python::pybase* stored(size_t position);

	python::pyobjectex* replace(python::pybase* header, python::pyobjectex* object,
			bool reduce);
	void replace(python::pybase* objectOld, python::pybase* objectNew);

	python::pybase* findDBRowDescriptor(python::pyobjectex* object) const;

	void zerouncompress(const unsigned char* buffer, int size,
	                unsigned char* ubuffer) const;

	python::pydbrow* loadDBRow(const unsigned char* buffer, const size_t size,
			python::pydbrowdescriptor* descriptor);
private:

	reader();

	istream* m_stream;
	streamiterator m_iterator;
	streamiterator m_shareIterator;
	std::vector<python::pybase*>* m_storage;
	std::stack<python::pybase*>* m_objects;

	uint8_t m_magic;
	uint8_t m_type;

	static python::pybase* (reader::* const m_loadPyMethods[])();
};

} /* namespace marshal */

#endif /* MARSHAL_READER_H_ */
