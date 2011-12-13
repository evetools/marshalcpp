//==========================================================================
// Name        : pydbcrowset.cpp
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

pydbcrowset::pydbcrowset() :
		pyobjectex(PYTYPE_DBCROWSET) {
}

pydbcrowset::pydbcrowset(const bool reduce) :
		pyobjectex(PYTYPE_DBCROWSET, reduce) {
}

pydbcrowset::pydbcrowset(const pydbcrowset&) :
		pyobjectex(PYTYPE_DBCROWSET) {
}

pydbcrowset::~pydbcrowset() {

}

void pydbcrowset::visit(pyvisitor& visitor) const {
	visitor.visitDBCRowSet(this);
}

} /* namespace python */

} /* namespace evetools */

