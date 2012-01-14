//==========================================================================
// Name        : pynone.cpp
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

pynone::pynone() :
		pybase(PYTYPE_NONE) {
}

pynone::pynone(const pynone&) :
		pybase(PYTYPE_NONE) {
}

pynone::~pynone() {

}

int pynone::compare(const pybase& rval) const {
	return (pybase::compare(rval));
}

void pynone::visit(pyvisitor& visitor) const {
	visitor.visitNone(this);
}

} /* namespace python */

} /* namespace evetools */

