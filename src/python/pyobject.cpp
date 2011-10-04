//==========================================================================
// Name        : pyobject.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pyobject.h"

namespace python {

pyobject::pyobject() :
		pybase(PYTYPE_OBJECT), m_header(NULL), m_content(NULL) {

}
pyobject::pyobject(const pyobject&) :
		pybase(PYTYPE_OBJECT), m_header(NULL), m_content(NULL) {

}

pyobject::~pyobject() {

	if (m_header) {
		m_header->decRef();
	}

	if (m_content) {
		m_content->decRef();
	}
}

const pybase* pyobject::header() const {
	return (m_header);
}


const pybase* pyobject::content() const {
	return (m_content);
}


void pyobject::header(pybase* pyHeader) {

	if (m_header) {
		m_header->decRef();
	}

	if (pyHeader) {
		pyHeader->incRef();
	}

	m_header = pyHeader;
}

void pyobject::content(pybase* pyContent) {

	if (m_content) {
		m_content->decRef();
	}

	if (pyContent) {
		pyContent->incRef();
	}

	m_content = pyContent;
}


void pyobject::visit(pyvisitor& visitor) const {
	visitor.visitObject(this);
}

} /* namespace python */

