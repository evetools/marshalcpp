//==========================================================================
// Name        : pyint.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYINT_H_
#define PYTHON_PYINT_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyint: public pybase {

public:

	pyint(const uint32_t value);
	virtual ~pyint();

	uint32_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pyint();
	pyint(const pyint&);

	uint32_t m_value;
};

} /* python */

} /* namespace evetools */

#endif /* PYTHON_PYINT_H_ */
