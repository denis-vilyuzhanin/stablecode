

file(GLOB SOURCES . *.cpp)
add_executable(passed.tests ${SOURCES})
target_link_libraries(passed.tests stablecode stablecode-main)	
