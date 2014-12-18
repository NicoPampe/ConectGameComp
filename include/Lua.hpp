#pragma once

#ifndef LUA_H
#define LUA_H

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <string>
//#include <iostream>

extern "C" struct lua_State;

class Lua {
public:
	Lua(const std::string &filename);
	~Lua();

	bool gettostack(const std::string &variable_name);
	
	template<typename T>
	T load(const std::string &variable_name);

	template<typename T>
	T getdefault(const std::string &variable_name) {
		return 0;
	}
private:
	lua_State *L;
	int level;
};

// need to define one of the template class
template<>
inline std::string Lua::load<std::string>(const std::string &variable_name) {
	std::string s = "null";
	if (lua_isstring(L, -1)) {
		s = std::string(lua_tostring(L, -1));
	}
	else {
		// something went wrong
	}
	return s;
}

#endif LUA_H
