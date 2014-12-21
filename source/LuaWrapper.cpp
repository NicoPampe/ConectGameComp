#include "LuaWrapper.hpp"
#include "lua.hpp"

#include <sstream>

bool LuaWrapper::from_file(const std::string& filename) {
	if (luaL_dofile(L, filename.c_str())) {
		error_msg_ = lua_tostring(L, -1);
		return false;
	}
	return true;
}

bool LuaWrapper::from_string(const std::string& script) {
	int error = luaL_loadstring(L, script.c_str());
	if (error) {
		error_msg_ = lua_tostring(L, -1);
		return false;
	}
	return true;
}

LuaWrapper::~LuaWrapper() {
	lua_close(L);
}

std::string LuaWrapper::load_field(const std::string& table, const std::string& key) {
	lua_getglobal(L, table.c_str());
	if (!lua_istable(L, -1)) {
		// Error: 'table' isn't actually a table.
		return "(null)";
	}
	lua_getfield(L, -1, key.c_str());
	const char *str = lua_tostring(L, -1);
	return str != nullptr ? str : "(null)";
}

bool LuaWrapper::load_global_as_bool(const std::string& variable) {
	lua_getglobal(L, variable.c_str());
	if (!lua_isboolean(L, -1)) {
		// TODO: Error: expected 'variable' to be a boolean!
		return false;
	}
	return lua_toboolean(L, -1) != 0;
}

double LuaWrapper::load_global_as_double(const std::string& variable) {
	lua_getglobal(L, variable.c_str());
	if (!lua_isnumber(L, -1)) {
		// TODO: Error: expected 'variable' to be a float!
		return 0.0;
	}
	return lua_tonumber(L, -1);
}

int LuaWrapper::load_global_as_int(const std::string& variable) {
	lua_getglobal(L, variable.c_str());
	if (!lua_isnumber(L, -1)) {
		// TODO: Error: expected 'variable' to be an integer!
		return 0;
	}
	return lua_tointeger(L, -1);
}

std::string LuaWrapper::load_global_as_str(const std::string& variable) {
	lua_getglobal(L, variable.c_str());
	const char *str = lua_tostring(L, -1);
	return str != nullptr ? "(null)" : str;
}

std::string LuaWrapper::dump_stack() const {
	std::stringstream ss;
	int top = lua_gettop(L);
	for (int i = 1; i <= top; i += 1) {
		switch (lua_type(L, i)) {
			case LUA_TSTRING: {
				ss << i << "\t[string: " << lua_tostring(L, i) << "]";
				break;
			}
			case LUA_TBOOLEAN: {
				ss << i << "\t[boolean: " << (lua_toboolean(L, i) ? "true" : "false") << "]";
				break;
			}
			case LUA_TNUMBER: {
				ss << i << "\t[number: " << lua_tonumber(L, i) << "]";
				break;
			}
			default:
				ss << i << "\t[" << lua_typename(L, i) << "]";
				break;
		}
		ss << " ";
	}
	return ss.str();
}
