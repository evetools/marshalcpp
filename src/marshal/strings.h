//==========================================================================
// Name        : strings.h
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MARSHAL_STRINGS_H_
#define EVETOOLS_MARSHAL_STRINGS_H_

#include <string>
#include <map>

namespace evetools {

namespace marshal {

class strings {

public:
	strings();
	virtual ~strings();

	static const std::string get(unsigned int id);
	static bool has(unsigned int id);

private:

	static bool m_init;
	static std::map<unsigned int, std::string> m_strings;

	static void init();
	static void insert(unsigned int id, std::string string);
};

} /* namespace marshal */

} /* namespace evetools */

#endif /* EVETOOLS_MARSHAL_STRINGS_H_ */
