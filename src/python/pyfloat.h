//==========================================================================
// Name        : pyfloat.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYFLOAT_H_
#define EVETOOLS_PYTHON_PYFLOAT_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyfloat: public pybase {

public:

	pyfloat(const float value);
	virtual ~pyfloat();

	float value() const ;

	void visit(pyvisitor& visitor) const;

private:

	pyfloat();
	pyfloat(const pyfloat&);

	float m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYFLOAT_H_ */
