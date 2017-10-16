#include<iostream>

#include "e.hpp"

void e(int n)
{
	double E = 0;

	for (int i = 0; i < n; i++)
	{
		E += (1 / factorial(i));
	}//creating e

	std::cout << E << std::endl;
}//e

double factorial(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return factorial(n-1)*n;
}//factorial
