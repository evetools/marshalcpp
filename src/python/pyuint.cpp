//==========================================================================
// Name        : pyuint.cpp
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

pyuint::pyuint() :
		pybase(PYTYPE_UINT), m_value(0) {
}

pyuint::pyuint(const pyuint&) :
		pybase(PYTYPE_UINT), m_value(0) {
}

pyuint::pyuint(const uint32_t intValue) :
		pybase(PYTYPE_UINT), m_value(intValue) {

}

pyuint::~pyuint() {
}

uint32_t pyuint::value() const {
	return (m_value);
}

void pyuint::visit(pyvisitor& visitor) const {
	visitor.visitUInt(this);
}

} /* namespace evetools */

} /* namespace python */

