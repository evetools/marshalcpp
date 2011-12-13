//==========================================================================
// Name        : mapregions.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */
#include "mapregions.h"

namespace evetools {

namespace model {

namespace loader {

mapregions::mapregions() {
}

mapregions::mapregions(const mapregions&) {
}

mapregions::mapregions(const std::string& path) {

	evetools::marshal::reader* reader = NULL;
	evetools::python::pybase* py = NULL;

	try {
		reader = new evetools::marshal::reader(path);
		py = reader->read();

		if (reader) {
			delete (reader);
			reader = NULL;
		}

		validate(*py);
		load(*py);

	} catch (std::exception& exception) {

		if (reader) {
			delete (reader);
		}

		if (py) {
			py->decRef();
		}

		throw std::runtime_error(exception.what());
	}

	if (py) {
		py->decRef();
	}
}

mapregions::~mapregions() {

}

void mapregions::validate(const python::pybase& py) {

	const python::pydbcrowset* object = py.asDBCRowSet();

	if (!object) {
		throw marshal::loadErrorException("Parsing InvTypes");
	}

}

void mapregions::load(const python::pybase& py) {

	const python::pydbcrowset* object = py.asDBCRowSet();

	if (!object) {
		throw marshal::loadErrorException("Parsing InvTypes Object");
	}

	python::pylist::const_iterator itrCurrent = object->list()->begin();
	python::pylist::const_iterator itrEnd = object->list()->end();

	for (; itrCurrent != itrEnd; ++itrCurrent) {
		m_list.push_back(model::mapregion::create(*(*itrCurrent)->asDBRow()));
	}
}

size_t mapregions::size() const {
	return (m_list.size());
}

mapregions::iterator mapregions::begin() {
	return (m_list.begin());
}
mapregions::iterator mapregions::end() {
	return (m_list.end());
}

mapregions::const_iterator mapregions::begin() const {
	return (m_list.begin());
}
mapregions::const_iterator mapregions::end() const {
	return (m_list.end());
}

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */
