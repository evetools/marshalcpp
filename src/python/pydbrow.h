//==========================================================================
// Name        : pydbrow.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYDBROW_H_
#define EVETOOLS_PYTHON_PYDBROW_H_

#include "pyobjectex.h"

namespace evetools {

namespace python {


class pydbrow: public pyobjectex {

public:

	pydbrow();
	virtual ~pydbrow();

	void visit(pyvisitor& visitor) const;

protected:

private:
	pydbrow(const pydbrow&);
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYDBROW_H_ */
