//==========================================================================
// Name        : pydbrow.cpp
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

pydbrow::pydbrow() :
		pyobjectex(PYTYPE_DBROW, false) {
}

pydbrow::pydbrow(const pydbrow&) :
		pyobjectex(PYTYPE_DBROW, false) {
}

pydbrow::~pydbrow() {

}

void pydbrow::visit(pyvisitor& visitor) const {
	visitor.visitDBRow(this);
}

} /* namespace python */

} /* namespace evetools */

