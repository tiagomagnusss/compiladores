/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

%{

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

%left '|' '&' '~'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '+' '-'
%left '.' '/'

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

cmd_atrib: TK_IDENTIFIER ASSIGNMENT expr			{ astPrint ($3, 0); }
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

expr: LIT_INTEGER									{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_FLOAT										{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHAR										{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| TK_IDENTIFIER index							{ $$ = 0; /* temporario */}
	| TK_IDENTIFIER '(' lista_argumentos ')'		{ $$ = 0; /* temporario */}
	| expr '+' expr									{ $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
	| expr '-' expr									{ $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0); }
	| expr '/' expr									{ $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0); }
	| expr '.' expr									{ $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0); }
	| expr '<' expr									{ $$ = astCreate(AST_LT, 0, $1, $3, 0, 0); }
	| expr '>' expr									{ $$ = astCreate(AST_GT, 0, $1, $3, 0, 0); }
	| '(' expr ')'									{ $$ = 0; /* temporario */}
	| expr OPERATOR_LE expr							{ $$ = astCreate(AST_LE, 0, $1, $3, 0, 0); }
	| expr OPERATOR_GE expr							{ $$ = astCreate(AST_GE, 0, $1, $3, 0, 0); }
	| expr OPERATOR_EQ expr							{ $$ = astCreate(AST_EQ, 0, $1, $3, 0, 0); }
	| expr OPERATOR_DIF expr						{ $$ = astCreate(AST_DIF, 0, $1, $3, 0, 0); }
	| expr '&' expr									{ $$ = astCreate(AST_AND, 0, $1, $3, 0, 0); }
	| expr '|' expr									{ $$ = astCreate(AST_OR, 0, $1, $3, 0, 0); }
	| '~' expr										{ $$ = 0; /* temporario */}

%%

void yyerror (char const *s)
{
	fprintf (stderr, "%s at line %d\n", s, getLineNumber ());
	exit (3);
}
