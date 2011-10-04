//==========================================================================
// Name        : pyint.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pyint.h"

namespace python {

pyint::pyint() :
		pybase(PYTYPE_INT), m_value(0) {
}

pyint::pyint(const pyint&) :
		pybase(PYTYPE_INT), m_value(0) {
}

pyint::pyint(const uint32_t intValue) :
		pybase(PYTYPE_INT), m_value(intValue) {

}

pyint::~pyint() {
}

uint32_t pyint::value() const {
	return (m_value);
}

void pyint::visit(pyvisitor& visitor) const {
	visitor.visitInt(this);
}

} /* namespace python */

