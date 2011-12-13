//==========================================================================
// Name        : marketorders.cpp
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */
#include "marketorders.h"

namespace evetools {

namespace model {

namespace loader {

marketorders::marketorders() : m_regionID(0), m_typeID(0), m_timestamp(0) {
}

marketorders::marketorders(const marketorders&) : m_regionID(0), m_typeID(0), m_timestamp(0) {
}

marketorders::marketorders(const std::string& path) : m_regionID(0), m_typeID(0), m_timestamp(0) {

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

marketorders::~marketorders() {

}

void marketorders::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
		const python::pytuple* tuple = NULL;

		if (!parentTuple || parentTuple->size() != 2) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		tuple = parentTuple->at(0)->asTuple();

		if (!tuple || tuple->size() != 4) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(0)->isBuffer()) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(1)->isBuffer()) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(1)->asBuffer()->str().compare("GetOrders") == 0) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(2)->isInt()) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!tuple->at(3)->isInt()) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		if (!parentTuple->at(1)->isDict()) {
			throw marshal::loadErrorException("Parsing MarketOrders");
		}

		m_regionID = tuple->at(2)->asInt()->value();
		m_typeID = tuple->at(3)->asInt()->value();

}

void marketorders::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
		const python::pylist* list = NULL;
		const python::pybase* dummy = dict->at("lret");

		if (!dummy) {
			throw marshal::loadErrorException("Parsing MarketOrders Object");
		}

		list = dummy->asList();

		if (!list) {
			throw marshal::loadErrorException("Parsing MarketOrders Object");
		}

		python::pylist::const_iterator iteratorList = list->begin();
		python::pylist::const_iterator endList = list->end();

		for (; iteratorList != endList; ++iteratorList) {
			if (!(*iteratorList)->isDBRowList()) {
				throw marshal::loadErrorException("Parsing MarketOrders ObjectList");
			}
			loadOrders(*((*iteratorList)->asDBRowList()));
		}
}


void marketorders::loadOrders(const python::pydbrowlist& rowlist) {

	python::pylist::const_iterator itrCurrent = rowlist.list()->begin();
	python::pylist::const_iterator itrEnd = rowlist.list()->end();

	for (; itrCurrent != itrEnd; ++itrCurrent) {
		m_list.push_back(model::marketorder::create(*(*itrCurrent)->asDBRow()));
	}
}

size_t marketorders::size() const {
	return (m_list.size());
}

marketorders::iterator marketorders::begin() {
	return (m_list.begin());
}
marketorders::iterator marketorders::end() {
	return (m_list.end());
}

marketorders::const_iterator marketorders::begin() const {
	return (m_list.begin());
}
marketorders::const_iterator marketorders::end() const {
	return (m_list.end());
}

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */
