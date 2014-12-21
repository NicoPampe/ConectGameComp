
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lua/src)

add_executable(LuaWrapperTests
	LuaWrapperTests.cpp

	${CMAKE_SOURCE_DIR}/source/LuaWrapper.cpp
	${CMAKE_SOURCE_DIR}/include/LuaWrapper.hpp
)

target_link_libraries(
	LuaWrapperTests
	${LUA_LIB}
)
