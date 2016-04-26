cmake_minimum_required (VERSION 3.0)
project (stablecode)

include(${CMAKE_CURRENT_SOURCE_DIR}/config.cmake)

add_subdirectory (src)
#add_subdirectory(test)
add_subdirectory(baseline)


