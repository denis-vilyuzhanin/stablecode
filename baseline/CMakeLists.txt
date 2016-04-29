

macro(__stablecode__ module)
	file(GLOB SOURCES . *.cpp)
	add_executable(${module}.tests ${SOURCES})
	target_link_libraries(${module}.tests stablecode stablecode-main)
endmacro(__stablecode__)	

add_subdirectory(passed)
add_subdirectory(failed)
add_subdirectory(undefined)