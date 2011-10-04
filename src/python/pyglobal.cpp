//==========================================================================
// Name        : pyglobal.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pyglobal.h"

namespace python {

pyglobal::pyglobal() :
		pybuffer(PYTYPE_GLOBAL, NULL, 0) {

}

pyglobal::pyglobal(const pyglobal&) :
		pybuffer(PYTYPE_GLOBAL, NULL, 0) {

}

pyglobal::pyglobal(const char* buf, size_t bufSize) :
		pybuffer(PYTYPE_GLOBAL, buf, bufSize) {
}

pyglobal::~pyglobal() {

}

void pyglobal::visit(pyvisitor& visitor) const {
	visitor.visitGlobal(this);
}

} /* namespace python */

