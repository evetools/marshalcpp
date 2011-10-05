//==========================================================================
// Name        : pyobject.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYOBJECT_H_
#define EVETOOLS_PYTHON_PYOBJECT_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pyobject: public pybase {

public:

	pyobject();
	virtual ~pyobject();

	const pybase* header() const;

	const pybase* content() const;

	void header(pybase* header);

	void content(pybase* content);

	void visit(pyvisitor& visitor) const;

private:

	pyobject(const pyobject&);

	pybase* m_header;
	pybase* m_content;

};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYOBJECT_H_ */
