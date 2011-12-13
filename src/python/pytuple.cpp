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

#include "py.h"

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

int pytuple::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		return (compareValues((const pycontainer&)(rval)));
	}

	return (ret);
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

