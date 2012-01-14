//==========================================================================
// Name        : streamiterator.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_STREAMITERATOR_H_
#define EVETOOLS_MARSHAL_STREAMITERATOR_H_

#include "istream.h"

namespace evetools {

namespace marshal {

class streamiterator {

public:

	typedef istream::value_type		value_type;
	typedef istream::const_value_type	const_value_type;

	typedef istream::pointer			pointer;
	typedef istream::const_pointer		const_pointer;

	typedef istream::reference			reference;
	typedef istream::const_reference	const_reference;

	typedef istream::difference_type	difference_type;
	typedef istream::size_type			size_type;

	streamiterator(const marshal::istream* stream, size_type position);
	streamiterator(const marshal::istream* stream, size_type position, size_type max);
	streamiterator(const streamiterator& iterator);
	streamiterator(const streamiterator& iterator, size_type max);
	virtual ~streamiterator();

	bool operator==(const streamiterator& iterator) const;
	bool operator!=(const streamiterator& iterator) const;

	streamiterator& operator++();
	streamiterator& operator--();

	streamiterator operator++(int size);
	streamiterator operator--(int size);

	streamiterator operator+(int size);
	streamiterator operator-(int size);

	streamiterator operator+=(int size);
	streamiterator operator-=(int size);

	const streamiterator& operator=(const streamiterator& iterator);

	value_type operator*() const;

	size_type pos() const;
	size_type max() const;

	template<typename T>
	T peek() {
		if (m_stream) {
			T value = m_stream->read<T>(m_current);
			return (value);
		}
		throw std::runtime_error("invalid stream in iterator");
	}

	template<typename T>
	T read() {
		if (m_stream) {
			T value = m_stream->read<T>(m_current);
			*this += sizeof(T);
			return (value);
		}
		throw std::runtime_error("invalid stream in iterator");
	}

	template<typename T>
	T* read(size_t size) {
		if (m_stream) {
			T* value = m_stream->read<T>(m_current, size);
			*this += sizeof(T) * size;
			return (value);
		}
		throw std::runtime_error("invalid stream in iterator");
	}

	streamiterator();

private:

	const marshal::istream* m_stream;

	size_type m_current;
	size_type m_max;
};

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_STREAMITERATOR_H_ */
