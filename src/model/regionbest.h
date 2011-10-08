//==========================================================================
// Name        : regionbest.h
// Version     : 0.0.1
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#ifndef EVETOOLS_MODEL_REGIONBEST_H_
#define EVETOOLS_MODEL_REGIONBEST_H_

#include "../python/py.h"


namespace evetools {

namespace model {


class regionbest {

public:
	regionbest();
	regionbest( const int64_t& price, const double& volRemaining, const int16_t& typeID, const int32_t& stationID );
	~regionbest();

	static regionbest* create(python::pydbrow&);

	void setPrice(const int64_t& price);
	int64_t getPrice() const;
	double getPriceInISK() const;
	void setVolRemaining(const double& volRemaining);
	double getVolRemaining() const;
	void setTypeID(const int16_t& typeID);
	int16_t getTypeID() const;
	void setStationID(const int32_t& stationID);
	int32_t getStationID() const;

private:

	int64_t m_price;
	double m_volRemaining;
	int16_t m_typeID;
	int32_t m_stationID;

}; /* class regionbest */


} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_REGIONBEST_H_ */

