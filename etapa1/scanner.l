/*
Trabalho Pratico de Compiladores
Tiago ----
Pedro Hoerlle de Oliveira - 00288548
*/

%{
#include "tokens.h"

int getLineNumber (void);

bool isRunning = true;
%}

/* Opcao do Flex para manter o numero da linha do lexema consumido */
%option yylineno

%x COMMENT

/* Declaracao de Defines */
ALFABETO_	[a-zA-Z_]
DIGITO		[0-9]

%%

/* Palavras Reservadas */
char					{ return KW_CHAR; }
int						{ return KW_INT; }
float					{ return KW_FLOAT; }
if						{ return KW_IF; }
else					{ return KW_ELSE; }
while					{ return KW_WHILE; }
read					{ return KW_READ; }
print					{ return KW_PRINT; }
return					{ return KW_RETURN; }

/* Caracteres Especiais */
";"						{ return yytext[0]; }
"("						{ return yytext[0]; }
")"						{ return yytext[0]; }
"["						{ return yytext[0]; }
"]"						{ return yytext[0]; }
"{"						{ return yytext[0]; }
"}"						{ return yytext[0]; }
"+"						{ return yytext[0]; }
"-"						{ return yytext[0]; }
"."						{ return yytext[0]; }
"/"						{ return yytext[0]; }
"<"						{ return yytext[0]; }
">"						{ return yytext[0]; }
"&"						{ return yytext[0]; }
"|"						{ return yytext[0]; }
"~"						{ return yytext[0]; }

/* Operadores Compostos */
"<-"					{ return ASSIGNMENT; }
"<="					{ return OPERATOR_LE; }
">="					{ return OPERATOR_GE; }
"=="					{ return OPERATOR_EQ; }
"!="					{ return OPERATOR_DIF; }

/* Identificadores */
{ALFABETO_}+			{ return TK_IDENTIFIER; }

/* Literais */
{DIGITO}+				{ return LIT_INTEGER; }
"'"[ -~]"'"				{ return LIT_CHAR; } /* Aceita os caracteres da tabela ASCII entre o ESPACO e o TILDE, rejeitando outros tipos de entrada tipo NULL, BackSpace, Tab etc. 
												Na especificacao nao fala nada sobre rejeitar essas entradas, mas faz mais sentido assim */
{DIGITO}","{DIGITO}		{ return LIT_FLOAT; } /* ESPECIFICACAO: ?? oq seriam exatamente literais decimais ?? Supus que sao um digito unico, ??ou seja 22,5 e 2,55 nao sao float, n faz sentido?? */
"\s"					{ return LIT_STRING; } /* to do */


/* Comentarios */
"##".*					{ } /* Comentarios de uma linha */

/* Comentarios de multiplas linhas */
"\#"					{ BEGIN(COMMENT); }

<COMMENT>"#\\"			{ BEGIN(INITIAL); }
<COMMENT>"\n"			{ } /* yylineno conta a linha quando o \n eh consumido */
<COMMENT>.				{ }

/* Outros */
[ \t\r]					{ }
"\n"					{ } /* yylineno conta a linha quando o \n eh consumido */
.						{ return TOKEN_ERROR; }

%%

#include "main.c"

int yywrap(){
	isRunning = false;

	return 1;
}

int getLineNumber()
{
	return yylineno;
}
