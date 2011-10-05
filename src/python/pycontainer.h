//==========================================================================
// Name        : pycontainer.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYCONTAINER_H_
#define EVETOOLS_PYTHON_PYCONTAINER_H_

#include "pybase.h"

namespace evetools {

namespace python {

class pycontainer: public pybase {

public:

	typedef std::vector<pybase*> storage_type;
	typedef storage_type::iterator iterator;
	typedef storage_type::const_iterator const_iterator;

	virtual ~pycontainer();

	virtual void push_back(pybase* pybase);

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	size_t size() const;

	pybase* at(size_t pos) const;


protected:

	pycontainer(const pytypes& type);

	storage_type m_container;

private:

	pycontainer();
	pycontainer(const pycontainer&);
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYCONTAINER_H_ */
