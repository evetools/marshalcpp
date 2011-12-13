//==========================================================================
// Name        : csvvisitor.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_LOADER_CSVVISITOR_H_
#define EVETOOLS_MARSHAL_LOADER_CSVVISITOR_H_

#include "../generator/dbrow.h"
#include "../../python/pyvisitor.h"

namespace evetools {

namespace marshal {

namespace loader {

class csvvisitor: public python::pyvisitor {

public:

	csvvisitor();
	csvvisitor(std::ostream& stream);
	virtual ~csvvisitor();

	void visitBase(const python::pybase* pybase);
	void visitNone(const python::pynone* pynone);
	void visitBool(const python::pybool* pybool);
	void visitInt(const python::pyint* pyint);
	void visitUInt(const python::pyuint* pyuint);
	void visitLong(const python::pylong* pylong);
	void visitULong(const python::pyulong* pyulong);
	void visitFloat(const python::pyfloat* pyfloat);
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

	const python::pydict* m_first;
};

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_LOADER_CSVVISITOR_H_ */
