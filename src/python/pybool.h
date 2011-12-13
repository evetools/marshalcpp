//==========================================================================
// Name        : pybool.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYBOOL_H_
#define EVETOOLS_PYTHON_PYBOOL_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pybool : public pybase {

public:

	pybool(const bool value);
	virtual ~pybool();

	int compare(const pybase& rval) const;

	bool value() const;

	void visit(pyvisitor& visitor) const;

public:

	pybool();
	pybool(const pybool&);

	bool m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYBOOL_H_ */
