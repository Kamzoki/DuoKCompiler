#pragma once
#include <iostream>
#include <vector>
#include "Token.h"

class SyntaxAnalyzer
{
public:
	//This function checks the syntax according to the grammar.
	void fn_CheckSyntax();
	std::vector<Token> AT;
private:
	//This funciton prints out syntax error.
	void fn_PrintError() const;
	void fn_PrintError(std::vector<Token> &AT, int errorIndex) const;
	//This function pops an arc with the given key from openArcs;
	void fn_PopArc(Keys arc);
	//This function checks the current status
	void fn_CheckCurrentStatus(Keys status, std::vector<Token> &AT, int errorIndex);
	
	bool isFirstStatus = true;
	std::vector<Keys> nextStatus;
	std::vector<Keys> openArcs;
};

