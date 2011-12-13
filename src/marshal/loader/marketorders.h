//==========================================================================
// Name        : marketorders.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_LOADER_MARKETORDERS_H_
#define EVETOOLS_MARSHAL_LOADER_MARKETORDERS_H_

#include "../reader.h"
#include "csvvisitor.h"

namespace evetools {

namespace marshal {

namespace loader {

class marketorders {

public:

	marketorders(const std::string&);
	virtual ~marketorders();

private:

	uint32_t m_regionID;

	uint32_t m_typeID;

	csvvisitor* m_visitor;

	marketorders();
	marketorders(const marketorders&);

	void validate(const python::pybase&);
	void load(const python::pybase&);
	void loadOrders(const python::pydbrowlist&);

};

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_LOADER_MARKETORDERS_H_ */
