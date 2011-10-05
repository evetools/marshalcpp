//==========================================================================
// Name        : pydbrow.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYDBROW_H_
#define PYTHON_PYDBROW_H_

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

} /* python */

} /* namespace evetools */

#endif /* PYTHON_PYDBROW_H_ */
