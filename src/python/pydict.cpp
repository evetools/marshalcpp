//==========================================================================
// Name        : pydict.cpp
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

pydict::pydict() :
		pycontainer(PYTYPE_DICT) {
}

pydict::pydict(const pydict&) :
		pycontainer(PYTYPE_DICT) {
}

pydict::~pydict() {
}

void pydict::push_back(pybase* pybaseKey, pybase* pybaseValue) {
	if (!pybaseKey) {
		std::stringstream stream;
		stream << "Invalid NULL key argument passed to pydict::push_back.";
		throw pyNullException(stream.str());
	}
	if (!pybaseValue) {
		std::stringstream stream;
		stream << "Invalid NULL value argument passed to pydict::push_back.";
		throw pyNullException(stream.str());
	}
	pycontainer::push_back(pybaseKey);
	pycontainer::push_back(pybaseValue);
}

void pydict::push_back(pybase* object) {
	if (!object) {
		std::stringstream stream;
		stream << "Invalid NULL argument passed to pydict::push_back.";
		throw pyNullException(stream.str());
	}
	pycontainer::push_back(object);
}

void pydict::visit(pyvisitor& visitor) const {
	visitor.visitDict(this);
}

} /* namespace python */

} /* namespace evetools */

