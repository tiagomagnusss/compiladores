/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

%{

#include <stdio.h>
#include <stdlib.h>

int yylex (void);
int getLineNumber (void);

/* Declaracao correta de yyerror segundo manual */
void yyerror (char const *);

%}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_ELSE
%token KW_WHILE
%token KW_READ
%token KW_PRINT
%token KW_RETURN

%token ASSIGNMENT
%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_DIF

%token TK_IDENTIFIER

%token LIT_INTEGER
%token LIT_FLOAT
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR

%left '+' '-'
%left '*' '/'

%%

program: lista_dec
	| %empty
	;

lista_dec: dec lista_dec
	| dec
	;

dec: tipo TK_IDENTIFIER '(' valor ')' ';'
	| tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao ';'
	| funcao
	| bloco ';'
	| cmd_simples
	;

inicializacao: valor inicializacao
	| %empty
	;

funcao: cabecalho corpo
	;

cabecalho: tipo TK_IDENTIFIER parametros
	;

parametros: tipo TK_IDENTIFIER
	;

corpo: bloco
	;

bloco: '{' seq_cmd_bloco resto '}'
	| %empty
	;

resto: ';' seq_cmd_bloco resto
	| %empty
	;

tipo: KW_CHAR
	| KW_INT
	| KW_FLOAT
	;

valor: LIT_INTEGER
	| LIT_FLOAT
	| LIT_CHAR
	;



dec: KW_INT TK_IDENTIFIER '=' LIT_INTEGER ';'
	;

plist: expr plisttail
	|
	;

plisttail: '.' plisttail
	|
	;

expr: LIT_INTEGER
	| TK_IDENTIFIER
	| expr '+' expr
	| expr '-' expr
	| '(' expr ')'

%%

void yyerror (char const *s)
{
	fprintf(stderr, "%s at line %d\n", s, getLineNumber());
	exit(3);
}
