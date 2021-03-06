//==========================================================================
// Name        : pydouble.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYDOUBLE_H_
#define EVETOOLS_PYTHON_PYDOUBLE_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pydouble: public pybase {

public:

	pydouble(const double value);
	virtual ~pydouble();

	int compare(const pybase& rval) const;

	double value() const ;

	void visit(pyvisitor& visitor) const;

private:

	pydouble();
	pydouble(const pydouble&);

	double m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYDOUBLE_H_ */
