//==========================================================================
// Name        : pydbrowdescriptor.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "../marshal/dumpvisitor.h"
#include "pydbrowdescriptor.h"
#include "py.h"

namespace evetools {

namespace python {

pydbrowdescriptor::pydbrowdescriptor() :
		pyobjectex(PYTYPE_DBROWDESCRIPTOR), m_size(0) {
}

pydbrowdescriptor::pydbrowdescriptor(const bool reduce) :
		pyobjectex(PYTYPE_DBROWDESCRIPTOR, reduce), m_size(0) {
}

pydbrowdescriptor::pydbrowdescriptor(const pydbrowdescriptor&) :
		pyobjectex(PYTYPE_DBROWDESCRIPTOR), m_size(0) {
}

pydbrowdescriptor::~pydbrowdescriptor() {

}

const std::multimap<int8_t, uint32_t, std::greater<uint8_t> > pydbrowdescriptor::sizeSortedColumns() const {
	return (m_sortedColumns);
}

size_t pydbrowdescriptor::size() const {
	return (m_size);
}

void pydbrowdescriptor::header(pybase* pyBase) {
	pyobjectex::header(pyBase);
	init();
}

const pybase* pydbrowdescriptor::get(size_t pos) const {
	const pybase* pyHeader = pyobjectex::header();
	const pytuple* tuple = pyHeader->asTuple()->at(1)->asTuple()->at(0)->asTuple();
	return tuple->at(pos);
}

const pytuple* pydbrowdescriptor::getColumns() const {
	const pybase* pyHeader = pyobjectex::header();
	return pyHeader->asTuple()->at(1)->asTuple()->at(0)->asTuple();
}

void pydbrowdescriptor::init() {

	const pybase* pyHeader = pyobjectex::header();
	const pytuple* tuple = NULL;

	if (!pyHeader->isTuple()) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header not a TUPLE.";
		throw loadPyException(stream.str());
	}

	if (pyHeader->asTuple()->size() < 2) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header TUPLE size < 2.";
		throw loadPyException(stream.str());
	}

	if (!pyHeader->asTuple()->at(1)->isTuple()) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header TUPLE::TUPLE not a TUPLE.";
		throw loadPyException(stream.str());
	}

	if (pyHeader->asTuple()->at(1)->asTuple()->size() == 0) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header TUPLE::TUPLE size == 0.";
		throw loadPyException(stream.str());
	}

	if (!pyHeader->asTuple()->at(1)->asTuple()->at(0)->isTuple()) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header TUPLE::TUPLE::TUPLE not a TUPLE.";
		throw loadPyException(stream.str());
	}

	if (pyHeader->asTuple()->at(1)->asTuple()->at(0)->asTuple()->size() == 0) {
		std::stringstream stream;
		stream << "Loading DBRowDescriptor header.";
		stream << "Header TUPLE::TUPLE::TUPLE size == 0.";
		throw loadPyException(stream.str());
	}

	tuple = pyHeader->asTuple()->at(1)->asTuple()->at(0)->asTuple();

	pytuple::const_iterator iterator = tuple->begin();
	pytuple::const_iterator end = tuple->end();

	uint32_t boolcount = 0;
	m_size = 0;
	size_t index = 0;

	for (; iterator != end; ++iterator) {
		switch ((*iterator)->asTuple()->at(1)->asInt()->value()) {
		case DBTYPE_UINT8:
			m_size += sizeof(int8_t);
			m_sortedColumns.insert(std::make_pair(8, index++));
			break;
		case DBTYPE_INT16:
			m_size += sizeof(int16_t);
			m_sortedColumns.insert(std::make_pair(16, index++));
			break;
		case DBTYPE_INT32:
			m_size += sizeof(int32_t);
			m_sortedColumns.insert(std::make_pair(32, index++));
			break;
		case DBTYPE_DOUBLE:
			m_size += sizeof(double);
			m_sortedColumns.insert(std::make_pair(64, index++));
			break;
		case DBTYPE_CURRENCY:
		case DBTYPE_INT64:
		case DBTYPE_WINFILETIME:
			m_size += sizeof(int64_t);
			m_sortedColumns.insert(std::make_pair(64, index++));
			break;
		case DBTYPE_BOOL:
			if (boolcount == 0) {
				m_size += sizeof(char);
			}
			m_sortedColumns.insert(std::make_pair(1, index++));
			++boolcount;
			if (boolcount == 8) {
				boolcount = 0;
			}
			break;
		case DBTYPE_STRING:
		case DBTYPE_WSTRING:
			m_sortedColumns.insert(std::make_pair(0, index++));
			break;
		default:
			std::stringstream stream;
			stream << "Loading DBRowDescriptor datatype ";
			stream << (*iterator)->asTuple()->at(1)->asInt()->value() << ".";
			throw loadPyException(stream.str());
		}
	}

	//TODO need to fix this
	m_size += 16;
}

void pydbrowdescriptor::visit(pyvisitor& visitor) const {
	visitor.visitDBRowDescriptor(this);
}

} /* namespace python */

} /* namespace evetools */

