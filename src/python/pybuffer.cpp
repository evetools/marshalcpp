//==========================================================================
// Name        : pybuffer.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pybuffer.h"

namespace evetools {

namespace python {

pybuffer::pybuffer() :
		pybase(PYTYPE_BUFFER), m_buffer(NULL), m_size(0) {
}

pybuffer::pybuffer(const pybuffer&) :
		pybase(PYTYPE_BUFFER), m_buffer(NULL), m_size(0) {
}

pybuffer::pybuffer(const char* buf, const size_t bufSize) :
		pybase(PYTYPE_BUFFER), m_buffer(NULL), m_size(0) {

	if (buf && bufSize) {
		m_buffer = new char[bufSize];
		::memcpy(m_buffer, buf, bufSize);
		m_size = bufSize;
	}
}

pybuffer::pybuffer(const pytypes& pyType, const char* buf, const size_t bufSize) :
		pybase(pyType), m_buffer(NULL), m_size(0) {

	if (buf && bufSize) {
		m_buffer = new char[bufSize];
		::memcpy(m_buffer, buf, bufSize);
		m_size = bufSize;
	}
}

pybuffer::~pybuffer() {
	if (m_buffer) {
		delete[] m_buffer;
	}
}

const char* pybuffer::value() const {
	return (m_buffer);
}

size_t pybuffer::size() const {
	return (m_size);
}

const std::string pybuffer::str() const {
	return (std::string(m_buffer, m_size));
}
void pybuffer::visit(pyvisitor& visitor) const {
	visitor.visitBuffer(this);
}

} /* namespace python */

} /* namespace evetools */
