cmake_minimum_required(VERSION 2.8.11)

# Constants
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_NAME "Circuit Simulator")
set(EXECUTABLE_TARGET_NAME "CircuitSimulator")

# Project
project(${PROJECT_NAME} CXX)

# Build output directories.
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)

# Source files
set(SOURCES
	./src/main.cpp
	./src/main.h
	./src/cisim/circuit.cpp
	./src/cisim/circuit.h
	./src/cisim/circuitsimulator.cpp
	./src/cisim/circuitsimulator.h
	./src/cisim/nodes/node.cpp
	./src/cisim/nodes/node.h
	./src/cisim/nodes/nodefactory.cpp
	./src/cisim/nodes/nodefactory.h
	./src/cisim/nodes/noderegistrar.cpp
	./src/cisim/nodes/noderegistrar.h)

# Executables
add_executable(${EXECUTABLE_TARGET_NAME} ${SOURCES})

# This somehow enables c++11.
target_compile_features(${EXECUTABLE_TARGET_NAME} PRIVATE cxx_range_for)


#########################################
## libraries
#########################################
# NOMIS header only library
target_include_directories(${EXECUTABLE_TARGET_NAME} PRIVATE "./lib/libnomis/include")