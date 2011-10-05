//==========================================================================
// Name        : main.cpp
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

#include <marshal/reader.h>

int main(int argc, char** argv) {

	if (argc == 1) {
		std::cout << "Usage: " << argv[0] << " file" << std::endl;
		return (EXIT_FAILURE);
	}

	marshal::reader* reader = NULL;
	python::pybase* py = NULL;
	marshal::dumpvisitor visitor;

	try {
		reader = new marshal::reader(argv[1]);
		py = reader->read();

		if (reader) {
			delete (reader);
		}

		py->visit(visitor);
		py->decRef();

	} catch (std::exception& e) {

		std::cout << "ERROR - " << e.what() << std::endl;

		if (reader) {
			delete (reader);
		}

		if (py) {
			delete (py);
		}

		return (EXIT_FAILURE);
	}

	if (reader) {
		delete (reader);
	}

	if (py) {
		delete (py);
	}

	return (EXIT_SUCCESS);
}

