//==========================================================================
// Name        : regionbest.cpp
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */
#include "regionbest.h"

namespace evetools {

namespace marshal {

namespace loader {

regionbest::regionbest() : m_regionID(0), m_visitor(NULL) {
}

regionbest::regionbest(const regionbest&) : m_regionID(0), m_visitor(NULL) {
}

regionbest::regionbest(const std::string& path) : m_regionID(0), m_visitor(NULL) {

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

regionbest::~regionbest() {

	if (m_visitor) {
		delete (m_visitor);
	}
}

void regionbest::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
	const python::pytuple* tuple = NULL;

	if (!parentTuple || parentTuple->size() != 2) {
		throw loadErrorException("Parsing MarketBest");
	}

	tuple = parentTuple->at(0)->asTuple();

	if (!tuple || tuple->size() != 3) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(0)->isBuffer()) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(1)->isBuffer()) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(1)->asBuffer()->str().compare("GetRegionBest") == 0) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(2)->isInt()) {
		throw loadErrorException("Parsing MarketBest");
	}

	if (!parentTuple->at(1)->isDict()) {
		throw loadErrorException("Parsing MarketBest");
	}

	m_regionID = tuple->at(2)->asInt()->value();
}

void regionbest::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
	const python::pyobjectex* objectex = NULL;
	const python::pybase* dummy = dict->at("lret");

	if (!dummy) {
		throw loadErrorException("Parsing MarketBest Object");
	}

	objectex = dummy->asObjectEx();

	if (!objectex) {
		throw loadErrorException("Parsing MarketBest Object");
	}

	python::pydict::const_iterator iterator = objectex->dict()->begin();
	python::pydict::const_iterator end = objectex->dict()->end();

	m_visitor = new csvvisitor();

	for (; iterator != end; ++iterator) {
		if ((*iterator).first->isDBRow()) {
			(*iterator).first->asDBRow()->dict()->visit(*m_visitor);
		}

	}
}

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */
