cmake_minimum_required(VERSION 2.6)

# Constants
set(PROJECT_NAME "Circuit Simulator")
set(EXECUTABLE_TARGET_NAME "CircuitSimulator")
file(GLOB_RECURSE sources ./ *.cpp *.h)

# Project
project(${PROJECT_NAME} CXX)

# Executables
add_executable(${EXECUTABLE_TARGET_NAME} ${sources})

# This somehow enables c++11.
target_compile_features(${EXECUTABLE_TARGET_NAME} PRIVATE cxx_range_for)