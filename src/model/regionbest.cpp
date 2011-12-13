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

namespace model {


regionbest::regionbest( const int64_t& price, const double& volRemaining, const int16_t& typeID, const int32_t& stationID) : 
m_price(price), m_volRemaining(volRemaining), m_typeID(typeID), m_stationID(stationID){
}

regionbest::~regionbest() {
}

regionbest::regionbest() : 
m_price(0), m_volRemaining(0.0f), m_typeID(0), m_stationID(0) {
}

void regionbest::setPrice(const int64_t& price) {
	m_price = price;
}

int64_t regionbest::getPrice() const {
	return (m_price);
}

double regionbest::getPriceInISK() const {
	return ((double)m_price / 10000.0f);
}

void regionbest::setVolRemaining(const double& volRemaining) {
	m_volRemaining = volRemaining;
}

double regionbest::getVolRemaining() const {
	return (m_volRemaining);
}

void regionbest::setTypeID(const int16_t& typeID) {
	m_typeID = typeID;
}

int16_t regionbest::getTypeID() const {
	return (m_typeID);
}

void regionbest::setStationID(const int32_t& stationID) {
	m_stationID = stationID;
}

int32_t regionbest::getStationID() const {
	return (m_stationID);
}


regionbest* regionbest::create(python::pydbrow& row) {

	regionbest* object = new regionbest();
	const python::pybase* pyBase = NULL;

	pyBase = row.dict()->at("price");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setPrice(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("volRemaining");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setVolRemaining(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("typeID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setTypeID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("stationID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setStationID(pyBase->asInt()->value());
	}

	return (object);
}

} /* namespace model */

} /* namespace evetools */

