//==========================================================================
// Name        : pydbrowlist.cpp
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

pydbrowlist::pydbrowlist() :
		pyobjectex(PYTYPE_DBROWLIST) {
}

pydbrowlist::pydbrowlist(const bool reduce) :
		pyobjectex(PYTYPE_DBROWLIST, reduce) {
}

pydbrowlist::pydbrowlist(const pydbrowlist&) :
		pyobjectex(PYTYPE_DBROWLIST) {
}

pydbrowlist::~pydbrowlist() {

}

void pydbrowlist::visit(pyvisitor& visitor) const {
	visitor.visitDBRowList(this);
}

} /* namespace python */

} /* namespace evetools */

