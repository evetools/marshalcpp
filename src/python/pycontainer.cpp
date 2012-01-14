//==========================================================================
// Name        : pycontainer.cpp
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

int pycontainer::compareValues(const pycontainer& rval) const {

		if (m_container.size() == rval.size()) {

			pycontainer::const_iterator itrBegin = begin();
			pycontainer::const_iterator itrEnd = end();

			pycontainer::const_iterator rvalItrBegin = rval.begin();
			pycontainer::const_iterator rvalItrEnd = rval.end();

			int ret = 0;

			for  ( ;((itrBegin != itrEnd) && (rvalItrBegin != rvalItrEnd));
					(++itrBegin, ++rvalItrBegin)) {

				ret = (*itrBegin)->compare(*(*rvalItrBegin));

				if (ret != 0) {
					return (ret);
				}
			}
		} else if (m_container.size() < rval.size()) {
			return (-1);
		}

		return (1);

	return (0);
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

} /* namespace evetools */

