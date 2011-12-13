//==========================================================================
// Name        : istream.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "istream.h"
#include "streamiterator.h"

namespace evetools {

namespace marshal {

istream::istream() :
		m_buffer(NULL), m_size(0) {
}

istream::istream(const_pointer buffer, size_type bufferSize) :
		m_buffer(NULL), m_size(0) {
	if (buffer && bufferSize) {
		m_buffer = new value_type[bufferSize];
		memcpy(m_buffer, buffer, bufferSize);
		m_size = bufferSize;
	} else {
		throw std::runtime_error("Opening stream.");
	}
}

istream::istream(const istream& stream) :
		m_buffer(NULL), m_size(0) {
	if (stream.m_buffer && stream.size()) {
		m_buffer = new value_type[stream.size()];
		::memcpy(m_buffer, stream.m_buffer, stream.size());
		m_size = stream.size();
	} else {
		throw std::runtime_error("Opening stream.");
	}
}

istream::istream(std::ifstream& stream) :
		m_buffer(NULL), m_size(0) {
	if (stream.is_open()) {
		size_type pos = stream.tellg();
		stream.seekg(0, std::ios::end);
		m_size = stream.tellg();
		m_buffer = new value_type[m_size];
		stream.seekg(0, std::ios::beg);
		stream.read(m_buffer, m_size);
		stream.seekg(pos, std::ios::beg);
	} else {
		throw std::runtime_error("Opening stream.");
	}
}

istream::~istream() {
	if (m_buffer) {
		delete[] m_buffer;
	}
}

istream::size_type istream::size() const {
	return (m_size);
}

bool istream::empty() const {
	return (m_size > 0);
}

istream::value_type istream::operator[](istream::size_type position) const {
	if (position > m_size) {
		std::stringstream stream;
		stream << "size: " << m_size;
		stream << " position: " << position;
		throw std::out_of_range(stream.str());
	}
	return (m_buffer[position]);
}

istream::const_iterator istream::begin() const {
	return (iterator(this, 0));
}

istream::const_iterator istream::end() const {
	return (iterator(this, m_size));
}

} /* namespace marshal */

} /* namespace evetools */
