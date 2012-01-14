//==========================================================================
// Name        : invtype.h
// Version     : 0.0.3
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#ifndef EVETOOLS_MODEL_INVTYPE_H_
#define EVETOOLS_MODEL_INVTYPE_H_

#include "../python/py.h"


namespace evetools {

namespace model {


class invtype {

public:
	invtype();
	invtype( const int32_t& typeID, const int32_t& groupID, const std::string& typeName, const std::string& description, const int32_t& graphicID, const double& radius, const double& mass, const double& volume, const double& capacity, const int32_t& portionSize, const uint8_t& raceID, const int64_t& basePrice, const bool& published, const int32_t& marketGroupID, const double& chanceOfDuplicating, const int32_t& soundID, const int32_t& iconID, const int32_t& dataID );
	~invtype();

	static invtype* create(python::pydbrow&);

	void setTypeID(const int32_t& typeID);
	int32_t getTypeID() const;
	void setGroupID(const int32_t& groupID);
	int32_t getGroupID() const;
	void setTypeName(const std::string& typeName);
	std::string getTypeName() const;
	void setDescription(const std::string& description);
	std::string getDescription() const;
	void setGraphicID(const int32_t& graphicID);
	int32_t getGraphicID() const;
	void setRadius(const double& radius);
	double getRadius() const;
	void setMass(const double& mass);
	double getMass() const;
	void setVolume(const double& volume);
	double getVolume() const;
	void setCapacity(const double& capacity);
	double getCapacity() const;
	void setPortionSize(const int32_t& portionSize);
	int32_t getPortionSize() const;
	void setRaceID(const uint8_t& raceID);
	uint8_t getRaceID() const;
	void setBasePrice(const int64_t& basePrice);
	int64_t getBasePrice() const;
	double getBasePriceInISK() const;
	void setPublished(const bool& published);
	bool getPublished() const;
	void setMarketGroupID(const int32_t& marketGroupID);
	int32_t getMarketGroupID() const;
	void setChanceOfDuplicating(const double& chanceOfDuplicating);
	double getChanceOfDuplicating() const;
	void setSoundID(const int32_t& soundID);
	int32_t getSoundID() const;
	void setIconID(const int32_t& iconID);
	int32_t getIconID() const;
	void setDataID(const int32_t& dataID);
	int32_t getDataID() const;

private:

	int32_t m_typeID;
	int32_t m_groupID;
	std::string m_typeName;
	std::string m_description;
	int32_t m_graphicID;
	double m_radius;
	double m_mass;
	double m_volume;
	double m_capacity;
	int32_t m_portionSize;
	uint8_t m_raceID;
	int64_t m_basePrice;
	bool m_published;
	int32_t m_marketGroupID;
	double m_chanceOfDuplicating;
	int32_t m_soundID;
	int32_t m_iconID;
	int32_t m_dataID;

}; /* class invtype */


} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_INVTYPE_H_ */

