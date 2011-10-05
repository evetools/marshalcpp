//==========================================================================
// Name        : pydbcrowset.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pydbcrowset.h"

namespace evetools {

namespace python {

pydbcrowset::pydbcrowset() :
		pyobjectex(PYTYPE_DBROWLIST) {
}

pydbcrowset::pydbcrowset(const bool reduce) :
		pyobjectex(PYTYPE_DBROWLIST, reduce) {
}

pydbcrowset::pydbcrowset(const pydbcrowset&) :
		pyobjectex(PYTYPE_DBROWLIST) {
}

pydbcrowset::~pydbcrowset() {

}

void pydbcrowset::visit(pyvisitor& visitor) const {
	visitor.visitDBCRowSet(this);
}

} /* namespace python */

} /* namespace evetools */

