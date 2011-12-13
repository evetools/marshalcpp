//==========================================================================
// Name        : pydict.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYDICT_H_
#define EVETOOLS_PYTHON_PYDICT_H_

#include "pycontainer.h"

namespace evetools {

namespace python {

class pydict: public pybase {

public:

	typedef std::map<pybase*, pybase*> storage_type;
	typedef storage_type::iterator iterator;
	typedef storage_type::const_iterator const_iterator;

	pydict();
	virtual ~pydict();

	void push_back(pybase* pybaseKey, pybase* pybaseValue);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	size_t size() const;

	const pybase* at(const pybase& key) const;
	const pybase* at(const std::string&) const;

	void visit(pyvisitor& visitor) const;

private:
	pydict(const pydict&);

	std::map<pybase*, pybase*> m_map;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYDICT_H_ */
