//==========================================================================
// Name        : pyfloat.cpp
// Version     : 0.0.1
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

pyfloat::pyfloat() :
		pybase(PYTYPE_FLOAT), m_value(0.0f) {

}

pyfloat::pyfloat(const pyfloat&) :
		pybase(PYTYPE_FLOAT), m_value(0.0f) {

}

pyfloat::pyfloat(const float doubleValue) :
		pybase(PYTYPE_FLOAT), m_value(doubleValue) {
}

pyfloat::~pyfloat() {

}

int pyfloat::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		if (m_value == rval.asFloat()->value()) {
			return (0);
		} else if (m_value < rval.asFloat()->value()) {
			return (-1);
		}
		return (1);
	}

	return (ret);
}
float pyfloat::value() const {
	return (m_value);
}


void pyfloat::visit(pyvisitor& visitor) const {
	visitor.visitFloat(this);
}

} /* namespace python */

} /* namespace evetools */

