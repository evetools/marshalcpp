//==========================================================================
// Name        : marketorders.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MODEL_LOADER_MARKETORDERS_H_
#define EVETOOLS_MODEL_LOADER_MARKETORDERS_H_

#include "../../marshal/reader.h"
#include "../marketorder.h"

namespace evetools {

namespace model {

namespace loader {

class marketorders {

public:

	typedef std::vector<model::marketorder*> storage_type;
	typedef storage_type::iterator iterator;
	typedef storage_type::const_iterator const_iterator;

	marketorders(const std::string&);
	virtual ~marketorders();

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	size_t size() const;

private:

	marketorders();
	marketorders(const marketorders&);

	void validate(const python::pybase&);
	void load(const python::pybase&);
	void loadOrders(const python::pydbrowlist& rowlist);

	storage_type m_list;

	uint32_t m_regionID;

	uint32_t m_typeID;

	uint64_t m_timestamp;


};

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_LOADER_MARKETORDERS_H_ */
