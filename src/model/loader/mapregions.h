//==========================================================================
// Name        : mapregions.h
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MODEL_LOADER_MAPREGIONS_H_
#define EVETOOLS_MODEL_LOADER_MAPREGIONS_H_

#include "../../marshal/reader.h"
#include "../mapregion.h"

namespace evetools {

namespace model {

namespace loader {

class mapregions {

public:

	typedef std::vector<model::mapregion*> storage_type;
	typedef storage_type::iterator iterator;
	typedef storage_type::const_iterator const_iterator;

	mapregions(const std::string&);
	virtual ~mapregions();

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	size_t size() const;

private:

	mapregions();
	mapregions(const mapregions&);

	void validate(const python::pybase&);
	void load(const python::pybase&);

	storage_type m_list;

};

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_LOADER_MAPREGIONS_H_ */
