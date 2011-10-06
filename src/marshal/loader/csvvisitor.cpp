//==========================================================================
// Name        : csvvisitor.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "csvvisitor.h"
#include "../../python/py.h"

namespace evetools {

namespace marshal {

namespace loader {

csvvisitor::csvvisitor(std::ostream& stream)  : m_stream(stream), m_first(NULL) {
}

csvvisitor::csvvisitor() : m_stream(std::cout), m_first(NULL) {
}

csvvisitor::~csvvisitor() {
}

void csvvisitor::visitBase(const python::pybase*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitNone(const python::pynone*) {
	m_stream << "NULL" << std::endl;
}

void csvvisitor::visitBool(const python::pybool* object) {
	if (object->value()) {
		m_stream << "true";
	} else {
		m_stream << "false";
	}
}

void csvvisitor::visitInt(const python::pyint* object) {
	m_stream << object->value();
}

void csvvisitor::visitLong(const python::pylong* object) {
	m_stream << object->value();
}

void csvvisitor::visitDouble(const python::pydouble* object) {
	m_stream << object->value();
}

void csvvisitor::visitBuffer(const python::pybuffer* object) {
	m_stream << object->str();
}

void csvvisitor::visitGlobal(const python::pyglobal* object) {
	m_stream << object->str();
}

void csvvisitor::visitTuple(const python::pytuple*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitList(const python::pylist*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitDict(const python::pydict* object) {

	python::pydict::const_iterator iterator = object->begin();
	python::pydict::const_iterator end = object->end();

	if (!m_first) {

		for (; iterator != end; ++iterator) {

			(*iterator)->visit(*this);

			if ((iterator + 2) != end) {
				m_stream << ";";
			}

			++iterator;
		}
		m_first = object;
	}

	m_stream << std::endl;

	iterator = object->begin();

	for (; iterator != end; ++iterator) {

		++iterator;

		(*iterator)->visit(*this);

		if ((iterator + 1) != end) {
			m_stream << ";";
		}
	}
}

void csvvisitor::visitObject(const python::pyobject*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitObjectEx(const python::pyobjectex*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitDBRowList(const python::pydbrowlist*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitDBCRowSet(const python::pydbcrowset*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitDBRowDescriptor(const python::pydbrowdescriptor*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitDBRow(const python::pydbrow*) {
	throw std::runtime_error("CSV Visitor.");
}

void csvvisitor::visitObjectExLike(const python::pyobjectex*,
		const std::string&) {
	throw std::runtime_error("CSV Visitor.");
}

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

