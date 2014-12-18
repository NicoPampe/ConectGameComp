#include "Lua.hpp"

extern "C" {
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

Lua::Lua(const std::string &filename) {
	L = luaL_newstate();
	luaL_dofile(L, filename.c_str());
}

Lua::~Lua() {
	lua_close(L);
}

template<typename T>
T Lua::load() {
	//lua_load(L);
}
