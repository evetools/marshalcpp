//==========================================================================
// Name        : mapregion.h
// Version     : 0.0.2
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#ifndef EVETOOLS_MODEL_MAPREGION_H_
#define EVETOOLS_MODEL_MAPREGION_H_

#include "../python/py.h"


namespace evetools {

namespace model {


class mapregion {

public:
	mapregion();
	mapregion( const int32_t& regionID, const std::string& regionName, const std::string& description, const int32_t& factionID, const double& x, const double& y, const double& z, const double& radius, const double& xMin, const double& xMax, const double& yMin, const double& yMax, const double& zMin, const double& zMax );
	~mapregion();

	static mapregion* create(python::pydbrow&);

	void setRegionID(const int32_t& regionID);
	int32_t getRegionID() const;
	void setRegionName(const std::string& regionName);
	std::string getRegionName() const;
	void setDescription(const std::string& description);
	std::string getDescription() const;
	void setFactionID(const int32_t& factionID);
	int32_t getFactionID() const;
	void setX(const double& x);
	double getX() const;
	void setY(const double& y);
	double getY() const;
	void setZ(const double& z);
	double getZ() const;
	void setRadius(const double& radius);
	double getRadius() const;
	void setXMin(const double& xMin);
	double getXMin() const;
	void setXMax(const double& xMax);
	double getXMax() const;
	void setYMin(const double& yMin);
	double getYMin() const;
	void setYMax(const double& yMax);
	double getYMax() const;
	void setZMin(const double& zMin);
	double getZMin() const;
	void setZMax(const double& zMax);
	double getZMax() const;

private:

	int32_t m_regionID;
	std::string m_regionName;
	std::string m_description;
	int32_t m_factionID;
	double m_x;
	double m_y;
	double m_z;
	double m_radius;
	double m_xMin;
	double m_xMax;
	double m_yMin;
	double m_yMax;
	double m_zMin;
	double m_zMax;

}; /* class mapregion */


} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_MAPREGION_H_ */

