//==========================================================================
// Name        : pyulong.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYULONG_H_
#define EVETOOLS_PYTHON_PYULONG_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyulong: public pybase {

public:

	pyulong(const uint64_t value);
	virtual ~pyulong();

	int compare(const pybase& rval) const;

	uint64_t value() const;

	void visit(pyvisitor& visitor) const;

private:

	pyulong();
	pyulong(const pyulong&);

	uint64_t m_value;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYULONG_H_ */
