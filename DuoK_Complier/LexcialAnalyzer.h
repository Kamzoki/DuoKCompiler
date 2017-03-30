#pragma once
#include <string>
#include <list>
#include <iostream>

enum class Keys {
	Reserved,
	Identifier,
	Variable,
	Constant,
	OpenCurlyBracket,
	ClosedCurlyBracket,
	OpenParentheses,
	ClosedParentheses,
	SemiColon,
	Operator,
};

class Token {
public:
	Keys m_Key;
	std::string m_Value;
};

class LexcialAnalyzer
{
public:
	//Constructor
	LexcialAnalyzer();
	// GetKeyWords function reads the line passed, extract predfined keywords, and add them to accepted tokens
	void fn_GetKeyWords(std::string currentLine) const;
	// GetNonKeyWords function reads the line passed, extract non keywords, and add them to accepted tokens
	void fn_GetNonKeyWords(std::string currentLine) const; // TODO this function must apply grammer rules like is this identifer has any keyword type before it or not.
	//Temp function for printing out accpeted tokens for testing
	void fn_PrintAcceptedTokens() const;
	// CheckValidity function checks if refused tokens list is clear ... else, it wil print out a lexical analyzer error.
	void CheckValidity() const;
	//PrintLexError print lexical analyser error message
	void PrintLexError(Token element) const;

private:
	//Holds all predefines language reserved words
	Token KeyWords[24];
	//Holds all accpeted/valid tokens
	std::list <Token> AcceptedTokens;
	//Holds all refused/invalid tokens
	std::list <Token> RefusedTokens;

};

