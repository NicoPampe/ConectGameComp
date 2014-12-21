#include "LuaWrapper.hpp"
#include <iostream>
#include <string>

int main() {
	// We need a script with globals, functions, and tables.
	const std::string script_text =
		"a = {}\n"                         // Table shenanigans.
		"a.a = a\n"                        // Table within a table.
		"a.b = 5.4\n"                      // Number within a table.
		"a.c = nil\n"                      // The Nil value ...
		"a.d1 = false\n"                   // Both values of a boolean.
		"a.d2 = true\n"
		"a.e = \"maybe a string.\"\n"      // An ordinary string.
		"a[1] = \"probably a string.\"\n"  // An integer index.
		"\n"
		"some_number = 5.4\n"              // See above.
		"something_nil = nil\n"
		"some_bool = false\n"
		"some_other_bool = true\n"
		"some_string = \"totally a string\"\n"
		"-- something_not_defined\n"
		"\n"
		"function foo(x)\n"
		"    return x * x\n"
		"end\n"
		"\n";

	std::cout << "Using script: \n"
	          << "========================\n" << script_text
	          << "========================\n"   << std::endl;

	LuaWrapper script;
	if (!script.from_string(script_text)) {
		std::cerr << "Something went wrong when parsing the above test script.\n";
		std::cerr << script.error_msg() << std::endl;
	}

	std::cout << "Stack Dump\n"
		<<       "----------\n"
		<< script.dump_stack() << std::endl;

	return 0;
}
