//==========================================================================
// Name        : pydbcrowset.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYDBCROWSET_H_
#define EVETOOLS_PYTHON_PYDBCROWSET_H_

#include "pyobjectex.h"

namespace evetools {

namespace python {


class pydbcrowset: public pyobjectex {

public:

	pydbcrowset(const bool reduce);
	virtual ~pydbcrowset();

	void visit(pyvisitor& visitor) const;

protected:

private:
	pydbcrowset();
	pydbcrowset(const pydbcrowset&);
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYDBCROWSET_H_ */
