//==========================================================================
// Name        : markethistory.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */
#include "markethistory.h"

namespace evetools {

namespace marshal {

namespace loader {

markethistory::markethistory() : m_regionID(0), m_typeID(0), m_visitor(NULL) {
}

markethistory::markethistory(const markethistory&) : m_regionID(0), m_typeID(0), m_visitor(NULL) {
}

markethistory::markethistory(const std::string& path) : m_regionID(0), m_typeID(0), m_visitor(NULL) {

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

markethistory::~markethistory() {

	if (m_visitor) {
		delete (m_visitor);
	}
}

void markethistory::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
	const python::pytuple* tuple = NULL;

	if (!parentTuple || parentTuple->size() != 2) {
		throw loadErrorException("Parsing MarketHistory");
	}

	tuple = parentTuple->at(0)->asTuple();

	if (!tuple || tuple->size() != 4) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(0)->isBuffer()) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(1)->isBuffer()) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(1)->asBuffer()->str().compare("GetOldPriceHistory") == 0) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(2)->isInt()) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(3)->isInt()) {
		throw loadErrorException("Parsing MarketHistory");
	}

	if (!parentTuple->at(1)->isDict()) {
		throw loadErrorException("Parsing MarketHistory");
	}

	m_regionID = tuple->at(2)->asInt()->value();
	m_typeID = tuple->at(3)->asInt()->value();

}

void markethistory::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
	const python::pydbcrowset* object = NULL;
	const python::pybase* dummy = dict->at("lret");

	if (!dummy) {
		throw loadErrorException("Parsing MarketHistory Object");
	}

	object = dummy->asDBCRowSet();

	if (!object) {
		throw loadErrorException("Parsing MarketHistory Object");
	}

	python::pylist::const_iterator iteratorList = object->list()->begin();
	python::pylist::const_iterator endList = object->list()->end();

	m_visitor = new csvvisitor();

	for (; iteratorList != endList; ++iteratorList) {
		if (!(*iteratorList)->isDBRow()) {
			throw loadErrorException("Parsing MarketHistory ObjectList");
		}
		loadEntry(*((*iteratorList)->asDBRow()));
	}
}

void markethistory::loadEntry(const python::pydbrow& entry) {
	entry.asDBRow()->dict()->visit(*m_visitor);
}

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */
