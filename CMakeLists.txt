cmake_minimum_required(VERSION 2.8.11)

# Constants
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_NAME "Circuit Simulator")
set(TARGET_NAME "CircuitSimulator")

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
	./src/circuitsimulator.cpp
	./src/circuitsimulator.h)

# Binaries
add_executable(${TARGET_NAME} ${SOURCES})

# This somehow enables c++11.
target_compile_features(${TARGET_NAME} PRIVATE cxx_range_for)


#########################################
## libraries
#########################################
# NOMIS header only library
target_include_directories(${TARGET_NAME} PRIVATE "./lib/libnomis/include")

# CISIM library
target_include_directories(${TARGET_NAME} PRIVATE "./lib/libcisim/include")
add_subdirectory("./lib/libcisim" "${CMAKE_BINARY_DIR}/libcisim")
target_link_libraries(${TARGET_NAME} -Wl,--whole-archive "cisim" -Wl,--no-whole-archive)
