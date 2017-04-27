#pragma once
#include <iostream>
#include <vector>
#include "LexcialAnalyzer.h"

class SyntaxAnalyzer
{
public:
	SyntaxAnalyzer();
	~SyntaxAnalyzer();
	//This function checks the syntax according to the grammar.
	void fn_CheckSyntax(std::vector<Token> &AT);
private:
	//This funciton prints out syntax error.
	void fn_PrintError() const;
	//This function pops an arc with the given key from openArcs;
	void fn_PopArc(Keys arc);
	//This function checks the current status
	void fn_CheckCurrentStatus(Keys status) const;
	
	bool isFirstStatus = true;
	std::vector<Keys> nextStatus;
	std::vector<Keys> openArcs;
};

