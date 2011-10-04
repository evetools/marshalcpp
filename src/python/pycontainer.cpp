//==========================================================================
// Name        : pycontainer.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include "pycontainer.h"

namespace python {

pycontainer::pycontainer() :
		pybase(PYTYPE_UNKNOWN_CONTAINER) {
}

pycontainer::pycontainer(const pytypes& pyType) :
		pybase(pyType) {
}

pycontainer::pycontainer(const pycontainer& container) :
		pybase(container.type()) {
}

pycontainer::~pycontainer() {
	pybase* py = NULL;
	for (size_t loop = 0; loop < m_container.size(); loop++) {
		py = m_container.at(loop);
		if (py) {
			py->decRef();
		}
	}
}

size_t pycontainer::size() const {
	return (m_container.size());
}

pybase* pycontainer::at(size_t pos) const {
	return (m_container.at(pos));
}

void pycontainer::push_back(pybase* object) {
	if (!object) {
		std::stringstream stream;
		stream << "Invalid NULL argument passed to pycontainer::push_back.";
		throw pyNullException(stream.str());
	}
	object->incRef();
	m_container.push_back(object);
}

pycontainer::iterator pycontainer::begin() {
	return (m_container.begin());
}
pycontainer::iterator pycontainer::end() {
	return (m_container.end());
}

pycontainer::const_iterator pycontainer::begin() const {
	return (m_container.begin());
}
pycontainer::const_iterator pycontainer::end() const {
	return (m_container.end());
}

} /* namespace python */

