cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Game VERSION 1.0 LANGUAGES CXX)

set(LIBS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")
include_directories("${LIBS_PATH}/include")
include_directories("${LIBS_PATH}/include/pdcurses")
link_directories("${LIBS_PATH}/windows/pdcurses")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(game)