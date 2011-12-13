//==========================================================================
// Name        : dbrow.h
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_GENERATOR_DBROW_H_
#define EVETOOLS_MARSHAL_GENERATOR_DBROW_H_

#include "../reader.h"

namespace evetools {

namespace marshal {

namespace generator {

class dbrow {

public:

	dbrow(const std::string& name, const python::pydbrow* row);
	virtual ~dbrow();

private:

	dbrow();
	dbrow(const dbrow&);

	void init();

	void createInclude();

	void createSource();

	const std::string& m_name;
	const python::pydbrow* m_row;

	std::stringstream m_include;
	std::stringstream m_source;

};

} /* namespace generator */

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_GENERATOR_DBROW_H_ */
