//==========================================================================
// Name        : pytuple.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pytuple.h"

namespace evetools {

namespace python {

pytuple::pytuple() :
		pycontainer(PYTYPE_TUPLE) {
}

pytuple::pytuple(const pytuple&) :
		pycontainer(PYTYPE_TUPLE) {
}

pytuple::~pytuple() {
}

void pytuple::push_back(pybase* object) {
	if (!object) {
		std::stringstream stream;
		stream << "Invalid NULL key argument passed to pytuple::push_back.";
		throw pyNullException(stream.str());
	}
	pycontainer::push_back(object);
}

void pytuple::visit(pyvisitor& visitor) const {
	visitor.visitTuple(this);
}

} /* namespace python */

} /* namespace evetools */

