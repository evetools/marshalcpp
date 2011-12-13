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


markethistory::markethistory( const int64_t& historyDate, const int64_t& lowPrice, const int64_t& highPrice, const int64_t& avgPrice, const int64_t& volume, const int32_t& orders) : 
m_historyDate(historyDate), m_lowPrice(lowPrice), m_highPrice(highPrice), m_avgPrice(avgPrice), m_volume(volume), m_orders(orders){
}

markethistory::~markethistory() {
}

markethistory::markethistory() : 
m_historyDate(0), m_lowPrice(0), m_highPrice(0), m_avgPrice(0), m_volume(0), m_orders(0) {
}

void markethistory::setHistoryDate(const int64_t& historyDate) {
	m_historyDate = historyDate;
}

int64_t markethistory::getHistoryDate() const {
	return (m_historyDate);
}

int64_t markethistory::getHistoryDateUNIX() const {
	return ((m_historyDate / 10000000) -  11644473600LL);
}

void markethistory::setLowPrice(const int64_t& lowPrice) {
	m_lowPrice = lowPrice;
}

int64_t markethistory::getLowPrice() const {
	return (m_lowPrice);
}

double markethistory::getLowPriceInISK() const {
	return ((double)m_lowPrice / 10000.0f);
}

void markethistory::setHighPrice(const int64_t& highPrice) {
	m_highPrice = highPrice;
}

int64_t markethistory::getHighPrice() const {
	return (m_highPrice);
}

double markethistory::getHighPriceInISK() const {
	return ((double)m_highPrice / 10000.0f);
}

void markethistory::setAvgPrice(const int64_t& avgPrice) {
	m_avgPrice = avgPrice;
}

int64_t markethistory::getAvgPrice() const {
	return (m_avgPrice);
}

double markethistory::getAvgPriceInISK() const {
	return ((double)m_avgPrice / 10000.0f);
}

void markethistory::setVolume(const int64_t& volume) {
	m_volume = volume;
}

int64_t markethistory::getVolume() const {
	return (m_volume);
}

void markethistory::setOrders(const int32_t& orders) {
	m_orders = orders;
}

int32_t markethistory::getOrders() const {
	return (m_orders);
}


markethistory* markethistory::create(python::pydbrow& row) {

	markethistory* object = new markethistory();
	const python::pybase* pyBase = NULL;

	pyBase = row.dict()->at("historyDate");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setHistoryDate(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("lowPrice");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setLowPrice(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("highPrice");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setHighPrice(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("avgPrice");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setAvgPrice(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("volume");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setVolume(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("orders");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setOrders(pyBase->asInt()->value());
	}

	return (object);
}

} /* namespace model */

} /* namespace evetools */

