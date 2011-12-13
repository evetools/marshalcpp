//==========================================================================
// Name        : markethistory.h
// Version     : 0.0.2
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#ifndef EVETOOLS_MODEL_LOADER_MARKETHISTORY_H_
#define EVETOOLS_MODEL_LOADER_MARKETHISTORY_H_

#include "../../marshal/reader.h"
#include "../markethistory.h"

namespace evetools {

namespace model {

namespace loader {

class markethistory {

public:

	typedef std::vector<model::markethistory*> storage_type;
	typedef storage_type::iterator iterator;
	typedef storage_type::const_iterator const_iterator;

	markethistory(const std::string&);
	virtual ~markethistory();

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	size_t size() const;

private:

	markethistory();
	markethistory(const markethistory&);

	void validate(const python::pybase&);
	void load(const python::pybase&);

	storage_type m_list;

	uint32_t m_regionID;

	uint32_t m_typeID;

};

} /* namespace loader */

} /* namespace model */

} /* namespace evetools */

#endif /* EVETOOLS_MODEL_LOADER_MARKETHISTORY_H_ */
