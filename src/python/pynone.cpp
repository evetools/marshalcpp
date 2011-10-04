//==========================================================================
// Name        : pynone.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pynone.h"

namespace python {

pynone::pynone() :
		pybase(PYTYPE_NONE) {
}

pynone::pynone(const pynone&) :
		pybase(PYTYPE_NONE) {
}

pynone::~pynone() {

}

void pynone::visit(pyvisitor& visitor) const {
	visitor.visitNone(this);
}

} /* namespace python */

