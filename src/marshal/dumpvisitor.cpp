//==========================================================================
// Name        : dumpvisitor.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "dumpvisitor.h"
#include "../python/py.h"

namespace evetools {

namespace marshal {

dumpvisitor::dumpvisitor(std::ostream& stream)  : m_stream(stream) {
}

dumpvisitor::dumpvisitor() : m_stream(std::cout) {
}

dumpvisitor::~dumpvisitor() {
}

void dumpvisitor::visitBase(const python::pybase* object) {
	std::ios::fmtflags flags = std::cout.flags();

	m_stream << indent() << "0x" << std::hex << std::setw(2);
	m_stream << std::setfill('0') << (int) object->type();

	m_stream.setf(flags);

	m_stream << std::endl;
}

void dumpvisitor::visitNone(const python::pynone*) {
	m_stream << indent() << "[NONE]" << std::endl;
}

void dumpvisitor::visitBool(const python::pybool* object) {
	m_stream << indent() << "[BOOLEAN : ";
	if (object->value()) {
		m_stream << "true";
	} else {
		m_stream << "false";
	}
	m_stream << "]" << std::endl;
}

void dumpvisitor::visitInt(const python::pyint* object) {
	m_stream << indent() << "[INT : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitUInt(const python::pyuint* object) {
	m_stream << indent() << "[UINT : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitLong(const python::pylong* object) {
	m_stream << indent() << "[LONG : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitULong(const python::pyulong* object) {
	m_stream << indent() << "[ULONG : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitFloat(const python::pyfloat* object) {
	m_stream << indent() << "[FLOAT : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitDouble(const python::pydouble* object) {
	m_stream << indent() << "[DOUBLE : " << object->value() << "]" << std::endl;
}

void dumpvisitor::visitBuffer(const python::pybuffer* object) {
	m_stream << indent() << "[BUFFER : " << object->str() << "]" << std::endl;
}

void dumpvisitor::visitGlobal(const python::pyglobal* object) {
	m_stream << indent() << "[GLOBAL : " << object->str() << "]" << std::endl;
}

void dumpvisitor::visitTuple(const python::pytuple* object) {

	m_stream << indent() << "[TUPLE " << object->size() << "]" << std::endl;

	push();

	python::pytuple::const_iterator iterator = object->begin();
	python::pytuple::const_iterator end = object->end();

	for (; iterator != end; ++iterator) {
		(*iterator)->visit(*this);
	}

	pop();
}

void dumpvisitor::visitList(const python::pylist* object) {

	m_stream << indent() << "[LIST " << object->size() << "]" << std::endl;

	push();

	python::pytuple::const_iterator iterator = object->begin();
	python::pytuple::const_iterator end = object->end();

	for (; iterator != end; ++iterator) {
		(*iterator)->visit(*this);
	}

	pop();
}

void dumpvisitor::visitDict(const python::pydict* object) {

	m_stream << indent() << "[DICT " << object->size() << "]" << std::endl;

	push();

	python::pydict::const_iterator iterator = object->begin();
	python::pydict::const_iterator end = object->end();

	for (; iterator != end; ++iterator) {
		(*iterator).first->visit(*this);
		push();
		(*iterator).second->visit(*this);
		pop();
	}

	pop();
}

void dumpvisitor::visitObject(const python::pyobject* object) {

	m_stream << indent() << "[OBJECT]" << std::endl;

	push();

	m_stream << indent() << "[OBJECT : HEADER]" << std::endl;
	if (object->header()) {
		push();
		object->header()->visit(*this);
		pop();
	}

	m_stream << indent() << "[OBJECT : CONTENT]" << std::endl;
	if (object->content()) {
		push();
		object->content()->visit(*this);
		pop();
	}

	pop();
}

void dumpvisitor::visitObjectEx(const python::pyobjectex* object) {
	visitObjectExLike(object, "OBJECTEX");
}

void dumpvisitor::visitDBRowList(const python::pydbrowlist* object) {
	visitObjectExLike(object, "DBROWLIST");
}

void dumpvisitor::visitDBCRowSet(const python::pydbcrowset* object) {
	visitObjectExLike(object, "DBCROWSET");
}

void dumpvisitor::visitDBRowDescriptor(const python::pydbrowdescriptor* object) {
	visitObjectExLike(object, "DBROWDESCRIPTOR");
}

void dumpvisitor::visitDBRow(const python::pydbrow* object) {
	visitObjectExLike(object, "DBROW");
}

void dumpvisitor::visitObjectExLike(const python::pyobjectex* object,
		const std::string& name) {
	m_stream << indent() << "[" << name;

	if (object->isReduce()) {
		m_stream << " : reduce]";
	} else {
		m_stream << "]";
	}
	m_stream << std::endl;

	push();

	m_stream << indent() << "[" << name;
	if (object->isReduce()) {
		m_stream << " : reduce";
	}
	m_stream << " : HEADER]" << std::endl;
	if (object->header()) {
		push();
		object->header()->visit(*this);
		pop();
	}

	m_stream << indent() << "[" << name;
	if (object->isReduce()) {
		m_stream << " : reduce";
	}
	m_stream << " : LIST " << object->list()->size() << "]" << std::endl;
	push();
	python::pylist::const_iterator iteratorList = object->list()->begin();
	python::pylist::const_iterator endList = object->list()->end();

	for (; iteratorList != endList; ++iteratorList) {
		(*iteratorList)->visit(*this);
	}
	pop();

	m_stream << indent() << "[" << name;
	if (object->isReduce()) {
		m_stream << " : reduce";
	}
	m_stream << " : DICT " << object->dict()->size() << "]" << std::endl;
	push();
	python::pydict::const_iterator iteratorDict = object->dict()->begin();
	python::pydict::const_iterator endDict = object->dict()->end();

	for (; iteratorDict != endDict; ++iteratorDict) {
		(*iteratorDict).first->visit(*this);
		push();
		(*iteratorDict).second->visit(*this);
		pop();
	}
	pop();

	pop();
}

const std::string dumpvisitor::indent() const {

	std::stringstream stream("");

	for (size_t loop = 0; loop < m_indentStack.size(); loop++) {
		stream << "  ";
	}

	return stream.str();
}

} /* namespace marshal */

} /* namespace evetools */

