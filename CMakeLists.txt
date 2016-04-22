cmake_minimum_required(VERSION 2.8.3)

# Constants
set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_NAME "Circuit Simulator")
set(EXECUTABLE_TARGET_NAME "CircuitSimulator")
set(INCLUDE_DIRECTORIES "include")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIR}/bin)

# Put all the source files into a variable.
file(GLOB_RECURSE sources ./src *.cpp *.h)

include_directories(${INCLUDE_DIRECTORIES})

# Project
project(${PROJECT_NAME} CXX)

# Executables
add_executable(${EXECUTABLE_TARGET_NAME} ${sources})

# This somehow enables c++11.
target_compile_features(${EXECUTABLE_TARGET_NAME} PRIVATE cxx_range_for)
