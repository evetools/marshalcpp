//==========================================================================
// Name        : streamiterator.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "streamiterator.h"

namespace evetools {

namespace marshal {

streamiterator::streamiterator() :
		m_stream(NULL), m_current(0), m_max(0) {
}

streamiterator::streamiterator(const istream* stream,
		streamiterator::size_type position) :
		m_stream(stream), m_current(position), m_max(stream->size()) {
}

streamiterator::streamiterator(const istream* stream,
		streamiterator::size_type position, streamiterator::size_type maxSize) :
		m_stream(stream), m_current(position), m_max(maxSize) {
}

streamiterator::streamiterator(const streamiterator& iterator) :
		m_stream(iterator.m_stream), m_current(iterator.m_current), m_max(
				iterator.m_max) {
}

streamiterator::streamiterator(const streamiterator& iterator,
		streamiterator::size_type maxSize) :
		m_stream(iterator.m_stream), m_current(iterator.m_current), m_max(maxSize) {
}

streamiterator::~streamiterator() {
}

bool streamiterator::operator==(const streamiterator& iterator) const {
	return (m_current == iterator.m_current);
}

bool streamiterator::operator!=(const streamiterator& iterator) const {
	return (m_current != iterator.m_current);
}

streamiterator& streamiterator::operator++() {
	if (m_current + 1 > m_max) {
		std::stringstream stream;
		stream << "iterator current: " << m_current + 1;
		stream << " max: " << m_max;
		throw std::out_of_range(stream.str());
	}
	++m_current;
	return (*this);
}

streamiterator& streamiterator::operator--() {
	if (m_current > 0) {
		--m_current;
		return (*this);
	} else {
		std::stringstream stream;
		stream << "iterator current: " << m_current;
		stream << " max: " << m_max;
		throw std::out_of_range(stream.str());
	}
}

streamiterator streamiterator::operator++(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		++*this;
		--size;
	}
	return (iterator);
}

streamiterator streamiterator::operator--(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		--*this;
		--size;
	}
	return (iterator);
}

streamiterator streamiterator::operator+(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		++*this;
		--size;
	}
	return (iterator);
}

streamiterator streamiterator::operator-(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		--*this;
		--size;
	}
	return (iterator);
}

streamiterator streamiterator::operator+=(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		++*this;
		--size;
	}
	return (iterator);
}

streamiterator streamiterator::operator-=(int size) {
	streamiterator iterator = *this;
	while (size > 0) {
		--*this;
		--size;
	}
	return (iterator);
}

const streamiterator& streamiterator::operator=(const streamiterator& iterator) {
	m_current = iterator.m_current;
	m_max = iterator.m_max;
	m_stream = iterator.m_stream;
	return (*this);
}

streamiterator::value_type streamiterator::operator*() const {
	if (m_current > m_max) {
		std::stringstream stream;
		stream << "iterator current: " << m_current;
		stream << " max: " << m_max;
		throw std::out_of_range(stream.str());
	}
	return (*m_stream)[m_current];
}

streamiterator::size_type streamiterator::pos() const {
	return (m_current);
}

streamiterator::size_type streamiterator::max() const {
	return (m_max);
}

} /* namespace marshal */

} /* namespace evetools */
