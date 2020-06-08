#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include "container.h"

TEST_CASE(" dict->Get(\"test\") ok ") {
	Container<std::string, std::string> *dict = new Container<std::string, std::string>;
	dict->Set("test", "ok");

	std::cout << dict->Get("test") << "\n";

	REQUIRE(" dict->Get(\"test\") == \"ok\" ");
}

TEST_CASE(" dict->Set(\"test\", \"1\") dict->Get(\"test\") 1 ") {
	Container<std::string, std::string> *dict = new Container<std::string, std::string>;
	dict->Set("test", "1");

	std::cout << dict->Get("test") << "\n";

	REQUIRE(" dict->Get(\"test\") == \"1\" ");
}

TEST_CASE(" dict->IsSet(\"test\", \"ok\") true ") {
	Container<std::string, std::string> *dict = new Container<std::string, std::string>;
	dict->Set("test", "ok");

	std::cout << std::boolalpha << dict->IsSet("test") << std::endl;

	REQUIRE(" dict->IsSet(\"test\") == true ");
}