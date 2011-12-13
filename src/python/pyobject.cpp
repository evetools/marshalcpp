//==========================================================================
// Name        : pyobject.cpp
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

int pyobject::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){

		if (m_header) {
			ret = m_header->compare(*(rval.asObject()->header()));
		}

		if (ret == 0) {
			if (m_content) {
				ret = m_content->compare(*(rval.asObject()->header()));
			}
		}
	}

	return (ret);
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

} /* namespace evetools */

