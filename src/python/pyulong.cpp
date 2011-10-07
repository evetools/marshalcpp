//==========================================================================
// Name        : pyulong.cpp
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

pyulong::pyulong() :
		pybase(PYTYPE_ULONG), m_value(0) {

}

pyulong::pyulong(const pyulong&) :
		pybase(PYTYPE_ULONG), m_value(0) {

}

pyulong::pyulong(const uint64_t longValue) :
		pybase(PYTYPE_ULONG), m_value(longValue) {

}

pyulong::~pyulong() {

}

uint64_t pyulong::value() const {
	return (m_value);
}

void pyulong::visit(pyvisitor& visitor) const {
	visitor.visitULong(this);
}

} /* namespace evetools */

} /* namespace python */

