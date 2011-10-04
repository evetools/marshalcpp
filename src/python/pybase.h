//==========================================================================
// Name        : pybase.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef PYTHON_PYBASE_H_
#define PYTHON_PYBASE_H_

#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#include <stdint.h>

#include <zlib.h>

#include "pyvisitor.h"

namespace python {

typedef enum pytypes {
	PYTYPE_NONE,
	PYTYPE_BOOL,
	PYTYPE_INT,
	PYTYPE_LONG,
	PYTYPE_DOUBLE,
	PYTYPE_BUFFER,
	PYTYPE_GLOBAL,
	PYTYPE_TUPLE,
	PYTYPE_LIST,
	PYTYPE_DICT,
	PYTYPE_OBJECT,
	PYTYPE_OBJECTEX,
	PYTYPE_DBROWLIST,
	PYTYPE_DBCROWSET,
	PYTYPE_DBROWDESCRIPTOR,
	PYTYPE_PACKEDROW,
	PYTYPE_DBROW,
	PYTYPE_UNKNOWN,
	PYTYPE_UNKNOWN_CONTAINER
} pytypes;

typedef enum dbtypes {
	DBTYPE_EMPTY = 0,
	DBTYPE_BOOL = 11,
	DBTYPE_INT8 = 16,
	DBTYPE_UINT8 = 17,
	DBTYPE_INT16 = 2,
	DBTYPE_UNT16 = 18,
	DBTYPE_INT32 = 3,
	DBTYPE_UINT32 = 19,
	DBTYPE_INT64 = 20,
	DBTYPE_UINT64 = 21,
	DBTYPE_CURRENCY = 6,
	DBTYPE_WINFILETIME = 64,
	DBTYPE_FLOAT = 4,
	DBTYPE_DOUBLE = 5,
	DBTYPE_STRING = 129,
	DBTYPE_WSTRING = 130
} dbtypes;

class loadPyException : public std::runtime_error {

public:

	loadPyException(const std::string& msg) : std::runtime_error(msg) {}
    virtual ~loadPyException() throw() {}
};

class loadPyNullException : public loadPyException {

public:

	loadPyNullException(const std::string& msg) : loadPyException(msg) {}
    virtual ~loadPyNullException() throw() {}
};

class pyNullException : public loadPyNullException {

public:

	pyNullException(const std::string& msg) : loadPyNullException(msg) {}
    virtual ~pyNullException() throw() {}
};


class pybase {

public:

	virtual ~pybase();

	pytypes type() const;

	bool isNone() const;
	bool isBool() const;
	bool isInt() const;
	bool isLong() const;
	bool isDouble() const;
	bool isBuffer() const;
	bool isGlobal() const;
	bool isTuple() const;
	bool isList() const;
	bool isDict() const;
	bool isObject() const;
	bool isObjectEx() const;
	bool isDBRowList() const;
	bool isDBCRowSet() const;
	bool isDBRowDescriptor() const;
	bool isDBRow() const;

	pynone* asNone();
	const pynone* asNone() const;

	pybool* asBool();
	const pybool* asBool() const;

	pyint* asInt();
	const pyint* asInt() const;

	pylong* asLong();
	const pylong* asLong() const;

	pydouble* asDouble();
	const pydouble* asDouble() const;

	pybuffer* asBuffer();
	const pybuffer* asBuffer() const;

	pyglobal* asGlobal();
	const pyglobal* asGlobal() const;

	pytuple* asTuple();
	const pytuple* asTuple() const;

	pylist* asList();
	const pylist* asList() const;

	pydict* asDict();
	const pydict* asDict() const;

	pyobject* asObject();
	const pyobject* asObject() const;

	pyobjectex* asObjectEx();
	const pyobjectex* asObjectEx() const;

	pydbrowlist* asDBRowList();
	const pydbrowlist* asDBRowList() const;

	pydbcrowset* asDBCRowSet();
	const pydbcrowset* asDBCRowSet() const;

	pydbrowdescriptor* asDBRowDescriptor();
	const pydbrowdescriptor* asDBRowDescriptor() const;

	pydbrow* asDBRow();
	const pydbrow* asDBRow() const;

	virtual void visit(pyvisitor& visitor) const;

	void incRef();

	void decRef();

protected:

	pybase(const pytypes& type);

private:

	pybase();
	pybase(const pybase&);

	const pytypes m_type;

	size_t m_refCounter;
};

} /* python */

#endif /* PYTHON_PYBASE_H_ */
