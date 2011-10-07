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

float pyfloat::value() const {
	return (m_value);
}


void pyfloat::visit(pyvisitor& visitor) const {
	visitor.visitFloat(this);
}

} /* namespace python */

} /* namespace evetools */

