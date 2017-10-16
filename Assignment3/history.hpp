#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <iostream>

void history(std::vector<std::string> v)
{
	std::cout << "Dun Dun DUUUUUUN" << std::endl;

	for (int i = 1; i < v.size()-1; i++)
	{
		std::cout << i << ":\t" << v[i] << std::endl;
	}

	std::cout << "Debug Testing" << std::endl;
	return;
}

#endif
