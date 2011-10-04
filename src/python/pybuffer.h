//==========================================================================
// Name        : pybuffer.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYBUFFER_H_
#define PYTHON_PYBUFFER_H_

#include "pybase.h"

namespace python {

class pybuffer: public pybase {

public:

	pybuffer(const char* buffer, const size_t size);
	virtual ~pybuffer();

	const char* value() const;
	size_t size() const;

	const std::string str() const;

	void visit(pyvisitor& visitor) const;

protected:

	pybuffer(const pytypes& type, const char* buffer, const size_t size);

private:

	pybuffer();
	pybuffer(const pybuffer&);

	char* m_buffer;
	size_t m_size;
	bool m_unicode;
};

} /* python */

#endif /* PYTHON_PYBUFFER_H_ */
