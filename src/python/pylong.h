//==========================================================================
// Name        : pylong.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYLONG_H_
#define PYTHON_PYLONG_H_

#include "pybase.h"

namespace python {

class pylong: public pybase {

public:

	pylong(const uint64_t value);
	virtual ~pylong();

	uint64_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pylong();
	pylong(const pylong&);

	uint64_t m_value;
};

} /* python */

#endif /* PYTHON_PYLONG_H_ */
