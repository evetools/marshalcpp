//==========================================================================
// Name        : pyint.h
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYINT_H_
#define EVETOOLS_PYTHON_PYINT_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyint: public pybase {

public:

	pyint(const int32_t value);
	virtual ~pyint();

	int compare(const pybase& rval) const;

	int32_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pyint();
	pyint(const pyint&);

	int32_t m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYINT_H_ */
