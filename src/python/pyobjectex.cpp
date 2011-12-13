//==========================================================================
// Name        : pyobjectex.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "py.h"

namespace evetools {

namespace python {

pyobjectex::pyobjectex() :
		pybase(PYTYPE_OBJECTEX), m_header(NULL), m_reduce(false) {
}

pyobjectex::pyobjectex(const bool reduce) :
		pybase(PYTYPE_OBJECTEX), m_header(NULL), m_reduce(reduce) {
}


pyobjectex::pyobjectex(const pytypes& pyType) :
		pybase(pyType), m_header(NULL), m_reduce(false) {
}

pyobjectex::pyobjectex(const pytypes& pyType, bool reduce) :
		pybase(pyType), m_header(NULL), m_reduce(reduce) {
}

pyobjectex::pyobjectex(const pyobjectex&) :
		pybase(PYTYPE_OBJECTEX), m_header(NULL), m_reduce(false) {
}

pyobjectex::~pyobjectex() {

	if (m_header) {
		m_header->decRef();
	}
}

int pyobjectex::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){

		if (m_header) {
			ret = m_header->compare(*((const pyobjectex*)&rval)->header());
		}

		if (ret == 0) {
			ret = m_dict.compare(*((const pyobjectex*)&rval)->dict());
		}

		if (ret == 0) {
			ret = m_list.compare(*((const pyobjectex*)&rval)->list());
		}
	}

	return (ret);
}

bool pyobjectex::isReduce() const {
	return (m_reduce);
}

const pybase* pyobjectex::header() const {
	return (m_header);
}

const pylist* pyobjectex::list() const {
	return (&m_list);
}

const pydict* pyobjectex::dict() const {
	return (&m_dict);
}

void pyobjectex::header(pybase* pyHeader) {

	if (m_header) {
		m_header->decRef();
	}

	if (pyHeader) {
		pyHeader->incRef();
	}

	m_header = pyHeader;
}

void pyobjectex::push_back_list(pybase* pyBase) {
	m_list.push_back(pyBase);
}

void pyobjectex::push_back_dict(pybase* pybaseKey, pybase* pybaseValue) {
	m_dict.push_back(pybaseKey, pybaseValue);
}

void pyobjectex::visit(pyvisitor& visitor) const {
	visitor.visitObjectEx(this);
}

} /* namespace python */

} /* namespace evetools */

