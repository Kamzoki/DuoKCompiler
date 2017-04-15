#include "stdafx.h"
#include "LexcialAnalyzer.h"

/*Token::Token(Keys key, std::string value) {
	m_Key = key;
	m_Value = value;
}*/
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
	KeyWords[10].m_Key = Keys::Operator;
	KeyWords[10].m_Value = "+";

	KeyWords[11].m_Key = Keys::Operator;
	KeyWords[11].m_Value = "-";

	KeyWords[12].m_Key = Keys::Operator;
	KeyWords[12].m_Value = "*";

	KeyWords[13].m_Key = Keys::Operator;
	KeyWords[13].m_Value = "/";

	KeyWords[14].m_Key = Keys::Operator;
	KeyWords[14].m_Value = "%";

	KeyWords[15].m_Key = Keys::Operator;
	KeyWords[15].m_Value = "&&";

	KeyWords[16].m_Key = Keys::Operator;
	KeyWords[16].m_Value = "||";

	KeyWords[17].m_Key = Keys::Operator;
	KeyWords[17].m_Value = "==";

	KeyWords[18].m_Key = Keys::Operator;
	KeyWords[18].m_Value = "<";

	KeyWords[19].m_Key = Keys::Operator;
	KeyWords[19].m_Value = ">";

	KeyWords[20].m_Key = Keys::Operator;
	KeyWords[20].m_Value = "<=";

	KeyWords[21].m_Key = Keys::Operator;
	KeyWords[21].m_Value = ">=";

	KeyWords[22].m_Key = Keys::Operator;
	KeyWords[22].m_Value = "!=";

	KeyWords[23].m_Key = Keys::Operator;
	KeyWords[23].m_Value = "=";
	

}

void LexcialAnalyzer::fn_CategorizeLexem(std::string currentLine)
{
	//This function Categorzie lexems.
	/*int j = 0;
	for (int i = 0; i < currentLine.length(); i=j+1)
	{
			if (currentLine[i] == ' ')
			{
				i++;
				if (!(currentLine[i] == '_' || (currentLine[i] >= 'a' && currentLine[i] <= 'z') || (currentLine[i] >= 'A' && currentLine[i] <= 'Z')))
				{
					fn_PrintLexError();
					break;
				}
			}

		else
		{
			bool foundLexem = false;
			int j = i;
			std::string newLexem = "";
			while (foundLexem == false)
			{
				newLexem += std::string() + currentLine[j];
				if (currentLine[j+1] == ' ')
				{
					Token newToken;
					newToken.m_Value = newLexem;
					for (int k = 0; k < 24; k++)
					{
						if (newToken.m_Value == KeyWords[k].m_Value)
						{
							newToken.m_Key = KeyWords[k].m_Key;
							foundLexem = true;
						}
					}
					if (foundLexem == false)
					{
						newToken.m_Key = Keys::Identifier;
						bool isDigit = false;
						int h = 0;
						for (int l = 0; l < newLexem.length(); l++)
						{
							if (newLexem[l] >= '0' && newLexem[l] <= '9')
							{
								h++;
								if (l == newLexem.length() -1 && h == l)
								{
									isDigit = true;
								}
							}
						}
						if (isDigit == true)
						{
							newToken.m_Key = Keys::Value;
						}
						foundLexem = true;
					}
					//std::cout << newToken.m_Value << std::endl;
					AcceptedTokens.push_back(newToken);
				}
			}
		}
	}
	fn_PrintAcceptedTokens();*/
	return;
}

void LexcialAnalyzer::fn_Toknize(std::string sourceCode)
{

	return;
}

void LexcialAnalyzer::fn_PrintAcceptedTokens() const
{
	if (AcceptedTokens.size() != 0)
	{
		for (int i = 0; i < AcceptedTokens.size(); i++)
		{
			std::cout << "Token" <<i<< ": " << AcceptedTokens[i].m_Value << std::endl;
		}
	}
	return;
}

void LexcialAnalyzer::fn_PrintLexError() const
{
	std::cout <<"Lexical Error! \n Fix your shit, BITCH!";
	return;
}
