#include "stdafx.h"
#include "SyntaxAnalyzer.h"

/*
Grammar:-
S-> Keyword ID
Exp -> OP|ID|Value|ID OP|OP Value|OP Value
OP -> =|!=|>|<|<=|>=|-|+|*|/|==|&&||||;
Keyword -> Reserved|ReservedS
Reserved -> string|char|number
ReservedS-> if|for
*/

void SyntaxAnalyzer::fn_CheckSyntax(std::vector<Token>& AT)
{
	for (int i = 0; i < AT.size(); i++)
	{
		if (i != 0)
		{
			isFirstStatus = false;
		}
		else {
			isFirstStatus = true;
			if (AT[i].m_Key == Keys::Operator || AT[i].m_Key == Keys::Value || AT[i].m_Key == Keys::SemiColon)
			{
				fn_PrintError();
			}
		}
			switch (AT[i].m_Key)
			{
				//This is the grammar.
				/*Cases on the current key, first check if it's stored in the nextStatus of the pre Key by calling fn_CheckCurrentStatus.
				Then clear the nextStatus vector and reassign with the new keys that should follow up the current key as the grammar specifies.*/

			case Keys::SemiColon:
				fn_CheckCurrentStatus(Keys::SemiColon);
				nextStatus.clear();
				nextStatus.push_back(Keys::Reserved); nextStatus.push_back(Keys::ReservedS); nextStatus.push_back(Keys::ClosedCurlyBracket);
				break;
			case Keys::Reserved:
				fn_CheckCurrentStatus(Keys::Reserved);
				nextStatus.clear();
				nextStatus.push_back(Keys::Identifier);
				break;
			case Keys::ReservedS:
				fn_CheckCurrentStatus(Keys::ReservedS);
				nextStatus.clear();
				nextStatus.push_back(Keys::OpenCurlyBracket); nextStatus.push_back(Keys::OpenParentheses);
				break;
			case Keys::Identifier:
				fn_CheckCurrentStatus(Keys::Identifier);
				nextStatus.clear();
				nextStatus.push_back(Keys::Operator); nextStatus.push_back(Keys::SemiColon); nextStatus.push_back(Keys::ClosedParentheses);
				break;
			case Keys::Operator:
				fn_CheckCurrentStatus(Keys::Operator);
				nextStatus.clear();
				nextStatus.push_back(Keys::Identifier); nextStatus.push_back(Keys::Value);
				break;
			case Keys::Value:
				fn_CheckCurrentStatus(Keys::Value);
				nextStatus.clear();
				nextStatus.push_back(Keys::Operator); nextStatus.push_back(Keys::SemiColon); nextStatus.push_back(Keys::ClosedParentheses);
				break;
			case Keys::OpenParentheses:
				fn_CheckCurrentStatus(Keys::OpenParentheses);
				nextStatus.clear();
				nextStatus.push_back(Keys::Identifier); nextStatus.push_back(Keys::Reserved); nextStatus.push_back(Keys::Value);
				openArcs.push_back(Keys::OpenParentheses);
				break;
			case Keys::OpenCurlyBracket:
				fn_CheckCurrentStatus(Keys::OpenCurlyBracket);
				nextStatus.clear();
				nextStatus.push_back(Keys::Reserved); nextStatus.push_back(Keys::ReservedS); nextStatus.push_back(Keys::Identifier);
				break;
			case Keys::ClosedParentheses:
				fn_CheckCurrentStatus(Keys::ClosedParentheses);
				nextStatus.clear();
				nextStatus.push_back(Keys::OpenCurlyBracket);
				fn_PopArc(Keys::OpenParentheses);
				break;
			case Keys::ClosedCurlyBracket:
				fn_CheckCurrentStatus(Keys::ClosedCurlyBracket);
				nextStatus.clear();
				nextStatus.push_back(Keys::SemiColon);
				fn_PopArc(Keys::OpenCurlyBracket);
				break;
			}
	}
	if (openArcs.empty() == false)
	{
		fn_PrintError();
	}
	return;
}

void SyntaxAnalyzer::fn_PrintError() const
{
	return;
}

void SyntaxAnalyzer::fn_PopArc(Keys arc)
{
	//This function simulates the pop behavior but on a spacific index.
	for (int i = 0; i < openArcs.size(); i++)
	{
		if (arc == openArcs[i])
		{
			openArcs.erase(openArcs.begin() + i);
		}
	}
	return;
}

void SyntaxAnalyzer::fn_CheckCurrentStatus(Keys status) const
{
	//This function loops through the nextStatus of the previous key, if it found a match with the passed status, return from funtion. if not, call fn_PrintError
	if (isFirstStatus == false)
	{
		for (int i = 0; i < nextStatus.size(); i++)
		{
			if (status == nextStatus[i])
			{
				return;
			}
		}

		fn_PrintError();
	}
	return;
}


