//==========================================================================
// Name        : mapregions.cpp
// Version     : 0.0.1
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

namespace marshal {

namespace loader {

mapregions::mapregions() {
}

mapregions::mapregions(const mapregions&) : m_visitor(NULL) {
}

mapregions::mapregions(const std::string& path) : m_visitor(NULL) {

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

	if (m_visitor) {
		delete (m_visitor);
	}
}

void mapregions::validate(const python::pybase& py) {

	const python::pydbcrowset* object = py.asDBCRowSet();

	if (!object) {
		throw loadErrorException("Parsing MapRegions");
	}

}

void mapregions::load(const python::pybase& py) {

	const python::pydbcrowset* object = py.asDBCRowSet();

	if (!object) {
		throw loadErrorException("Parsing MapRegions Object");
	}

	python::pylist::const_iterator iterator = object->list()->begin();
	python::pylist::const_iterator end = object->list()->end();

	m_visitor = new csvvisitor();

	for (; iterator != end; ++iterator) {
			(*iterator)->asDBRow()->dict()->visit(*m_visitor);
	}
}

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */
