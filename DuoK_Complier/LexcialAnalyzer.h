#pragma once
#include <string>
#include <list>
#include <iostream>
#include <vector>

enum class Keys {
	Reserved,
	ReservedS,
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
	Keys m_Key;
	std::string m_Value;
};

class LexcialAnalyzer
{
public:
	//Constructor
	LexcialAnalyzer();
	// Tokenizes the source code
	void fn_Toknize(std::string sourceCode);
	//Temp function for printing out accpeted tokens for testing
	void fn_PrintAcceptedTokens() const;

private:
	//PrintLexError print lexical analyser error message
	void fn_PrintLexError() const;
	// This fucntion accepts lexem as a parameter and categorize it as either a keyword type, identfier, or a value.
	void fn_CategorizeLexeme(std::string lexeme);

	//Holds all predefines language reserved words
	Token KeyWords[24];
	//Holds all accpeted/valid tokens
	std::vector <Token> AcceptedTokens;
	//Holds a refused/invalid tokens
    std::string RefusedLexem = "";

};

