%{
#include "tokens.h"

bool isRunning = true;
int lineNumber = 1;

%}

%%

"char"                    { return KW_CHAR; }
"int"                     { return KW_INT; }
"float"                   { return KW_FLOAT; }
"if"                      { return KW_IF; }
"else"                    { return KW_ELSE; }
"while"                   { return KW_WHILE; }
"read"                    { return KW_READ; }
"print"                   { return KW_PRINT; }
"return"                  { return KW_RETURN; }
"<-"                      { return ASSIGNMENT; }
"<="                      { return OPERATOR_LE; }
">="                      { return OPERATOR_GE; }
"=="                      { return OPERATOR_EQ; }
"!="                      { return OPERATOR_DIF; }
""                        { return TK_IDENTIFIER; }
"\d "                     { return LIT_INTEGER; }
"\d .\d*"                 { return LIT_FLOAT; }
"'\c'"                    { return LIT_CHAR; }
"\s"                      { return LIT_STRING; }
"."                       { return TOKEN_ERROR; }

%%

int yywrap(){
	isRunning = false;

	return 1;
}
