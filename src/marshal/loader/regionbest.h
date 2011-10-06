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

#ifndef EVETOOLS_MARSHAL_LOADER_REGIONBEST_H_
#define EVETOOLS_MARSHAL_LOADER_REGIONBEST_H_

#include "../reader.h"
#include "csvvisitor.h"

namespace evetools {

namespace marshal {

namespace loader {

class regionbest {

public:

	regionbest(const std::string&);
	virtual ~regionbest();

private:

	uint32_t m_regionID;

	csvvisitor* m_visitor;

	regionbest();
	regionbest(const regionbest&);

	void validate(const python::pybase&);
	void load(const python::pybase&);

};

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_LOADER_REGIONBEST_H_ */
