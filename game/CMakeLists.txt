cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Game VERSION 1.0 LANGUAGES CXX)

include_directories(include)
file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(game ${SOURCES})
target_link_libraries(game pdcurses.dll)

add_custom_command(
    TARGET game POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${LIBS_PATH}/windows/pdcurses/pdcurses.dll"
    $<TARGET_FILE_DIR:game>
)