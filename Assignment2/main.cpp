#include<string>
#include<iostream>

#include "e.hpp"
#include "fib.hpp"
#include "pi.hpp"
#include "helpMessage.hpp"

int main(int argc, char* argv[])
{
	std::string function = argv[1];
	int number = std::stoi(argv[2]);

	if (function == "-fib")
	{
		if (number >= 0 && number <= 40)
			fib(number);
		else
			helpMessageFib();
	}//call fib function
	else if (function == "-e")
	{
		if (number > 0 && number <= 30)
			e(number);
		else
			helpMessageE();
	}//call e function
	else if (function == "-pi")
	{
		if (number > 0 && number <= 10)
			pi(number);
		else
			helpMessagePi();
	}//call pi function
	else
		helpMessage();

	return EXIT_SUCCESS;
}//main
