#pragma once

#include "lua.hpp"
#include <memory>
#include <string>

class LuaWrapper {
public:
	LuaWrapper()
	: L(luaL_newstate()) {}
	~LuaWrapper();

	bool from_file(const std::string& filename);
	bool from_string(const std::string& script);

	std::string load_field(const std::string& table, const std::string& key);

	bool load_global_as_bool(const std::string& variable);
	double load_global_as_double(const std::string& variable);
	int load_global_as_int(const std::string& variable);
	std::string load_global_as_str(const std::string& variable);

	std::string dump_stack() const;
	std::string error_msg() const { return error_msg_; }

private:
	lua_State *L;
	std::string error_msg_ = "No error.";
};
