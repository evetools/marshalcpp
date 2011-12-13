
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

#ifndef EVETOOLS_PYTHON_PYLIST_H_
#define EVETOOLS_PYTHON_PYLIST_H_

#include "pycontainer.h"

namespace evetools {

namespace python {

class pylist: public pycontainer {

public:

	pylist();
	virtual ~pylist();

	int compare(const pybase& rval) const;

	void push_back(pybase* pybase);

	void visit(pyvisitor& visitor) const;

private:

	pylist(const pylist&);
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYLIST_H_ */
