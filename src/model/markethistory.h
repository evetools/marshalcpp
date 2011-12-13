//==========================================================================
// Name        : markethistory.h
// Version     : 0.0.1
//==========================================================================

/**
* Copyright (C)2011 by Gregor Anders All rights reserved.
*
* This code is free software; you can redistribute it and/or modify it under
* the terms of the BSD license (see the file LICENSE.txt included with the
* distribution).
*/

#ifndef EVETOOLS_MODEL_MARKETHISTORY_H_
#define EVETOOLS_MODEL_MARKETHISTORY_H_

#include "../python/py.h"


namespace evetools {

namespace model {


class markethistory {

public:
	markethistory();
	markethistory( const int64_t& historyDate, const int64_t& lowPrice, const int64_t& highPrice, const int64_t& avgPrice, const int64_t& volume, const int32_t& orders );
	~markethistory();

	static markethistory* create(python::pydbrow&);

	void setHistoryDate(const int64_t& historyDate);
	int64_t getHistoryDate() const;
	int64_t getHistoryDateUNIX() const;
	void setLowPrice(const int64_t& lowPrice);
	int64_t getLowPrice() const;
	double getLowPriceInISK() const;
	void setHighPrice(const int64_t& highPrice);
	int64_t getHighPrice() const;
	double getHighPriceInISK() const;
	void setAvgPrice(const int64_t& avgPrice);
	int64_t getAvgPrice() const;
	double getAvgPriceInISK() const;
	void setVolume(const int64_t& volume);
	int64_t getVolume() const;
	void setOrders(const int32_t& orders);
	int32_t getOrders() const;

private:

	int64_t m_historyDate;
	int64_t m_lowPrice;
	int64_t m_highPrice;
	int64_t m_avgPrice;
	int64_t m_volume;
	int32_t m_orders;

}; /* class markethistory */


} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_MARKETHISTORY_H_ */

