#include<iostream>
#include<iomanip>
#include<math.h>

#include "pi.hpp"

void pi(int n)
{
	std::cout << std::setprecision(n+1) << M_PI << std::endl;
	return;
}//Pi
