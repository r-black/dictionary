#include <iostream>
#include <string>
#include "container.h"

int main()
{
	Dictionary<std::string, std::string> *dict = new Container<std::string, std::string>;
	dict->Set("test", "ok");
	std::cout << std::boolalpha << dict->IsSet("test") << std::endl;
	std::cout << dict->Get("test") << std::endl;
	try
	{
		dict->Get("ok");
	}
	catch (NotFoundKeyException<std::string>& e)
	{
		std::cerr << e.what() << std::endl;
	}
}