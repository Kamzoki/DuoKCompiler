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
	// This fucntion accepts lexem as a parameter and categorize it as either a keyword type, identfier, or a value.
	void fn_CategorizeLexem(std::string lexem);
	// Tokenizes the source code
	void fn_Toknize(std::string sourceCode);
	//Temp function for printing out accpeted tokens for testing
	void fn_PrintAcceptedTokens() const;
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

