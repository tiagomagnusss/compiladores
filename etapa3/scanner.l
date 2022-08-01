/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

%{

#include "y.tab.h"
#include "hash.h"

int running = 1;

int getLineNumber (void);
void initMe (void);
int isRunning (void);

%}

/* Opcao do Flex para manter o numero da linha do lexema consumido */
%option yylineno

/* Opcao do Flex para nao gerar codigo que nao eh utilizado e causa warnings */
%option nounput
%option noinput

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
{ALFABETO_}+			{ hashInsert(yytext,TK_IDENTIFIER); return TK_IDENTIFIER; }

 /* Literais */
{DIGITO}+				{ hashInsert(yytext,LIT_INTEGER); return LIT_INTEGER; }
'[^'\n]'				{ hashInsert(yytext,LIT_CHAR); return LIT_CHAR; } /* Confirmado ''(vazio) e quebra de linha nao faz parte*/
{DIGITO}+,{DIGITO}+		{ hashInsert(yytext,LIT_FLOAT); return LIT_FLOAT; } /* Literais Decimais sao a mesma coisa que inteiros */

 /* String */
\"([^\\"\n]|\\.)*\"		{ hashInsert(yytext,LIT_STRING); return LIT_STRING; } /* Confirmado string vazia eh valida e multilinha nao */

 /* Comentarios de uma linha */
"##".*					{ }

 /* Comentarios de multiplas linhas */
"\\#"					{ BEGIN(COMMENT); }

<COMMENT>"#\\"			{ BEGIN(INITIAL); }
<COMMENT>"\n"			{ } /* yylineno conta a linha quando o \n eh consumido */
<COMMENT>.				{ }

 /* Outros */
[ \t\r]					{ } /* ESPACO, TAB e CARRIAGE RETURN */
"\n"					{ } /* yylineno conta a linha quando o \n eh consumido */
.						{ return TOKEN_ERROR; }

%%

#include "hash.c"
#include "main.c"

int yywrap(void)
{
	running = 0;
	return 1;
}

int getLineNumber(void)
{
	return yylineno;
}

void initMe(void)
{
	hashInit();
}

int isRunning(void)
{
	return running;
}
