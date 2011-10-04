//==========================================================================
// Name        : pydict.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYDICT_H_
#define PYTHON_PYDICT_H_

#include "pycontainer.h"

namespace python {

class pydict: public pycontainer {

public:

	pydict();
	virtual ~pydict();

	void push_back(pybase* pybase);
	void push_back(pybase* pybaseKey, pybase* pybaseValue);

	void visit(pyvisitor& visitor) const;

private:

	pydict(const pydict&);
};

} /* python */

#endif /* PYTHON_PYDICT_H_ */
