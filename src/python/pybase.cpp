//==========================================================================
// Name        : pybase.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "py.h"

namespace python {

pybase::pybase() :
		m_type(PYTYPE_UNKNOWN), m_refCounter(0) {
}

pybase::pybase(const pybase&) :
		m_type(PYTYPE_UNKNOWN), m_refCounter(0) {
}

pybase::pybase(const pytypes& pyType) :
		m_type(pyType), m_refCounter(0) {
}

pybase::~pybase() {
}

pytypes pybase::type() const {
	return (m_type);
}

void pybase::visit(pyvisitor& visitor) const {
	visitor.visitBase(this);
}

void pybase::incRef() {
	++m_refCounter;
}

void pybase::decRef() {

	if (m_refCounter) {
		--m_refCounter;
	}

	if (!m_refCounter) {
		delete (this);
	}
}

bool pybase::isNone() const {
	return (m_type == PYTYPE_NONE);
}

bool pybase::isBool() const {
	return (m_type == PYTYPE_BOOL);
}

bool pybase::isInt() const {
	return (m_type == PYTYPE_INT);
}

bool pybase::isLong() const {
	return (m_type == PYTYPE_LONG);
}

bool pybase::isDouble() const {
	return (m_type == PYTYPE_DOUBLE);
}

bool pybase::isBuffer() const {
	return (m_type == PYTYPE_BUFFER);
}

bool pybase::isGlobal() const {
	return (m_type == PYTYPE_GLOBAL);
}

bool pybase::isTuple() const {
	return (m_type == PYTYPE_TUPLE);
}

bool pybase::isList() const {
	return (m_type == PYTYPE_LIST);
}

bool pybase::isDict() const {
	return (m_type == PYTYPE_DICT);
}

bool pybase::isObject() const {
	return (m_type == PYTYPE_OBJECT);
}

bool pybase::isObjectEx() const {
	return (m_type == PYTYPE_OBJECTEX);
}

bool pybase::isDBRowList() const {
	return (m_type == PYTYPE_DBROWLIST);
}

bool pybase::isDBCRowSet() const {
	return (m_type == PYTYPE_DBCROWSET);
}

bool pybase::isDBRowDescriptor() const {
	return (m_type == PYTYPE_DBROWDESCRIPTOR);
}

bool pybase::isDBRow() const {
	return (m_type == PYTYPE_DBROW);
}

pynone* pybase::asNone() {
	assert(isNone());
	return (reinterpret_cast<pynone*>(this));
}

const pynone* pybase::asNone() const {
	assert(isNone());
	return (reinterpret_cast<const pynone*>(this));
}

pybool* pybase::asBool() {
	assert(isBool());
	return (reinterpret_cast<pybool*>(this));
}

const pybool* pybase::asBool() const {
	assert(isBool());
	return (reinterpret_cast<const pybool*>(this));
}

pyint* pybase::asInt() {
	assert(isInt());
	return (reinterpret_cast<pyint*>(this));
}

const pyint* pybase::asInt() const {
	assert(isInt());
	return (reinterpret_cast<const pyint*>(this));
}

pylong* pybase::asLong() {
	assert(isLong());
	return (reinterpret_cast<pylong*>(this));
}

const pylong* pybase::asLong() const {
	assert(isLong());
	return (reinterpret_cast<const pylong*>(this));
}

pydouble* pybase::asDouble() {
	assert(isDouble());
	return (reinterpret_cast<pydouble*>(this));
}

const pydouble* pybase::asDouble() const {
	assert(isDouble());
	return (reinterpret_cast<const pydouble*>(this));
}
pybuffer* pybase::asBuffer() {
	assert(isBuffer());
	return (reinterpret_cast<pybuffer*>(this));
}

const pybuffer* pybase::asBuffer() const {
	assert(isBuffer());
	return (reinterpret_cast<const pybuffer*>(this));
}

pyglobal* pybase::asGlobal() {
	assert(isGlobal());
	return (reinterpret_cast<pyglobal*>(this));
}

const pyglobal* pybase::asGlobal() const {
	assert(isGlobal());
	return (reinterpret_cast<const pyglobal*>(this));
}

pytuple* pybase::asTuple() {
	assert(isTuple());
	return (reinterpret_cast<pytuple*>(this));
}
const pytuple* pybase::asTuple() const {
	assert(isTuple());
	return (reinterpret_cast<const pytuple*>(this));
}

pylist* pybase::asList() {
	assert(isList());
	return (reinterpret_cast<pylist*>(this));
}

const pylist* pybase::asList() const {
	assert(isList());
	return (reinterpret_cast<const pylist*>(this));
}

pydict* pybase::asDict() {
	assert(isDict());
	return (reinterpret_cast<pydict*>(this));
}

const pydict* pybase::asDict() const {
	assert(isDict());
	return (reinterpret_cast<const pydict*>(this));
}

pyobject* pybase::asObject() {
	assert(isObject());
	return (reinterpret_cast<pyobject*>(this));
}

const pyobject* pybase::asObject() const {
	assert(isObject());
	return (reinterpret_cast<const pyobject*>(this));
}

pyobjectex* pybase::asObjectEx() {
	assert(isObjectEx());
	return (reinterpret_cast<pyobjectex*>(this));
}

const pyobjectex* pybase::asObjectEx() const {
	assert(isObjectEx());
	return (reinterpret_cast<const pyobjectex*>(this));
}

pydbrowlist* pybase::asDBRowList() {
	assert(isDBRowList());
	return (reinterpret_cast<pydbrowlist*>(this));
}

const pydbrowlist* pybase::asDBRowList() const {
	assert(isDBRowList());
	return (reinterpret_cast<const pydbrowlist*>(this));
}

pydbcrowset* pybase::asDBCRowSet() {
	assert(isDBCRowSet());
	return (reinterpret_cast<pydbcrowset*>(this));
}

const pydbcrowset* pybase::asDBCRowSet() const {
	assert(isDBCRowSet());
	return (reinterpret_cast<const pydbcrowset*>(this));
}

pydbrowdescriptor* pybase::asDBRowDescriptor() {
	assert(isDBRowDescriptor());
	return (reinterpret_cast<pydbrowdescriptor*>(this));
}

const pydbrowdescriptor* pybase::asDBRowDescriptor() const {
	assert(isDBRowDescriptor());
	return (reinterpret_cast<const pydbrowdescriptor*>(this));
}

pydbrow* pybase::asDBRow() {
	assert(isDBRow());
	return (reinterpret_cast<pydbrow*>(this));
}

const pydbrow* pybase::asDBRow() const {
	assert(isDBRow());
	return (reinterpret_cast<const pydbrow*>(this));
}

} /* namespace python */

