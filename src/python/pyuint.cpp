//==========================================================================
// Name        : pyuint.cpp
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

int pyuint::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		if (m_value == rval.asUInt()->value()) {
			return (0);
		} else if (m_value < rval.asUInt()->value()) {
			return (-1);
		}
		return (1);
	}

	return (ret);
}
uint32_t pyuint::value() const {
	return (m_value);
}

void pyuint::visit(pyvisitor& visitor) const {
	visitor.visitUInt(this);
}

} /* namespace evetools */

} /* namespace python */

