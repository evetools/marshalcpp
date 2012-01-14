//==========================================================================
// Name        : pybool.cpp
// Version     : 0.0.3
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

pybool::pybool() :
		pybase(PYTYPE_BOOL), m_value(false) {
}

pybool::pybool(const pybool&) :
		pybase(PYTYPE_BOOL), m_value(false) {
}

pybool::pybool(const bool boolValue) :
		pybase(PYTYPE_BOOL), m_value(boolValue) {
}

pybool::~pybool() {

}

int pybool::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		if (m_value == rval.asBool()->value()) {
			return (0);
		} else if (m_value < rval.asBool()->value()) {
			return (-1);
		}
		return (1);
	}

	return (ret);
}

bool pybool::value() const {
	return (m_value);
}

void pybool::visit(pyvisitor& visitor) const {
	visitor.visitBool(this);
}

} /* namespace python */

} /* namespace evetools */

