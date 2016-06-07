cmake_minimum_required(VERSION 2.8.11)

# Constants
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_NAME "Circuit Simulator library")
set(TARGET_NAME "cisim")

# Project
project(${PROJECT_NAME} CXX)

# Build output directories.
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)

# Source files.
set(SOURCES
	./src/circuit.cpp
	./src/bit.cpp
	./src/circuitbuilder.cpp
	./src/nodes/node.cpp
	./src/nodes/nodefactory.cpp
	./src/nodes/noderegistrar.cpp
	./src/nodes/neutralnode.cpp
	./src/exceptions/invalidcircuitfileformat.cpp)
	
# Includes
include_directories(${PROJECT_DIR}/include)

# Binaries
add_library(${TARGET_NAME} STATIC ${SOURCES})

# This somehow enables c++11.
target_compile_features(${TARGET_NAME} PRIVATE cxx_range_for)


#########################################
## libraries
#########################################
# NOMIS header only library
target_include_directories(${TARGET_NAME} PRIVATE "./lib/libnomis/include")
