//==========================================================================
// Name        : pyglobal.h
// Version     : 0global.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYGLOBAL_H_
#define PYTHON_PYGLOBAL_H_

#include "pybuffer.h"

namespace evetools {

namespace python {

class pyglobal: public pybuffer {

public:

	pyglobal(const char* buffer, size_t size);
	virtual ~pyglobal();

	void visit(pyvisitor& visitor) const;

private:

	pyglobal();
	pyglobal(const pyglobal&);
};

} /* python */

} /* namespace evetools */

#endif /* PYTHON_PYGLOBAL_H_ */
