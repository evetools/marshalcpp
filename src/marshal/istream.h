//==========================================================================
// Name        : istream.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef MARSHAL_ISTREAM_H_
#define MARSHAL_ISTREAM_H_

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <limits>
#include <cassert>
#include <cwchar>
#include <stack>

#include <stdint.h>

#include "../common/utf8.h"

namespace marshal {

class streamiterator;

class istream {

public:

	typedef char					value_type;
	typedef const char				const_value_type;

	typedef char*					pointer;
	typedef const char*				const_pointer;

	typedef char&					reference;
	typedef const char&				const_reference;

	typedef ptrdiff_t				difference_type;
	typedef size_t					size_type;

	typedef streamiterator			iterator;
	typedef const streamiterator	const_iterator;

	istream(std::ifstream& ifs);
	istream(const istream& stream);
	istream(const_pointer buffer, size_type size);
	virtual ~istream();

	size_type size() const;
	bool empty() const;

	value_type operator[](size_type position) const;

	const_iterator begin() const;
	const_iterator end() const;

	template<typename T>
	T read(const size_type& position) const {
		if (m_buffer) {
			T value = 0;
			::memcpy(&value, (m_buffer + position), sizeof(T));
			return (value);
		}
		throw std::runtime_error("invalid stream buffer");
	}

	template<typename T>
	T* read(const size_type& position, size_type sizeT) const {
		if (m_buffer) {
			T* value = new T[sizeT];
			::memcpy((void*)value, (m_buffer + position), sizeof(T) * sizeT);
			return (value);
		}
		throw std::runtime_error("invalid stream buffer");
	}

	istream();

private:

	pointer m_buffer;
	size_type m_size;


};

} /* namespace marshal */

#endif /* MARSHAL_ISTREAM_H_ */
