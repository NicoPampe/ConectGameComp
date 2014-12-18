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
T Lua::load(const std::string &variable_name) {
	
	T result;
	if (gettostack(variable_name)) {
		result = load<T>(variable_name);
	}
	else {
		result = getdefault(variable_name);
		
	}
}

bool Lua::gettostack(const std::string &variable_name) {
	level = 0;
	std::string var = "";
	for (unsigned int i = 0; i < variable_name.size(); i++) 
	{
		if (variable_name.at(i) == '.') {
			if (level == 0) {
				lua_getglobal(L, var.c_str());
			}
			else {
				lua_getfield(L, -1, var.c_str());
			}

			if (lua_isnil(L, -1)) {
				return false;
			}
			else {
				var = "";
				level++;
			}
		}
		else {
			var += variable_name.at(i);
		}
	}
	if (level == 0) {
		lua_getglobal(L, var.c_str());
	}
	else {
		lua_getfield(L, -1, var.c_str());
	}
	if (lua_isnil(L, -1)) {
		return false;
	}
	return true;
}