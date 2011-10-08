//==========================================================================
// Name        : marketorder.cpp
// Version     : 0.0.1
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#include "marketorder.h"


namespace evetools {

namespace model {


marketorder::marketorder( const int64_t& price, const double& volRemaining, const int32_t& typeID, const int16_t& range, const int64_t& orderID, const int32_t& volEntered, const int32_t& minVolume, const bool& bid, const int64_t& issueDate, const int16_t& duration, const int32_t& stationID, const int32_t& regionID, const int32_t& solarSystemID, const int32_t& jumps) : 
m_price(price), m_volRemaining(volRemaining), m_typeID(typeID), m_range(range), m_orderID(orderID), m_volEntered(volEntered), m_minVolume(minVolume), m_bid(bid), m_issueDate(issueDate), m_duration(duration), m_stationID(stationID), m_regionID(regionID), m_solarSystemID(solarSystemID), m_jumps(jumps){
}

marketorder::~marketorder() {
}

marketorder::marketorder() : 
m_price(0), m_volRemaining(0.0f), m_typeID(0), m_range(0), m_orderID(0), m_volEntered(0), m_minVolume(0), m_bid(false), m_issueDate(0), m_duration(0), m_stationID(0), m_regionID(0), m_solarSystemID(0), m_jumps(0) {
}

void marketorder::setPrice(const int64_t& price) {
	m_price = price;
}

int64_t marketorder::getPrice() const {
	return (m_price);
}

double marketorder::getPriceInISK() const {
	return ((double)m_price / 10000.0f);
}

void marketorder::setVolRemaining(const double& volRemaining) {
	m_volRemaining = volRemaining;
}

double marketorder::getVolRemaining() const {
	return (m_volRemaining);
}

void marketorder::setTypeID(const int32_t& typeID) {
	m_typeID = typeID;
}

int32_t marketorder::getTypeID() const {
	return (m_typeID);
}

void marketorder::setRange(const int16_t& range) {
	m_range = range;
}

int16_t marketorder::getRange() const {
	return (m_range);
}

void marketorder::setOrderID(const int64_t& orderID) {
	m_orderID = orderID;
}

int64_t marketorder::getOrderID() const {
	return (m_orderID);
}

void marketorder::setVolEntered(const int32_t& volEntered) {
	m_volEntered = volEntered;
}

int32_t marketorder::getVolEntered() const {
	return (m_volEntered);
}

void marketorder::setMinVolume(const int32_t& minVolume) {
	m_minVolume = minVolume;
}

int32_t marketorder::getMinVolume() const {
	return (m_minVolume);
}

void marketorder::setBid(const bool& bid) {
	m_bid = bid;
}

bool marketorder::getBid() const {
	return (m_bid);
}

void marketorder::setIssueDate(const int64_t& issueDate) {
	m_issueDate = issueDate;
}

int64_t marketorder::getIssueDate() const {
	return (m_issueDate);
}

int64_t marketorder::getIssueDateUNIX() const {
	return ((m_issueDate / 10000000) -  11644473600LL);
}

void marketorder::setDuration(const int16_t& duration) {
	m_duration = duration;
}

int16_t marketorder::getDuration() const {
	return (m_duration);
}

void marketorder::setStationID(const int32_t& stationID) {
	m_stationID = stationID;
}

int32_t marketorder::getStationID() const {
	return (m_stationID);
}

void marketorder::setRegionID(const int32_t& regionID) {
	m_regionID = regionID;
}

int32_t marketorder::getRegionID() const {
	return (m_regionID);
}

void marketorder::setSolarSystemID(const int32_t& solarSystemID) {
	m_solarSystemID = solarSystemID;
}

int32_t marketorder::getSolarSystemID() const {
	return (m_solarSystemID);
}

void marketorder::setJumps(const int32_t& jumps) {
	m_jumps = jumps;
}

int32_t marketorder::getJumps() const {
	return (m_jumps);
}


marketorder* marketorder::create(python::pydbrow& row) {

	marketorder* object = new marketorder();
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

	pyBase = row.dict()->at("range");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setRange(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("orderID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setOrderID(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("volEntered");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setVolEntered(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("minVolume");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setMinVolume(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("bid");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asBool()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setBid(pyBase->asBool()->value());
	}

	pyBase = row.dict()->at("issueDate");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setIssueDate(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("duration");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setDuration(pyBase->asInt()->value());
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

	pyBase = row.dict()->at("regionID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setRegionID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("solarSystemID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setSolarSystemID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("jumps");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setJumps(pyBase->asInt()->value());
	}

	return (object);
}

} /* namespace model */

} /* namespace evetools */

