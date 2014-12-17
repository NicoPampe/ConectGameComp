cmake_minimum_required (VERSION 2.6)
project (ConnectGameComp)

# Setup / find SFML libs.
if(WIN32)
	set(SFML_LIBS
		debug sfml-main-d.lib
		debug sfml-graphics-d.lib
		debug sfml-window-d.lib
		debug sfml-system-d.lib

		optimized sfml-main.lib
		optimized sfml-graphics.lib
		optimized sfml-window.lib
		optimized sfml-system.lib
	)
else()
	find_library(SFML_GRAPHICS sfml-graphics)
	find_library(SFML_SYSTEM sfml-system)
	find_library(SFML_WINDOW sfml-window)
	set(SFML_LIBS ${SFML_GRAPHICS} ${SFML_SYSTEM} ${SFML_WINDOW})
endif()

include_directories(include)

add_executable(ConnectGameComp
		WIN32
		source/main.cpp
		source/Game.cpp
		source/OverWorld.cpp

		include/Common.hpp
		include/Game.hpp
		include/OverWorld.hpp
)

target_link_libraries(
	ConnectGameComp
	${SFML_LIBS}
)

