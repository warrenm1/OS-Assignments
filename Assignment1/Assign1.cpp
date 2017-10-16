#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<math.h>

void fib(int);
void e(int);
void pi(int);
void helpMessageFib();
void helpMessageE();
void helpMessagePi();
void helpMessage();

double factorial(int);

int main(int argc, char* argv[])
{
	std::string function = argv[1];
	int number = std::stoi(argv[2]);

	if(function == "-fib")
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

void fib(int n)
{
	if (n == 0)
	{
		std::cout << "0" << std::endl;
		return;
	}//n=0 base case
	if (n == 1 || n == 2)
	{
		std::cout << "1" << std::endl;
		return;
	}//n=1 or n=2 base case

	int nMinus1 = 1;
	int nMinus2 = 1;
	int newN = nMinus1 + nMinus2;

	for (int i = 3; i < n; i++)
	{
		nMinus2 = nMinus1;
		nMinus1 = newN;
		newN = nMinus1 + nMinus2;
	}//calculating Fibinacci number using for loop

	std::cout << newN << std::endl;
	return;
}//fib

void e(int n)
{
	double E = 0;

	for (int i = 0; i < n; i++)
	{
		E += (1 / factorial(i));
	}//creating e

	std::cout <<  E << std::endl;
}//e

void pi(int n)
{
	std::cout << std::setprecision(n+1) << M_PI << std::endl;
	return;
}//pi

void helpMessageFib()
{
	std::cout << "Error code: 1123581321" << std::endl << "For the 'fib' function, use Range of 0-40" << std:: endl << std::endl;
	return;
}//Fib Error Message

void helpMessageE()
{
	std::cout << "Error code:27182818285" << std::endl << "For the 'e' function, use Range of 1-30" << std::endl << std::endl;
	return;
}//E error message

void helpMessagePi()
{
	std::cout << "Error code: 31415926536" << std::endl << "For the 'pi' function, use Range of 1-10" << std::endl << std::endl;
	return;
}//Pi error message

void helpMessage()
{
	std::cout << "Error code: INVALID ENTRY" << std::endl << "\"-\" for Fibinacci Sequence" << std::endl << "\tRange: 0-40" << std::endl << "\"-e\" for value of e" << std::endl << "\tRange: 1-30" << std::endl << "\"-pi\" for value of pi" << std::endl << "\tRange:1-10" << std::endl << std::endl;
	return;
}//Standard error message

double factorial(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return factorial(n - 1)*n;
}//factorial
