//==========================================================================
// Name        : pylong.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pylong.h"

namespace evetools {

namespace python {

pylong::pylong() :
		pybase(PYTYPE_LONG), m_value(0) {

}

pylong::pylong(const pylong&) :
		pybase(PYTYPE_LONG), m_value(0) {

}

pylong::pylong(const uint64_t longValue) :
		pybase(PYTYPE_LONG), m_value(longValue) {

}

pylong::~pylong() {

}

uint64_t pylong::value() const {
	return (m_value);
}

void pylong::visit(pyvisitor& visitor) const {
	visitor.visitLong(this);
}

} /* namespace evetools */

} /* namespace python */

