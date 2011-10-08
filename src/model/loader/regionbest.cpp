//==========================================================================
// Name        : regionbest.cpp
// Version     : 0.0.1
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

namespace model {

namespace loader {

regionbest::regionbest() {
}

regionbest::regionbest(const regionbest&) {
}

regionbest::regionbest(const std::string& path) {

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

}

void regionbest::validate(const python::pybase& py) {

	const python::pytuple* parentTuple = py.asTuple();
	const python::pytuple* tuple = NULL;

	if (!parentTuple || parentTuple->size() != 2) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	tuple = parentTuple->at(0)->asTuple();

	if (!tuple || tuple->size() != 3) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(0)->isBuffer()) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(0)->asBuffer()->str().compare("marketProxy") == 0) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(1)->isBuffer()) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(1)->asBuffer()->str().compare("GetRegionBest") == 0) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!tuple->at(2)->isInt()) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	if (!parentTuple->at(1)->isDict()) {
		throw marshal::loadErrorException("Parsing MarketBest");
	}

	m_regionID = tuple->at(2)->asInt()->value();
}

void regionbest::load(const python::pybase& py) {

	const python::pydict* dict = py.asTuple()->at(1)->asDict();
		const python::pyobjectex* objectex = NULL;
		const python::pybase* dummy = dict->at("lret");

		if (!dummy) {
			throw marshal::loadErrorException("Parsing MarketBest Object");
		}

		objectex = dummy->asObjectEx();

		if (!objectex) {
			throw marshal::loadErrorException("Parsing MarketBest Object");
		}

		python::pydict::const_iterator itrCurrent = objectex->dict()->begin();
		python::pydict::const_iterator itrEnd = objectex->dict()->end();

		for (; itrCurrent != itrEnd; ++itrCurrent) {
			if ((*itrCurrent).first->isDBRow()) {
				m_list.push_back(model::regionbest::create(*(*itrCurrent).first->asDBRow()));
			}

		}
}

size_t regionbest::size() const {
	return (m_list.size());
}

regionbest::iterator regionbest::begin() {
	return (m_list.begin());
}
regionbest::iterator regionbest::end() {
	return (m_list.end());
}

regionbest::const_iterator regionbest::begin() const {
	return (m_list.begin());
}
regionbest::const_iterator regionbest::end() const {
	return (m_list.end());
}

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */
