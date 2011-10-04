//==========================================================================
// Name        : dumpvisitor.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef MARSHAL_DUMPVISITOR_H_
#define MARSHAL_DUMPVISITOR_H_

#include "../python/pyvisitor.h"

namespace marshal {

class dumpvisitor: public python::pyvisitor {

public:

	dumpvisitor();
	dumpvisitor(std::ostream& stream);
	virtual ~dumpvisitor();

	void visitBase(const python::pybase* pybase);
	void visitNone(const python::pynone* pynone);
	void visitBool(const python::pybool* pybool);
	void visitInt(const python::pyint* pyint);
	void visitLong(const python::pylong* pylong);
	void visitDouble(const python::pydouble* pydouble);
	void visitBuffer(const python::pybuffer* pybuffer);
	void visitGlobal(const python::pyglobal* pyglobal);
	void visitTuple(const python::pytuple* pytuple);
	void visitList(const python::pylist* pylist);
	void visitDict(const python::pydict* pydict);
	void visitObject(const python::pyobject* pyobject);
	void visitObjectEx(const python::pyobjectex* pyobjectex);
	void visitDBRowList(const python::pydbrowlist* pydbrowlist);
	void visitDBCRowSet(const python::pydbcrowset* pydbcrowset);
	void visitDBRowDescriptor(const python::pydbrowdescriptor*
			pydbrowdescriptor);
	void visitDBRow(const python::pydbrow* pydbrow);

	void visitObjectExLike(const python::pyobjectex* pyobjectex,
			const std::string& name);

protected:

	std::ostream& m_stream;

	const std::string indent() const;

	void push() { m_indentStack.push_back(1); };
	void pop() { m_indentStack.pop_back(); };

	std::vector<int> m_indentStack;
};

} /* namespace marshal */

#endif /* MARSHAL_DUMPVISITOR_H_ */
