#include <iostream>
#include <string>
#include <sys/wait.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <cstring>

void stringSplit(std::string s, std::vector<std::string>& v)
{
	std::stringstream ss;
	ss << s;

	std::string temp;

	while (std::getline(ss, temp, ' '));

		v.push_back(temp);


	return;
}

void commandSplit(int cNum, std::vector<std::string>& v)
{ 
	std::stringstream ss;
	ss << v[cNum];

	std::string temp;

	while (std::getline(ss, temp, ' '))
		v.push_back(temp);

	return;
}

void history(std::vector<std::string> v)
{
	for (int i = 1; i < v.size() - 1; i ++)
		std::cout << i << ":\t" << v[i] << std::endl;

	return;
}

void ctrl(std::vector<std::string> v)
{
	std::vector<std::string> temp;

	int cNum = std::stoi(v[v.size() - 1]);

	commandSplit(cNum, temp);

	char** argv = new char*[temp.size() + 1];

	for (int i = 0; i < temp.size(); i++)
		strcpy(argv[i], temp[i].c_str());

	argv[temp.size()] = NULL;

	execvp(argv[0], argv);

	return;
}

int main()
{
	bool shell = true;

	std::string command;
	
	std::vector<std::string> argv;
	std::vector<std::string> History;

	std::chrono::time_point<std::chrono::high_resolution_clock> s = std::chrono::high_resolution_clock::now();
	std::chrono::time_point<std::chrono::high_resolution_clock> e = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> totalTime = e - s;

	std::cout << "[cmd]:\t";
	std::getline(std::cin, command);
	History.push_back(command);
	
//	std::cout << History[0] <<std::endl;

	stringSplit(command, argv);
	
	while(shell)
	{
		if (argv[0] == "exit")
		{
			shell = false;
			
			History.clear();
			argv.clear();

			std::cout << "Good-bye" << std::endl << std::endl;

			return EXIT_SUCCESS;
		}//basis check--avoiding fork bombs

//		History.push_back(command);

//		for (int i; i < History.size(); i++)
//			std::cout << History[i] << std::endl; //debugging
		
		if (argv[0] == "ptime")
		{
			std::cout << "Total Time: " << totalTime.count() << " seconds" << std::endl;
		}
		if (argv[0] == "^")
		{
			std::string comNum = argv.back();
			argv.pop_back();
			argv.clear();
			argv[0] = "ctrl";
			for (int i = 0; i < History.size(); i++)
				argv.push_back(History[i]);
//			argv.insert(argv.end(), History.begin(), History.end());
			argv.push_back(comNum);
		}//places history between 'ctrl' and the number command for History.
		
		if (argv[0] == "history")
		{
			for (int i = 0; i < History.size(); i++)
				argv.push_back(History[i]);
//			argv.insert(argv.end(), History.begin(), History.end());
		}//appends History to the end of argv for display usage

		std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

		if (argv[0] != "ptime")
		{
		       	if (fork())
			{
//				std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

				wait(NULL);
			
				std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double> tempTime = end - start;
				totalTime = totalTime + tempTime;
			}//parent--time
			else
			{
				char** argv2 = new char*[argv.size() + 1];
			
				for (int i = 0; i < argv.size(); i++)
				{
//					argv2[i] = new char[8];
					std::strcpy(argv2[i],argv[i].c_str());
				}

				argv2[argv.size()] = NULL;

				execvp(argv2[0], argv2);
			
				std::cout << "Error! '" << argv[0] << "' not a valid command!" << std::endl;
			}//executing process
		}

		argv.clear();

		std::cout << "[cmd]:\t";
		std::getline(std::cin, command);
		History.push_back(command);
		stringSplit(command, argv);

//		for (int i = 0; i < History.size(); i++)
//			std::cout << History[i] << std::endl;
	}//while in the shell


	return EXIT_SUCCESS;
}//main
