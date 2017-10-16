#ifndef STRINGSPLIT_HPP
#define STRINGSPLIT_HPP

#include <string>
#include <sstream>
#include <iostream>

void stringSplit(std::string s, std::vector<std::string>& v)
{	
	std::stringstream ss;
	ss << s;

	std::string temp;

	while (std::getline(ss, temp,  ' '))
	{
		v.push_back(temp);
	}//while there is stuff in the string stream
//	std::cout << temp[0] << std::endl;
	return;
}//stringSplit

void commandSplit(int cNum, std::vector<std::string>& v)
{
	std::stringstream ss;
	ss << v[cNum];

	std::string temp;

	while (std::getline(ss, temp, ' '))
	{
		v.push_back(temp);
	}

	return;
}
#endif
