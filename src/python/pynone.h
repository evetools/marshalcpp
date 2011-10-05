//==========================================================================
// Name        : pynone.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYNONE_H_
#define EVETOOLS_PYTHON_PYNONE_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pynone: public pybase {

public:

	pynone();
	virtual ~pynone();

	void visit(pyvisitor& visitor) const;

private:

	pynone(const pynone&);

};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYNONE_H_ */
