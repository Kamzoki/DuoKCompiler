#include "stdafx.h"
#include "LexcialAnalyzer.h"


LexcialAnalyzer::LexcialAnalyzer(){
	//Initialaizing predefined keywords and their tags.
	
	//number keyword
	KeyWords[0].m_Key = Keys::Reserved;
	KeyWords[0].m_Value = "number";

	//string keyword
	KeyWords[1].m_Key = Keys::Reserved;
	KeyWords[1].m_Value = "string";

	//character keyword
	KeyWords[2].m_Key = Keys::Reserved;
	KeyWords[2].m_Value = "char";

	//If keyword
	KeyWords[3].m_Key = Keys::Reserved;
	KeyWords[3].m_Value = "if";

	//for keyword
	KeyWords[4].m_Key = Keys::Reserved;
	KeyWords[4].m_Value = "for";

	//semicolon keyword
	KeyWords[5].m_Key = Keys::SemiColon;
	KeyWords[5].m_Value = ";";

	//Open parentheses keyword
	KeyWords[6].m_Key = Keys::OpenParentheses;
	KeyWords[6].m_Value = "(";

	//Closed parentheses keyword
	KeyWords[7].m_Key = Keys::ClosedParentheses;
	KeyWords[7].m_Value = ")";

	//Open curly bracket keyword
	KeyWords[8].m_Key = Keys::OpenCurlyBracket;
	KeyWords[8].m_Value = "{";

	//Closed curly bracket keyword
	KeyWords[9].m_Key = Keys::ClosedCurlyBracket;
	KeyWords[9].m_Value = "}";

	//Operator keyword
	// TODO add all operators and make sure their keys are Operator
	KeyWords[10].m_Key = Keys::Operator;
	KeyWords[10].m_Value = 
	return;
}

void LexcialAnalyzer::fn_GetKeyWords(std::string currentLine) const
{
	return;
}

void LexcialAnalyzer::fn_GetNonKeyWords(std::string currentLine) const
{
	return;
}

void LexcialAnalyzer::fn_PrintAcceptedTokens() const
{
	return;
}

void LexcialAnalyzer::CheckValidity() const
{
	return;
}
