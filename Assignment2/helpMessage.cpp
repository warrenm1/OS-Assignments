#include<iostream>

#include "helpMessage.hpp"

void helpMessage()
{
		std::cout << "Error code: INVALID ENTRY" << std::endl << "\"-fib\" for Fibinacci Sequence" << std::endl << "\tRange: 0-40" << std::endl << "\"-e\" for value of e" << std::endl << "\tRange: 1-30" << std::endl << "\"-pi\" for value of pi" << std::endl << "\tRange: 1-10" << std::endl << std::endl;
			return;
}//Standard error message

void helpMessageFib()
{
	std::cout << "Error code: 1123581321" << std::endl << "For the '-fib' function, use Range of 0-40" << std::endl << std::endl;
	return;
}//Fib errormessage

void helpMessageE()
{
	std::cout << "Error code: 27182818285" << std::endl << "For the '-e' function, use Range of 1-30" << std::endl << std::endl;
	return;
}//E error message

void helpMessagePi()
{
	std::cout << "Error code: 31415926536" << std::endl << "For the '-pi' function, use Range of 1-10" << std::endl << std::endl;
	return;
}//Pi error message
