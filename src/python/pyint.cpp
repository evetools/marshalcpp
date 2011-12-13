//==========================================================================
// Name        : pyint.cpp
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

pyint::pyint() :
		pybase(PYTYPE_INT), m_value(0) {
}

pyint::pyint(const pyint&) :
		pybase(PYTYPE_INT), m_value(0) {
}

pyint::pyint(const int32_t intValue) :
		pybase(PYTYPE_INT), m_value(intValue) {

}

pyint::~pyint() {
}

int pyint::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		if (m_value == rval.asInt()->value()) {
			return (0);
		} else if (m_value < rval.asInt()->value()) {
			return (-1);
		}
		return (1);
	}

	return (ret);
}
int32_t pyint::value() const {
	return (m_value);
}

void pyint::visit(pyvisitor& visitor) const {
	visitor.visitInt(this);
}

} /* namespace evetools */

} /* namespace python */

