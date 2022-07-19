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

programa: lista_dec
	;

lista_dec: dec lista_dec
	| /* empty */
	;

dec: tipo TK_IDENTIFIER '(' valor ')' 										';'
	| tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao  ';'
	| tipo TK_IDENTIFIER ASSIGNMENT expr 									  ';'
	| tipo TK_IDENTIFIER '(' lista_params ')'	bloco					';'
	| bloco ';'
	| cmd_simples
	;

inicializacao: valor inicializacao
	| /* empty */
	;

bloco: '{' seq_cmd_bloco resto '}'
	| /* empty */
	;

resto: ';' seq_cmd_bloco resto
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

valor: LIT_INTEGER
	| LIT_FLOAT
	| LIT_CHAR
	;

cmd_simples: cmd_atrib
	| cmd_if
	| cmd_while
	| cmd_print
	| cmd_read
	| cmd_return
	;

cmd_atrib: TK_IDENTIFIER ASSIGNMENT expr ';'
	| TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr ';'
	;

cmd_if: KW_IF '(' expr ')' bloco cmd_else
	;

cmd_else: KW_ELSE bloco
	| /* empty */
	;

cmd_while: KW_WHILE '(' expr ')' bloco
	;

cmd_print: KW_PRINT print_args ';'
	;

cmd_read: KW_READ '(' TK_IDENTIFIER ')' ';'
	;

cmd_return: KW_RETURN '(' expr ')' ';'
	;

seq_cmd_bloco: cmd_simples seq_cmd_bloco
	| /* empty */
	;

print_args: expr print_args
	| LIT_STRING print_args
	| TK_IDENTIFIER '[' expr ']'
	| /* empty */
	;

expr: LIT_INTEGER
	| LIT_FLOAT
	| LIT_CHAR
	| TK_IDENTIFIER
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
	| expr '~' expr

%%

void yyerror (char const *s)
{
	fprintf(stderr, "%s at line %d\n", s, getLineNumber());
	exit(3);
}
