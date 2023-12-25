cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Game VERSION 1.0 LANGUAGES CXX)

include_directories(include)
file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(game ${SOURCES})