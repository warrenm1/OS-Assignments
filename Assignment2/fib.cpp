#include<iostream>

#include "fib.hpp"

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
	}//calculating Fibinacci number using 'for' loop

	std::cout << newN << std::endl;
	return;
}//fib
