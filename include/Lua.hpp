#pragma once

#include <string>

extern "C" struct lua_State;

class Lua {
public:
	Lua(const std::string &filename);
	~Lua();

	template<typename T>
	T load();
private:
	lua_State *L;
};