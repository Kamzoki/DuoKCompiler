#pragma once
#include <string>
#include <list>
#include <iostream>
#include <vector>

enum class Keys {
	Reserved,
	Identifier,
	Value,
	OpenCurlyBracket,
	ClosedCurlyBracket,
	OpenParentheses,
	ClosedParentheses,
	SemiColon,
	Operator,
};

class Token {
public:
	//Token(Keys key, std::string vlaue);
	Keys m_Key;
	std::string m_Value;
};

class LexcialAnalyzer
{
public:
	//Constructor
	LexcialAnalyzer();
	// GetNonKeyWords function reads the line passed, extract non keywords, and add them to accepted tokens
	void fn_CheckLexems(std::string currentLine); // TODO this function must apply grammer rules like is this identifer has any keyword type before it or not.
	//Temp function for printing out accpeted tokens for testing
	void fn_PrintAcceptedTokens() const;
	// CheckValidity function checks if refused tokens list is clear ... else, it wil print out a lexical analyzer error.
	//void fn_CheckValidity() const;
	//PrintLexError print lexical analyser error message
	void fn_PrintLexError() const;

private:
	//Holds all predefines language reserved words
	Token KeyWords[24];
	//Holds all accpeted/valid tokens
	std::vector <Token> AcceptedTokens;
	//Holds a refused/invalid tokens
    std::string RefusedLexem = "";

};

