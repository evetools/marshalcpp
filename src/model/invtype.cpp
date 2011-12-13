//==========================================================================
// Name        : invtype.cpp
// Version     : 0.0.1
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#include "invtype.h"


namespace evetools {

namespace model {


invtype::invtype( const int32_t& typeID, const int32_t& groupID, const std::string& typeName, const std::string& description, const int32_t& graphicID, const double& radius, const double& mass, const double& volume, const double& capacity, const int32_t& portionSize, const uint8_t& raceID, const int64_t& basePrice, const bool& published, const int32_t& marketGroupID, const double& chanceOfDuplicating, const int32_t& soundID, const int32_t& iconID, const int32_t& dataID) : 
m_typeID(typeID), m_groupID(groupID), m_typeName(typeName), m_description(description), m_graphicID(graphicID), m_radius(radius), m_mass(mass), m_volume(volume), m_capacity(capacity), m_portionSize(portionSize), m_raceID(raceID), m_basePrice(basePrice), m_published(published), m_marketGroupID(marketGroupID), m_chanceOfDuplicating(chanceOfDuplicating), m_soundID(soundID), m_iconID(iconID), m_dataID(dataID){
}

invtype::~invtype() {
}

invtype::invtype() : 
m_typeID(0), m_groupID(0), m_typeName(std::string("")), m_description(std::string("")), m_graphicID(0), m_radius(0.0f), m_mass(0.0f), m_volume(0.0f), m_capacity(0.0f), m_portionSize(0), m_raceID(0), m_basePrice(0), m_published(false), m_marketGroupID(0), m_chanceOfDuplicating(0.0f), m_soundID(0), m_iconID(0), m_dataID(0) {
}

void invtype::setTypeID(const int32_t& typeID) {
	m_typeID = typeID;
}

int32_t invtype::getTypeID() const {
	return (m_typeID);
}

void invtype::setGroupID(const int32_t& groupID) {
	m_groupID = groupID;
}

int32_t invtype::getGroupID() const {
	return (m_groupID);
}

void invtype::setTypeName(const std::string& typeName) {
	m_typeName = typeName;
}

std::string invtype::getTypeName() const {
	return (m_typeName);
}

void invtype::setDescription(const std::string& description) {
	m_description = description;
}

std::string invtype::getDescription() const {
	return (m_description);
}

void invtype::setGraphicID(const int32_t& graphicID) {
	m_graphicID = graphicID;
}

int32_t invtype::getGraphicID() const {
	return (m_graphicID);
}

void invtype::setRadius(const double& radius) {
	m_radius = radius;
}

double invtype::getRadius() const {
	return (m_radius);
}

void invtype::setMass(const double& mass) {
	m_mass = mass;
}

double invtype::getMass() const {
	return (m_mass);
}

void invtype::setVolume(const double& volume) {
	m_volume = volume;
}

double invtype::getVolume() const {
	return (m_volume);
}

void invtype::setCapacity(const double& capacity) {
	m_capacity = capacity;
}

double invtype::getCapacity() const {
	return (m_capacity);
}

void invtype::setPortionSize(const int32_t& portionSize) {
	m_portionSize = portionSize;
}

int32_t invtype::getPortionSize() const {
	return (m_portionSize);
}

void invtype::setRaceID(const uint8_t& raceID) {
	m_raceID = raceID;
}

uint8_t invtype::getRaceID() const {
	return (m_raceID);
}

void invtype::setBasePrice(const int64_t& basePrice) {
	m_basePrice = basePrice;
}

int64_t invtype::getBasePrice() const {
	return (m_basePrice);
}

double invtype::getBasePriceInISK() const {
	return ((double)m_basePrice / 10000.0f);
}

void invtype::setPublished(const bool& published) {
	m_published = published;
}

bool invtype::getPublished() const {
	return (m_published);
}

void invtype::setMarketGroupID(const int32_t& marketGroupID) {
	m_marketGroupID = marketGroupID;
}

int32_t invtype::getMarketGroupID() const {
	return (m_marketGroupID);
}

void invtype::setChanceOfDuplicating(const double& chanceOfDuplicating) {
	m_chanceOfDuplicating = chanceOfDuplicating;
}

double invtype::getChanceOfDuplicating() const {
	return (m_chanceOfDuplicating);
}

void invtype::setSoundID(const int32_t& soundID) {
	m_soundID = soundID;
}

int32_t invtype::getSoundID() const {
	return (m_soundID);
}

void invtype::setIconID(const int32_t& iconID) {
	m_iconID = iconID;
}

int32_t invtype::getIconID() const {
	return (m_iconID);
}

void invtype::setDataID(const int32_t& dataID) {
	m_dataID = dataID;
}

int32_t invtype::getDataID() const {
	return (m_dataID);
}


invtype* invtype::create(python::pydbrow& row) {

	invtype* object = new invtype();
	const python::pybase* pyBase = NULL;

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

	pyBase = row.dict()->at("groupID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setGroupID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("typeName");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asBuffer()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		if (pyBase->asBuffer()->size() > 0) {
			object->setTypeName(pyBase->asBuffer()->str());
		}
	}

	pyBase = row.dict()->at("description");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asBuffer()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		if (pyBase->asBuffer()->size() > 0) {
			object->setDescription(pyBase->asBuffer()->str());
		}
	}

	pyBase = row.dict()->at("graphicID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setGraphicID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("radius");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setRadius(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("mass");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setMass(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("volume");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setVolume(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("capacity");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setCapacity(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("portionSize");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setPortionSize(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("raceID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asUInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setRaceID(pyBase->asUInt()->value());
	}

	pyBase = row.dict()->at("basePrice");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asLong()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setBasePrice(pyBase->asLong()->value());
	}

	pyBase = row.dict()->at("published");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asBool()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setPublished(pyBase->asBool()->value());
	}

	pyBase = row.dict()->at("marketGroupID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setMarketGroupID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("chanceOfDuplicating");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setChanceOfDuplicating(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("soundID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setSoundID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("iconID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setIconID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("dataID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setDataID(pyBase->asInt()->value());
	}

	return (object);
}

} /* namespace model */

} /* namespace evetools */

