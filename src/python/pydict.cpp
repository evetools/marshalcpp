//==========================================================================
// Name        : pydict.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "py.h"

namespace evetools {

namespace python {

pydict::pydict() :
		pybase(PYTYPE_DICT) {
}

pydict::pydict(const pydict&) :
		pybase(PYTYPE_DICT) {
}

pydict::~pydict() {

	pydict::const_iterator iteratorCurrent = begin();
	pydict::const_iterator iteratorEnd = end();

	for (; iteratorCurrent != iteratorEnd; ++iteratorCurrent) {
		(*iteratorCurrent).first->decRef();
		(*iteratorCurrent).second->decRef();
	}

}

void pydict::push_back(pybase* pybaseKey, pybase* pybaseValue) {
	if (!pybaseKey) {
		std::stringstream stream;
		stream << "Invalid NULL key argument passed to pydict::push_back.";
		throw pyNullException(stream.str());
	}
	if (!pybaseValue) {
		std::stringstream stream;
		stream << "Invalid NULL value argument passed to pydict::push_back.";
		throw pyNullException(stream.str());
	}
	pybaseKey->incRef();
	pybaseValue->incRef();
	m_map.insert(std::pair<pybase*, pybase*>(pybaseKey, pybaseValue));
}

size_t pydict::size() const {
	return (m_map.size());
}

const pybase* pydict::at(const std::string& key) const {
	const pybuffer dkey(key.c_str(), key.length());
	return (at(dkey));
}

const pybase* pydict::at(const pybase& key) const {

	pydict::const_iterator iteratorCurrent = begin();
	pydict::const_iterator iteratorEnd = end();

	for (; iteratorCurrent != iteratorEnd; ++iteratorCurrent) {

		if ((*iteratorCurrent).first->compare(key) == 0) {
			return ((*iteratorCurrent).second);
		}
	}

	return (NULL);
}

pydict::iterator pydict::begin() {
	return (m_map.begin());
}

pydict::iterator pydict::end() {
	return (m_map.end());
}

pydict::const_iterator pydict::begin() const {
	return (m_map.begin());
}

pydict::const_iterator pydict::end() const {
	return (m_map.end());
}

void pydict::visit(pyvisitor& visitor) const {
	visitor.visitDict(this);
}

} /* namespace python */

} /* namespace evetools */

