//==========================================================================
// Name        : pydbrowlist.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYDBROWLIST_H_
#define PYTHON_PYDBROWLIST_H_

#include "pyobjectex.h"

namespace python {


class pydbrowlist: public pyobjectex {

public:

	pydbrowlist(const bool reduce);
	virtual ~pydbrowlist();

	void visit(pyvisitor& visitor) const;

protected:

private:
	pydbrowlist();
	pydbrowlist(const pydbrowlist&);
};

} /* python */

#endif /* PYTHON_PYDBROWLIST_H_ */
