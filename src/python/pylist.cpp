//==========================================================================
// Name        : pylist.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pylist.h"

namespace python {

pylist::pylist() :
		pycontainer(PYTYPE_LIST) {
}

pylist::pylist(const pylist&) :
		pycontainer(PYTYPE_LIST) {
}

pylist::~pylist() {
}

void pylist::push_back(pybase* object) {
	if (!object) {
		std::stringstream stream;
		stream << "Invalid NULL key argument passed to pylist::push_back.";
		throw pyNullException(stream.str());
	}
	pycontainer::push_back(object);
}

void pylist::visit(pyvisitor& visitor) const {
	visitor.visitList(this);
}

} /* namespace python */
