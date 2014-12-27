cmake_minimum_required (VERSION 2.8)
project (ConnectGameComp)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

# Finds the SFML libraries and sets them to SFML_LIBRARYES.
# Also finds the include directory and sets it to SFML_INCLUDE_DIR.
find_package(SFML 2 REQUIRED
	COMPONENTS graphics window system main
)

set(LUA_LIB lua-5.2)

# We want Lua as a DLL, not static.
add_definitions(-DLUA_BUILD_AS_DLL)
add_subdirectory(lua)

include_directories(
	include              # Primary include dir for the project
	lua/src              # Lua headers
	unnamed_lua_binder   # Lua Wrapper header
	${SFML_INCLUDE_DIR}  # SFML headers
)

add_executable(ConnectGameComp
		source/main.cpp

		source/Game.cpp
		source/BattleScene.cpp
		source/BoardFigure.cpp
		source/Game.cpp
		source/OverWorld.cpp
		source/OverWorldFigure.cpp
		source/PartyFigure.cpp
		source/SpriteManager.cpp

		include/BattleScene.hpp
		include/BoardFigure.hpp
		include/Common.hpp
		include/Game.hpp
		include/OverWorld.hpp
		include/OverWorldFigure.hpp
		include/PartyFigure.hpp
		include/SpriteManager.hpp
		include/Tile.hpp

		unnamed_lua_binder/LuaScript.cpp
		unnamed_lua_binder/LuaScript.hpp
)

target_link_libraries(
	ConnectGameComp
	${SFML_LIBRARIES}
	${LUA_LIB}         # Defined in lua/CMakeLists.txt
)

# Copy the resources over to the CMAKE_BINARY_DIR.
add_custom_command(
	TARGET ConnectGameComp PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources
)
