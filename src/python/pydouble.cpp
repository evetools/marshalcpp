//==========================================================================
// Name        : pydouble.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pydouble.h"

namespace evetools {

namespace python {

pydouble::pydouble() :
		pybase(PYTYPE_DOUBLE), m_value(0.0f) {

}

pydouble::pydouble(const pydouble&) :
		pybase(PYTYPE_DOUBLE), m_value(0.0f) {

}

pydouble::pydouble(const double doubleValue) :
		pybase(PYTYPE_DOUBLE), m_value(doubleValue) {
}

pydouble::~pydouble() {

}

double pydouble::value() const {
	return (m_value);
}


void pydouble::visit(pyvisitor& visitor) const {
	visitor.visitDouble(this);
}

} /* namespace python */

} /* namespace evetools */

