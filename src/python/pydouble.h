//==========================================================================
// Name        : pydouble.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYDOUBLE_H_
#define PYTHON_PYDOUBLE_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pydouble: public pybase {

public:

	pydouble(const double value);
	virtual ~pydouble();

	double value() const ;

	void visit(pyvisitor& visitor) const;

private:

	pydouble();
	pydouble(const pydouble&);

	double m_value;
};

} /* python */

} /* namespace evetools */

#endif /* PYTHON_PYDOUBLE_H_ */
