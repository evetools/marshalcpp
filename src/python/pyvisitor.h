//==========================================================================
// Name        : pyvisitor.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_PYTHON_PYVISITOR_H_
#define EVETOOLS_PYTHON_PYVISITOR_H_

#include <iostream>
#include <iomanip>
#include <vector>

namespace evetools {

namespace python {

class pybase;
class pynone;
class pybool;
class pyint;
class pyuint;
class pylong;
class pyulong;
class pyfloat;
class pydouble;
class pybuffer;
class pyglobal;
class pytuple;
class pylist;
class pydict;
class pyobject;
class pyobjectex;
class pydbrowlist;
class pydbcrowset;
class pydbrowdescriptor;
class pydbrow;

class pyvisitor {

public:

	pyvisitor();
	virtual ~pyvisitor();

	virtual void visitBase(const pybase* pybase) = 0;
	virtual void visitNone(const pynone* pynone) = 0;
	virtual void visitBool(const pybool* pybool) = 0;
	virtual void visitInt(const pyint* pyint) = 0;
	virtual void visitUInt(const pyuint* pyint) = 0;
	virtual void visitLong(const pylong* pylong) = 0;
	virtual void visitULong(const pyulong* pyulong) = 0;
	virtual void visitFloat(const pyfloat* pyfloat) = 0;
	virtual void visitDouble(const pydouble* pydouble) = 0;
	virtual void visitBuffer(const pybuffer* pybuffer) = 0;
	virtual void visitGlobal(const pyglobal* pyglobal) = 0;
	virtual void visitTuple(const pytuple* pytuple) = 0;
	virtual void visitList(const pylist* pylist) = 0;
	virtual void visitDict(const pydict* pydict) = 0;
	virtual void visitObject(const pyobject* pyobject) = 0;
	virtual void visitObjectEx(const pyobjectex* pyobjectex) = 0;
	virtual void visitDBRowList(const pydbrowlist* pydbrowlist) = 0;
	virtual void visitDBCRowSet(const pydbcrowset* pydbcrowset) = 0;
	virtual void visitDBRowDescriptor(const pydbrowdescriptor*
			pydbrowdescriptor) = 0;
	virtual void visitDBRow(const pydbrow* pydbrow) = 0;
};

} /* namespace python */

} /* namespace evetools */

#endif /* EVETOOLS_PYTHON_PYVISITOR_H_ */
