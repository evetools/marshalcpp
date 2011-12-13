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

#include "py.h"

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

int pydouble::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		if (m_value == rval.asDouble()->value()) {
			return (0);
		} else if (m_value < rval.asDouble()->value()) {
			return (-1);
		}
		return (1);
	}

	return (ret);
}
double pydouble::value() const {
	return (m_value);
}


void pydouble::visit(pyvisitor& visitor) const {
	visitor.visitDouble(this);
}

} /* namespace python */

} /* namespace evetools */

