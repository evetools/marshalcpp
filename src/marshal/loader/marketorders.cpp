//==========================================================================
// Name        : marketorders.cpp
// Version     : 0.0.1
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

namespace marshal {

namespace loader {

marketorders::marketorders() : m_regionID(0), m_typeID(0), m_visitor(NULL) {
}

marketorders::marketorders(const marketorders&) : m_regionID(0), m_typeID(0), m_visitor(NULL) {
}

marketorders::marketorders(const std::string& path) : m_regionID(0), m_typeID(0), m_visitor(NULL) {

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

	if (m_visitor) {
		delete (m_visitor);
	}
}

void marketorders::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
	const python::pytuple* tuple = NULL;

	if (!parentTuple || parentTuple->size() != 2) {
		throw loadErrorException("Parsing MarketOrders");
	}

	tuple = parentTuple->at(0)->asTuple();

	if (!tuple || tuple->size() != 4) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(0)->isBuffer()) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(1)->isBuffer()) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(1)->asBuffer()->str().compare("GetOrders") == 0) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(2)->isInt()) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!tuple->at(3)->isInt()) {
		throw loadErrorException("Parsing MarketOrders");
	}

	if (!parentTuple->at(1)->isDict()) {
		throw loadErrorException("Parsing MarketOrders");
	}

	m_regionID = tuple->at(2)->asInt()->value();
	m_typeID = tuple->at(3)->asInt()->value();

}

void marketorders::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
	const python::pylist* list = NULL;

	python::pydict::const_iterator iterator = dict->begin();
	python::pydict::const_iterator end = dict->end();

	for (; iterator != end; ++iterator) {

		if ((*iterator)->isBuffer()) {
			if ((*iterator)->asBuffer()->str().compare("lret") == 0) {
				list = (*(++iterator))->asList();
				break;
			}
		}

		++iterator;
	}

	if (!list) {
		throw loadErrorException("Parsing MarketOrders Object");
	}

	python::pylist::const_iterator iteratorList = list->begin();
	python::pylist::const_iterator endList = list->end();

	m_visitor = new csvvisitor();

	for (; iteratorList != endList; ++iteratorList) {
		if (!(*iteratorList)->isDBRowList()) {
			throw loadErrorException("Parsing MarketOrders ObjectList");
		}
		loadOrders(*((*iteratorList)->asDBRowList()));
	}
}

void marketorders::loadOrders(const python::pydbrowlist& rowlist) {

	python::pylist::const_iterator iterator = rowlist.list()->begin();
	python::pylist::const_iterator end = rowlist.list()->end();

	for (; iterator != end; ++iterator) {
		(*iterator)->asDBRow()->dict()->visit(*m_visitor);
	}
}

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */
