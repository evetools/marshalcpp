cmake_minimum_required( VERSION 2.6 FATAL_ERROR )

PROJECT( "evemarshal" CXX)

FIND_PACKAGE( "ZLIB" REQUIRED )

SET( BUILD_SHARED_LIBS ON )

SET( CMAKE_CXX_FLAGS "-Wno-long-long -Wall -Wextra -pedantic-errors -W -Wshadow -Wpointer-arith -Wcast-qual -Winline -Werror" )

SET( CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 ${CMAKE_C_FLAGS}" )

SET( CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_C_FLAGS}" )

SET ( CMAKE_VERBOSE_MAKEFILE FALSE ) 

INCLUDE_DIRECTORIES( "${PROJECT_BINARY_DIR}" )

ADD_SUBDIRECTORY( "src" )
