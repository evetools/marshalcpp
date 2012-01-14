//==========================================================================
// Name        : pyuint.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYUINT_H_
#define EVETOOLS_PYTHON_PYUINT_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyuint: public pybase {

public:

	pyuint(const uint32_t value);
	virtual ~pyuint();

	int compare(const pybase& rval) const;

	uint32_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pyuint();
	pyuint(const pyuint&);

	uint32_t m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYUINT_H_ */
