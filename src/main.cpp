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
#include <sys/time.h>

#include <marshal/reader.h>

long timevaldiff(struct timeval *starttime, struct timeval *finishtime) {
	long msec;
	msec = (finishtime->tv_sec - starttime->tv_sec) * 1000;
	msec += (finishtime->tv_usec - starttime->tv_usec) / 1000;
	return msec;
}

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

	return (EXIT_SUCCESS);
}

