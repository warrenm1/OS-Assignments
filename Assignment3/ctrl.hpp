#ifndef CTRL_HPP
#define CTRL_HPP

#include <unistd.h>
#include <stdio.h>
#include <cstring>

#include "stringSplit.hpp"
#include <string>
#include <vector>

void ctrl(std::vector<std::string> v)
{
	std::vector<std::string> temp;

	int cNum = std::stoi(v[v.size()-1]);

	commandSplit(cNum, temp);

	char** argv = new char*[temp.size() + 1];

	for (int i = 0; i < temp.size(); i++)
	{
//		argv[i] = new char[8];
		strcpy(argv[i], temp[i].c_str());
	}
	argv[temp.size()] = NULL;

	execvp(argv[0], argv);

	return;
}

#endif
