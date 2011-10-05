
//==========================================================================
// Name        : pylist.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYLIST_H_
#define PYTHON_PYLIST_H_

#include "pycontainer.h"

namespace python {

class pylist: public pycontainer {

public:

	pylist();
	virtual ~pylist();

	void push_back(pybase* pybase);

	void visit(pyvisitor& visitor) const;

private:

	pylist(const pylist&);
};

} /* python */

#endif /* PYTHON_PYLIST_H_ */