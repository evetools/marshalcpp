//==========================================================================
// Name        : markethistory.cpp
// Version     : 0.0.2
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

namespace model {

namespace loader {

markethistory::markethistory() {
}

markethistory::markethistory(const markethistory&) {
}

markethistory::markethistory(const std::string& path) {

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

}

void markethistory::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
	const python::pytuple* tuple = NULL;

	if (!parentTuple || parentTuple->size() != 2) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	tuple = parentTuple->at(0)->asTuple();

	if (!tuple || tuple->size() != 4) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(0)->isBuffer()) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(1)->isBuffer()) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(1)->asBuffer()->str().compare("GetOldPriceHistory") == 0) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(2)->isInt()) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!tuple->at(3)->isInt()) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	if (!parentTuple->at(1)->isDict()) {
		throw marshal::loadErrorException("Parsing MarketHistory");
	}

	m_regionID = tuple->at(2)->asInt()->value();
	m_typeID = tuple->at(3)->asInt()->value();

}

void markethistory::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
	const python::pydbcrowset* object = NULL;
	const python::pybase* dummy = dict->at("lret");

	if (!dummy) {
		throw marshal::loadErrorException("Parsing MarketHistory Object");
	}

	object = dummy->asDBCRowSet();

	if (!object) {
		throw marshal::loadErrorException("Parsing MarketHistory Object");
	}

	python::pylist::const_iterator iteratorList = object->list()->begin();
	python::pylist::const_iterator endList = object->list()->end();

	for (; iteratorList != endList; ++iteratorList) {
		if (!(*iteratorList)->isDBRow()) {
			throw marshal::loadErrorException("Parsing MarketHistory ObjectList");
		}
		m_list.push_back(model::markethistory::create(*(*iteratorList)->asDBRow()));
	}
}

size_t markethistory::size() const {
	return (m_list.size());
}

markethistory::iterator markethistory::begin() {
	return (m_list.begin());
}
markethistory::iterator markethistory::end() {
	return (m_list.end());
}

markethistory::const_iterator markethistory::begin() const {
	return (m_list.begin());
}
markethistory::const_iterator markethistory::end() const {
	return (m_list.end());
}

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */
