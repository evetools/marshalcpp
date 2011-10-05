//==========================================================================
// Name        : pytuple.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYTUPLE_H_
#define PYTHON_PYTUPLE_H_

#include "pycontainer.h"

namespace evetools {

namespace python {

class pytuple: public pycontainer {

public:

	pytuple();
	virtual ~pytuple();

	void push_back(pybase* pybase);

	void visit(pyvisitor& visitor) const;

private:

	pytuple(const pytuple&);
};

} /* python */

} /* namespace evetools */

#endif /* PYTHON_PYTUPLE_H_ */
