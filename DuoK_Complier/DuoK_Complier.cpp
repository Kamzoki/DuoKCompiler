// DuoK_Complier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

//Variables
std::string codeText = "";
//Prototypes
void ReadSourceCode();

int main()
{
	ReadSourceCode();
    return 0;
}

void ReadSourceCode()
{
	std::ifstream file("E:/Study/4th Year second semester/Compiler/Project/DuoK_Complier/Source Code.txt", std::ios::in);
	std::string codeText = "";
	if (file.is_open() == true)
	{
		while (getline(file, codeText))
		{
			// Call Lexical Analyzer
			std::cout << codeText<< std::endl;
		}
		file.close();
	}
	else {
		std::cout << "There is some error.\n Make sure your code is saved in a file called Source Code.txt. \n Make sure your Source Code.txt has been saved in the same folder of the \n compiler project." << std::endl;
	}
	return;
}
