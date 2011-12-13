//==========================================================================
// Name        : mapregion.cpp
// Version     : 0.0.3
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#include "mapregion.h"


namespace evetools {

namespace model {


mapregion::mapregion( const int32_t& regionID, const std::string& regionName, const std::string& description, const int32_t& factionID, const double& x, const double& y, const double& z, const double& radius, const double& xMin, const double& xMax, const double& yMin, const double& yMax, const double& zMin, const double& zMax) : 
m_regionID(regionID), m_regionName(regionName), m_description(description), m_factionID(factionID), m_x(x), m_y(y), m_z(z), m_radius(radius), m_xMin(xMin), m_xMax(xMax), m_yMin(yMin), m_yMax(yMax), m_zMin(zMin), m_zMax(zMax){
}

mapregion::~mapregion() {
}

mapregion::mapregion() : 
m_regionID(0), m_regionName(std::string("")), m_description(std::string("")), m_factionID(0), m_x(0.0f), m_y(0.0f), m_z(0.0f), m_radius(0.0f), m_xMin(0.0f), m_xMax(0.0f), m_yMin(0.0f), m_yMax(0.0f), m_zMin(0.0f), m_zMax(0.0f) {
}

void mapregion::setRegionID(const int32_t& regionID) {
	m_regionID = regionID;
}

int32_t mapregion::getRegionID() const {
	return (m_regionID);
}

void mapregion::setRegionName(const std::string& regionName) {
	m_regionName = regionName;
}

std::string mapregion::getRegionName() const {
	return (m_regionName);
}

void mapregion::setDescription(const std::string& description) {
	m_description = description;
}

std::string mapregion::getDescription() const {
	return (m_description);
}

void mapregion::setFactionID(const int32_t& factionID) {
	m_factionID = factionID;
}

int32_t mapregion::getFactionID() const {
	return (m_factionID);
}

void mapregion::setX(const double& x) {
	m_x = x;
}

double mapregion::getX() const {
	return (m_x);
}

void mapregion::setY(const double& y) {
	m_y = y;
}

double mapregion::getY() const {
	return (m_y);
}

void mapregion::setZ(const double& z) {
	m_z = z;
}

double mapregion::getZ() const {
	return (m_z);
}

void mapregion::setRadius(const double& radius) {
	m_radius = radius;
}

double mapregion::getRadius() const {
	return (m_radius);
}

void mapregion::setXMin(const double& xMin) {
	m_xMin = xMin;
}

double mapregion::getXMin() const {
	return (m_xMin);
}

void mapregion::setXMax(const double& xMax) {
	m_xMax = xMax;
}

double mapregion::getXMax() const {
	return (m_xMax);
}

void mapregion::setYMin(const double& yMin) {
	m_yMin = yMin;
}

double mapregion::getYMin() const {
	return (m_yMin);
}

void mapregion::setYMax(const double& yMax) {
	m_yMax = yMax;
}

double mapregion::getYMax() const {
	return (m_yMax);
}

void mapregion::setZMin(const double& zMin) {
	m_zMin = zMin;
}

double mapregion::getZMin() const {
	return (m_zMin);
}

void mapregion::setZMax(const double& zMax) {
	m_zMax = zMax;
}

double mapregion::getZMax() const {
	return (m_zMax);
}


mapregion* mapregion::create(python::pydbrow& row) {

	mapregion* object = new mapregion();
	const python::pybase* pyBase = NULL;

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

	pyBase = row.dict()->at("regionName");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asBuffer()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		if (pyBase->asBuffer()->size() > 0) {
			object->setRegionName(pyBase->asBuffer()->str());
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

	pyBase = row.dict()->at("factionID");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asInt()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setFactionID(pyBase->asInt()->value());
	}

	pyBase = row.dict()->at("x");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setX(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("y");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setY(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("z");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setZ(pyBase->asDouble()->value());
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

	pyBase = row.dict()->at("xMin");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setXMin(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("xMax");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setXMax(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("yMin");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setYMin(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("yMax");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setYMax(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("zMin");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setZMin(pyBase->asDouble()->value());
	}

	pyBase = row.dict()->at("zMax");
	if (!pyBase) {
		throw std::runtime_error("Parsing DB Row.");
	}
	if (!pyBase->isNone()) {
		if (!pyBase->asDouble()) {
			throw std::runtime_error("Parsing DB Row.");
		}
		object->setZMax(pyBase->asDouble()->value());
	}

	return (object);
}

} /* namespace model */

} /* namespace evetools */

