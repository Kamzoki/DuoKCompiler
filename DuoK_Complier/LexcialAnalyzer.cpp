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
	KeyWords[3].m_Key = Keys::ReservedS;
	KeyWords[3].m_Value = "if";

	//for keyword
	KeyWords[4].m_Key = Keys::ReservedS;
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

void LexcialAnalyzer::fn_CategorizeLexeme(std::string lexeme)
{
	//This function Categorzie lexems.

	Token newToken;
	newToken.m_Value = lexeme;
	
	//Search if the given lexeme is a keyword, if yes, intilize it's key, and add it to the accepted tokens and then exit the funciton.
	for (int i = 0; i < 23; i++)
	{
		if (lexeme == KeyWords[i].m_Value)
		{
			newToken.m_Key = KeyWords[i].m_Key;
			AcceptedTokens.push_back(newToken);
			return;
		}
	}

	//If search for keywords fails, start checking if the given lexeme is a digit, if yes make it's key = Value, else, make it's key = Identifier and then exit the function
	int DigitLexemeIndex = 0;
	for (int i = 0; i < lexeme.length(); i++)
	{
		if (lexeme[i] >= '0' && lexeme[i] <= '9')
		{
			DigitLexemeIndex++;
		}
	}
	if (DigitLexemeIndex == lexeme.length())
	{
		newToken.m_Key = Keys::Value;
	}
	else {
		newToken.m_Key = Keys::Identifier;
	}
	AcceptedTokens.push_back(newToken);
	return;
}

void LexcialAnalyzer::fn_Toknize(std::string sourceCode)
{
	char charBuffer;
	std::string lexemeBuffer = "";
	for (int i = 0; i < sourceCode.length(); i++)
	{
		if (sourceCode[i] != ' ')
		{
			charBuffer = sourceCode[i];
			if ((charBuffer >= 'a' && charBuffer <= 'z') || (charBuffer >='A' && charBuffer <= 'Z') || (charBuffer >= '0' && charBuffer <= '9'))
			{
				lexemeBuffer += std::string() + charBuffer;
			}
			else
			{
				fn_CategorizeLexeme(lexemeBuffer);
				lexemeBuffer = "";
				switch (charBuffer)
				{
				case '<':
					if (sourceCode[i+1]=='='){
					lexemeBuffer +=std::string()+charBuffer+sourceCode[i+1];
					fn_CategorizeLexeme(lexemeBuffer);
					lexemeBuffer = "";
					i++;
					}
					else
					{
						lexemeBuffer += std::string() + charBuffer;
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
					}
					break;
				case '=':
					if (sourceCode[i + 1] == '=') {
						lexemeBuffer += std::string() + charBuffer + sourceCode[i + 1];
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
						i++;
					}
					else
					{
						lexemeBuffer += std::string() + charBuffer;
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
					}
					break;
				case '!':
					if (sourceCode[i + 1] == '=') {
						lexemeBuffer += std::string() + charBuffer + sourceCode[i + 1];
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
						i++;
					}
					else
					{
						lexemeBuffer += std::string() + charBuffer;
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
					}
					break;
				case '>':
					if (sourceCode[i + 1] == '=') {
						lexemeBuffer += std::string() + charBuffer + sourceCode[i + 1];
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
						i++;
					}
					else
					{
						lexemeBuffer += std::string() + charBuffer;
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
					}
					break;
				case '&':
					if (sourceCode[i + 1] == '&') {
					lexemeBuffer += std::string() + charBuffer + sourceCode[i + 1];
					fn_CategorizeLexeme(lexemeBuffer);
					lexemeBuffer = "";
					i++;
				}
						 else
						 {
							 fn_PrintLexError();
						 }
					break;
				case '|':
					if (sourceCode[i + 1] == '|') {
						lexemeBuffer += std::string() + charBuffer + sourceCode[i + 1];
						fn_CategorizeLexeme(lexemeBuffer);
						lexemeBuffer = "";
						i++;
					}
					else
					{
						fn_PrintLexError();
					}
					break;
				default:
					lexemeBuffer += std::string() + charBuffer;
					fn_CategorizeLexeme(lexemeBuffer);
					lexemeBuffer = "";
					break;
				}
			}
		}
	}
	return;
}

void LexcialAnalyzer::fn_PrintAcceptedTokens() const
{
	if (AcceptedTokens.size() != 0)
	{
		std::string theKey = "";
		for (int i = 0; i < AcceptedTokens.size(); i++)
		{
			switch (AcceptedTokens[i].m_Key)
			{
			case Keys::Reserved:
				theKey = "Reserved";
				break;
			case Keys::ReservedS:
				theKey = "Reserved Special";
				break;
			case Keys::Value:
				theKey = "Some Value";
				break;
			case Keys::Identifier:
				theKey = "Identifier";
				break;
			case Keys::OpenCurlyBracket:
				theKey = "OpenCurlyBracket";
				break;
			case Keys::ClosedCurlyBracket:
				theKey = "ClosedCurlyBracket";
				break;
			case Keys::OpenParentheses:
				theKey = "OpenParentheses";
				break;
			case Keys::ClosedParentheses:
				theKey = "ClosedParentheses";
				break;
			case Keys::SemiColon:
				theKey = "SemiColon";
				break;
			case Keys::Operator:
				theKey = "Operator";
				break;
			}
			std::cout << "Token" <<i<< ":- \n" <<"Key: " << theKey << " Value: " << AcceptedTokens[i].m_Value << std::endl;
		}
	}
	else {
		fn_PrintLexError();
	}
	return;
}

void LexcialAnalyzer::fn_PrintLexError() const
{
	std::cout <<"Lexical Error! \n invalid lexeme!\n";
	return;
}
