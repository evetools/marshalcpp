//==========================================================================
// Name        : markethistory.cpp
// Version     : 0.0.1
//==========================================================================

/**
 * Copyright (C)2011 by Gregor Anders All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it under
 * the terms of the BSD license (see the file LICENSE.txt included with the
 * distribution).
 */

#include <cstdio>
#include <cstdlib>

#include <marshal/loader/markethistory.h>

int main(int argc, char** argv) {

	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return (EXIT_FAILURE);
	}

	evetools::marshal::loader::markethistory* loader = NULL;

	try {

		loader = new evetools::marshal::loader::markethistory(argv[1]);

	} catch (std::exception& e) {

		std::cout << "ERROR - " << e.what() << std::endl;

		if (loader) {
			delete (loader);
		}

		return (EXIT_FAILURE);
	}

	if (loader) {
		delete (loader);
	}

	return (EXIT_SUCCESS);
}
