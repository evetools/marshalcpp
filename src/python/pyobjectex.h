//==========================================================================
// Name        : pyobjectex.h
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYOBJECTEX_H_
#define EVETOOLS_PYTHON_PYOBJECTEX_H_

#include "pydict.h"
#include "pylist.h"

namespace evetools {

namespace python {


class pyobjectex: public pybase {

public:

	typedef pylist list_type;

	typedef pydict dict_type;

	pyobjectex(const bool isReduce);
	virtual ~pyobjectex();

	int compare(const pybase& rval) const;

	void push_back_list(pybase* pybase);
	void push_back_dict(pybase* pybaseKey, pybase* pybaseValue);

	bool isReduce() const;
	const pybase* header() const;
	virtual void header(pybase* header);

	const pylist* list() const;
	const pydict* dict() const;

	void visit(pyvisitor& visitor) const;

protected:

	pyobjectex(const python::pytypes& type);
	pyobjectex(const python::pytypes& type, const bool isReduce);

private:

	pyobjectex();
	pyobjectex(const pyobjectex&);

	pybase* m_header;

	pylist m_list;
	pydict m_dict;

	bool m_reduce;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PY_H_ */
