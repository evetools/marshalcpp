//==========================================================================
// Name        : pylong.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYLONG_H_
#define EVETOOLS_PYTHON_PYLONG_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pylong: public pybase {

public:

	pylong(const int64_t value);
	virtual ~pylong();

	int compare(const pybase& rval) const;

	int64_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pylong();
	pylong(const pylong&);

	int64_t m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYLONG_H_ */
