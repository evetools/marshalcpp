//==========================================================================
// Name        : pydbrowdescriptor.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYDBROWDESCRIPTOR_H_
#define PYTHON_PYDBROWDESCRIPTOR_H_

#include "pyobjectex.h"

namespace python {

class pydbrowdescriptor: public pyobjectex {

public:

	pydbrowdescriptor(const bool reduce);
	virtual ~pydbrowdescriptor();

	void header(pybase* header);

	const std::multimap<int8_t, uint32_t, std::greater<uint8_t> >
	sizeSortedColumns() const;

	size_t size() const;

	const pybase* get(size_t pos) const;

	const pytuple* getColumns() const;

	void visit(pyvisitor& visitor) const;

protected:

	void init();

private:

	pydbrowdescriptor();
	pydbrowdescriptor(const pydbrowdescriptor&);

	std::multimap<int8_t, uint32_t, std::greater<uint8_t> > m_sortedColumns;

	size_t m_size;
};

} /* python */

#endif /* PYTHON_PYDBROWDESCRIPTOR_H_ */
