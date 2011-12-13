//==========================================================================
// Name        : markethistory.h
// Version     : 0.0.3
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_LOADER_MARKETHISTORY_H_
#define EVETOOLS_MARSHAL_LOADER_MARKETHISTORY_H_

#include "../reader.h"
#include "csvvisitor.h"

namespace evetools {

namespace marshal {

namespace loader {

class markethistory {

public:

	markethistory(const std::string&);
	virtual ~markethistory();

private:

	uint32_t m_regionID;

	uint32_t m_typeID;

	csvvisitor* m_visitor;

	markethistory();
	markethistory(const markethistory&);

	void validate(const python::pybase&);
	void load(const python::pybase&);
	void loadEntry(const python::pydbrow& entry);

};

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_LOADER_MARKETHISTORY_H_ */
