/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

%{

#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "ast.h"

int yylex (void);
int getLineNumber (void);

/* Declaracao correta de yyerror segundo manual */
void yyerror (char const *);

%}

%union
{
	HASH_NODE *symbol;
	//AST *ast;
}

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

%token<symbol> TK_IDENTIFIER

%token<symbol> LIT_INTEGER
%token<symbol> LIT_FLOAT
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING
%token TOKEN_ERROR

%left '|' '&' '~'
%left '<' '>' '.' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '*' '/'

%%

programa: lista_dec
	;

lista_dec: dec lista_dec
	| /* empty */
	;

dec: tipo TK_IDENTIFIER '(' valor ')' 										';'
	| tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao					';'
	| tipo TK_IDENTIFIER '(' lista_params ')' bloco
	;

inicializacao: valor inicializacao
	| /* empty */
	;

valor: LIT_INTEGER
	| LIT_FLOAT
	| LIT_CHAR
	| TK_IDENTIFIER
	;

lista_argumentos: expr lista_argumentos
	| /* empty */
	;

bloco: '{' cmd_simples resto '}'
	;

resto: ';' cmd_simples resto
	| /* empty */
	;

lista_params: param resto_params
	| /* empty */
	;

param: tipo TK_IDENTIFIER
	;

resto_params: param resto_params
	| /* empty */
	;

tipo: KW_CHAR
	| KW_INT
	| KW_FLOAT
	;

cmd_simples: cmd_atrib
	| cmd_if
	| cmd_while
	| cmd_print
	| cmd_read
	| cmd_return
	| bloco
	| /* empty */
	;

cmd_atrib: TK_IDENTIFIER ASSIGNMENT expr
	| TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr
	;

cmd_if: KW_IF '(' expr ')' cmd_simples cmd_else
	;

cmd_else: KW_ELSE cmd_simples
	| /* empty */
	;

cmd_while: KW_WHILE '(' expr ')' cmd_simples
	;

cmd_print: KW_PRINT lista_elementos
	;

cmd_read: KW_READ TK_IDENTIFIER index
	;

index: '[' expr ']'
	| /* empty */
	;

cmd_return: KW_RETURN expr
	;

lista_elementos: LIT_STRING resto_print
	| expr resto_print
	;

resto_print: lista_elementos
	| /* empty */
	;

expr: LIT_INTEGER
	| LIT_FLOAT
	| LIT_CHAR
	| TK_IDENTIFIER index
	| TK_IDENTIFIER '(' lista_argumentos ')'
	| expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '.' expr
	| expr '<' expr
	| expr '>' expr
	| '(' expr ')'
	| expr OPERATOR_LE expr
	| expr OPERATOR_GE expr
	| expr OPERATOR_EQ expr
	| expr OPERATOR_DIF expr
	| expr '&' expr
	| expr '|' expr
	| '~' expr

%%

void yyerror (char const *s)
{
	fprintf (stderr, "%s at line %d\n", s, getLineNumber ());
	exit (3);
}
