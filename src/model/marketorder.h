//==========================================================================
// Name        : marketorder.h
// Version     : 0.0.1
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#ifndef EVETOOLS_MODEL_MARKETORDER_H_
#define EVETOOLS_MODEL_MARKETORDER_H_

#include "../python/py.h"


namespace evetools {

namespace model {


class marketorder {

public:
	marketorder();
	marketorder( const int64_t& price, const double& volRemaining, const int32_t& typeID, const int16_t& range, const int64_t& orderID, const int32_t& volEntered, const int32_t& minVolume, const bool& bid, const int64_t& issueDate, const int16_t& duration, const int32_t& stationID, const int32_t& regionID, const int32_t& solarSystemID, const int32_t& jumps );
	~marketorder();

	static marketorder* create(python::pydbrow&);

	void setPrice(const int64_t& price);
	int64_t getPrice() const;
	double getPriceInISK() const;
	void setVolRemaining(const double& volRemaining);
	double getVolRemaining() const;
	void setTypeID(const int32_t& typeID);
	int32_t getTypeID() const;
	void setRange(const int16_t& range);
	int16_t getRange() const;
	void setOrderID(const int64_t& orderID);
	int64_t getOrderID() const;
	void setVolEntered(const int32_t& volEntered);
	int32_t getVolEntered() const;
	void setMinVolume(const int32_t& minVolume);
	int32_t getMinVolume() const;
	void setBid(const bool& bid);
	bool getBid() const;
	void setIssueDate(const int64_t& issueDate);
	int64_t getIssueDate() const;
	int64_t getIssueDateUNIX() const;
	void setDuration(const int16_t& duration);
	int16_t getDuration() const;
	void setStationID(const int32_t& stationID);
	int32_t getStationID() const;
	void setRegionID(const int32_t& regionID);
	int32_t getRegionID() const;
	void setSolarSystemID(const int32_t& solarSystemID);
	int32_t getSolarSystemID() const;
	void setJumps(const int32_t& jumps);
	int32_t getJumps() const;

private:

	int64_t m_price;
	double m_volRemaining;
	int32_t m_typeID;
	int16_t m_range;
	int64_t m_orderID;
	int32_t m_volEntered;
	int32_t m_minVolume;
	bool m_bid;
	int64_t m_issueDate;
	int16_t m_duration;
	int32_t m_stationID;
	int32_t m_regionID;
	int32_t m_solarSystemID;
	int32_t m_jumps;

}; /* class marketorder */


} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_MARKETORDER_H_ */

