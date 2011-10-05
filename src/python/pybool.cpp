//==========================================================================
// Name        : pybool.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pybool.h"

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

bool pybool::value() const {
	return (m_value);
}

void pybool::visit(pyvisitor& visitor) const {
	visitor.visitBool(this);
}

} /* namespace python */

} /* namespace evetools */

