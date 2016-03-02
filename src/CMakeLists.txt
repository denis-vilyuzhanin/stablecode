

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include" )
file(GLOB SOURCES . *.cpp)
list(REMOVE_ITEM SOURCES "main.cpp")

add_library(stablecode ${SOURCES})
target_include_directories (stablecode PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_library(stablecode-main main.cpp)
target_link_libraries(stablecode-main stablecode)	
