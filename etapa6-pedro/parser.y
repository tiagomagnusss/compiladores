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
#include "tacs.h"
#include "asm.h"

int yylex (void);
int getLineNumber (void);

/* Declaracao correta de yyerror segundo manual */
void yyerror (char const *);

%}

%union
{
	HASH_NODE *symbol;
	AST *ast;
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

%type<ast> expr
%type<ast> resto_print
%type<ast> index
%type<ast> lista_argumentos
%type<ast> lista_elementos
%type<ast> cmd_return
%type<ast> cmd_read
%type<ast> cmd_print
%type<ast> cmd_while
%type<ast> cmd_else
%type<ast> cmd_if
%type<ast> cmd_atrib
%type<ast> cmd_simples
%type<ast> tipo
%type<ast> resto_params
%type<ast> param
%type<ast> lista_params
%type<ast> resto
%type<ast> bloco
%type<ast> valor
%type<ast> inicializacao
%type<ast> dec
%type<ast> lista_dec
%type<ast> programa

%left '|' '&' '~'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '.' '/'

%%

programa: lista_dec									{ TAC *code; $$ = astCreate (AST_PROGRAM, 0, $1, 0, 0, 0); astPrint ($$, 0); astDecompile ($$); code = generateCode ($$); tacPrintBackwards (code); code = tacReverse(code); generateAsm(code); }
		;
	;

lista_dec: dec lista_dec							{ $$ = astCreate (AST_LIST_DEC, 0, $1, $2, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

dec: tipo TK_IDENTIFIER '(' valor ')'';'			{ $$ = astCreate (AST_DEC_VARIABLE, $2, $1, $4, 0, 0); }
	| tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao';'	{ $$ = astCreate (AST_DEC_VECTOR, $2, $1, astCreate (AST_DEC_VECTOR_SIZE, $4, 0, 0, 0, 0), $6, 0); }
	| tipo TK_IDENTIFIER '(' lista_params ')' bloco	{ $$ = astCreate (AST_DEC_FUNC, $2, $1, $4, $6, 0); }
	;

inicializacao: valor inicializacao					{ $$ = astCreate (AST_INIT, 0, $1, $2, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

valor: LIT_INTEGER									{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_FLOAT										{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHAR										{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	;

lista_argumentos: expr lista_argumentos				{ $$ = astCreate (AST_LIST_ARGUMENTS, 0, $1, $2, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

bloco: '{' cmd_simples resto '}'					{ $$ = astCreate (AST_BLOCK, 0, $2, $3, 0, 0); }
	;

resto: ';' cmd_simples resto						{ $$ = astCreate (AST_RESTO, 0, $2, $3, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

lista_params: param resto_params					{ $$ = astCreate (AST_LISTA_PARAMS, 0, $1, $2, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

param: tipo TK_IDENTIFIER							{ $$ = astCreate (AST_PARAM, $2, $1, 0, 0, 0); }
	;

resto_params: param resto_params					{ $$ = astCreate (AST_RESTO_PARAMS, 0, $1, $2, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

tipo: KW_CHAR										{ $$ = astCreate (AST_CHAR, 0, 0, 0, 0, 0); }
	| KW_INT										{ $$ = astCreate (AST_INT, 0, 0, 0, 0, 0); }
	| KW_FLOAT										{ $$ = astCreate (AST_FLOAT, 0, 0, 0, 0, 0); }
	;

cmd_simples: cmd_atrib								{ $$ = $1; }
	| cmd_if										{ $$ = $1; }
	| cmd_while										{ $$ = $1; }
	| cmd_print										{ $$ = $1; }
	| cmd_read										{ $$ = $1; }
	| cmd_return									{ $$ = $1; }
	| bloco											{ $$ = $1; }
	| /* empty */									{ $$ = 0; }
	;

cmd_atrib: TK_IDENTIFIER ASSIGNMENT expr			{ $$ = astCreate (AST_ATRIB_VARIAVEL, $1, $3, 0, 0, 0); }
	| TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr	{ $$ = astCreate (AST_ATRIB_VETOR, $1, $3, $6, 0, 0); }
	;

cmd_if: KW_IF '(' expr ')' cmd_simples cmd_else		{ $$ = astCreate (AST_IF, 0, $3, $5, $6, 0); }
	;

cmd_else: KW_ELSE cmd_simples						{ $$ = astCreate (AST_ELSE, 0, $2, 0, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

cmd_while: KW_WHILE '(' expr ')' cmd_simples		{ $$ = astCreate (AST_WHILE, 0, $3, $5, 0, 0); }
	;

cmd_print: KW_PRINT lista_elementos					{ $$ = astCreate (AST_PRINT, 0, $2, 0, 0, 0); }
	;

cmd_read: KW_READ TK_IDENTIFIER index				{ $$ = astCreate (AST_READ, $2, $3, 0, 0, 0); }
	;

index: '[' expr ']'									{ $$ = astCreate (AST_ACCESS_VECTOR, 0, $2, 0, 0, 0); }
	| /* empty */									{ $$ = 0; }
	;

cmd_return: KW_RETURN expr							{ $$ = astCreate (AST_RETURN, 0, $2, 0, 0, 0); }
	;

lista_elementos: LIT_STRING resto_print				{ $$ = astCreate (AST_LIST_ELEMENTS_STRING, $1, $2, 0, 0, 0); }
	| expr resto_print								{ $$ = astCreate (AST_LIST_ELEMENTS_EXPR, 0, $1, $2, 0, 0); }
	;

resto_print: lista_elementos						{ $$ = $1; }
	| /* empty */									{ $$ = 0; }
	;

expr: LIT_INTEGER									{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_FLOAT										{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHAR										{ $$ = astCreate (AST_SYMBOL, $1, 0, 0, 0, 0); }
	| TK_IDENTIFIER index							{ $$ = astCreate (AST_VARIABLE, $1, $2, 0, 0, 0); }
	| TK_IDENTIFIER '(' lista_argumentos ')'		{ $$ = astCreate (AST_FUNC_CALL, $1, $3, 0, 0, 0); }
	| expr '+' expr									{ $$ = astCreate (AST_ADD, 0, $1, $3, 0, 0); }
	| expr '-' expr									{ $$ = astCreate (AST_SUB, 0, $1, $3, 0, 0); }
	| expr '/' expr									{ $$ = astCreate (AST_DIV, 0, $1, $3, 0, 0); }
	| expr '.' expr									{ $$ = astCreate (AST_MUL, 0, $1, $3, 0, 0); }
	| expr '<' expr									{ $$ = astCreate (AST_LT, 0, $1, $3, 0, 0); }
	| expr '>' expr									{ $$ = astCreate (AST_GT, 0, $1, $3, 0, 0); }
	| '(' expr ')'									{ $$ = astCreate (AST_ASSOCITIVITY, 0, $2, 0, 0, 0); }
	| expr OPERATOR_LE expr							{ $$ = astCreate (AST_LE, 0, $1, $3, 0, 0); }
	| expr OPERATOR_GE expr							{ $$ = astCreate (AST_GE, 0, $1, $3, 0, 0); }
	| expr OPERATOR_EQ expr							{ $$ = astCreate (AST_EQ, 0, $1, $3, 0, 0); }
	| expr OPERATOR_DIF expr						{ $$ = astCreate (AST_DIF, 0, $1, $3, 0, 0); }
	| expr '&' expr									{ $$ = astCreate (AST_AND, 0, $1, $3, 0, 0); }
	| expr '|' expr									{ $$ = astCreate (AST_OR, 0, $1, $3, 0, 0); }
	| '~' expr										{ $$ = astCreate (AST_NOT, 0, $2, 0, 0, 0); }

%%

void yyerror (char const *s)
{
	fprintf (stderr, "%s at line %d\n", s, getLineNumber ());
	exit (3);
}