//==========================================================================
// Name        : pylist.cpp
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

pylist::pylist() :
		pycontainer(PYTYPE_LIST) {
}

pylist::pylist(const pylist&) :
		pycontainer(PYTYPE_LIST) {
}

pylist::~pylist() {
}

int pylist::compare(const pybase& rval) const {

	int ret = pybase::compare(rval);

	if (ret == 0){
		return (compareValues((const pycontainer&)(rval)));
	}

	return (ret);
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

} /* namespace evetools */

} /* namespace python */
