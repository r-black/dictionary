#include <iostream>
#include <string>
#include "container.h"

int main()
{
	Container<std::string, std::string> *dict = new Container<std::string, std::string>;
	dict->Set("test", "ok");
	std::cout << std::boolalpha << dict->IsSet("test") << std::endl;
	std::cout << dict->Get("test") << std::endl;
	try
	{
		// dict->~Container();
		std::cout << dict->Get("test") << std::endl;
		std::cout << dict->Get("ok") << std::endl;
	}
	catch (NotFoundKeyException<std::string>& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << dict->Get("ok") << std::endl;
	}
	catch (NotFoundKeyException<std::string>& e)
	{
		setlocale(LC_ALL, "Russian");
		std::cerr << "Ключ " << e.GetKey() << " не найден" << std::endl;
	}
}