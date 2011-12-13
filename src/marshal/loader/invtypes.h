//==========================================================================
// Name        : invtypes.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_LOADER_INVTYPES_H_
#define EVETOOLS_MARSHAL_LOADER_INVTYPES_H_

#include "../reader.h"
#include "csvvisitor.h"

namespace evetools {

namespace marshal {

namespace loader {

class invtypes {

public:

	invtypes(const std::string&);
	virtual ~invtypes();

private:

	csvvisitor* m_visitor;

	invtypes();
	invtypes(const invtypes&);

	void validate(const python::pybase&);
	void load(const python::pybase&);

};

} /* namespace loader */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_LOADER_INVTYPES_H_ */
