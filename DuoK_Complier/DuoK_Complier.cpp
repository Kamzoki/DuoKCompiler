// DuoK_Complier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "LexcialAnalyzer.h"

//Variables
std::string codeText = "";
LexcialAnalyzer LexAnl;

//Prototypes
void ReadSourceCode();
void PrintResult();

int main()
{
	ReadSourceCode();
	PrintResult();
    return 0;
}

void ReadSourceCode()
{
	std::string lineBuffer;
	std::ifstream file("E:/Study/4th Year second semester/Compiler/Project/DuoK_Complier/Source Code.txt", std::ios::in);
	if (file.is_open() == true)
	{
		std::cout << "Lexical Anlyzer output: - \n";
		int lineIndex = 0;
		while (getline(file, lineBuffer))
		{
			// Call Lexical Analyzer
			if (lineIndex != 0)
			{
				codeText += " " + lineBuffer;
			}
			else {
				codeText += lineBuffer;
			}
			lineIndex++;
		}
		file.close();
		LexAnl.fn_Toknize(codeText);
	}
	else {
		std::cout << "There is some error.\n Make sure your code is saved in a file called Source Code.txt. \n Make sure your Source Code.txt has been saved in the same folder of the \n compiler project." << std::endl;
	}
	return;
}

void PrintResult() {
	LexAnl.fn_PrintAcceptedTokens();
	return;
}