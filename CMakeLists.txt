cmake_minimum_required(VERSION 2.8.3)

set(PROJECT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(INCLUDE_DIRECTORIES "include")

include_directories(${INCLUDE_DIRECTORIES})

add_subdirectory("./src/cisim")
