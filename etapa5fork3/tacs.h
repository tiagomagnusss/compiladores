/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_DIV 4
#define TAC_MUL 5
#define TAC_LT 6
#define TAC_GT 7
#define TAC_LE 8
#define TAC_GE 9
#define TAC_EQ 10
#define TAC_DIF 11
#define TAC_AND 12
#define TAC_OR 13
#define TAC_NOT 14
#define TAC_MOVE 15
#define TAC_MOVE_VECTOR 16
#define TAC_IFZ 17
#define TAC_LABEL 18
#define TAC_JUMP 19
#define TAC_VECTOR_INDEX 20
#define TAC_VARIABLE_VECTOR 21
#define TAC_ELSE 22
#define TAC_BEGINFUN 23
#define TAC_ENDFUN 24
#define TAC_PARAM 25
#define TAC_ARG 26
#define TAC_CALL 27
#define TAC_CALLRES 28
#define TAC_RETURN 29

/*

pronto:
#define AST_DEC_FUNC == TAC_BEGINFUN TAC_ENDFUN
#define AST_ATRIB_VARIAVEL == TAC_MOVE
#define AST_ATRIB_VETOR == TAC_MOVE_VECTOR
#define AST_IF == TAC_IFZ
#define AST_ELSE == TAC_ELSE
#define AST_ACCESS_VECTOR == TAC_VECTOR_INDEX
#define AST_VARIABLE == TAC_SYMBOL TAC_VARIABLE_VECTOR
#define AST_PARAM == TAC_PARAM
#define AST_LIST_ARGUMENTS == TAC_ARG
#define AST_FUNC_CALL == TAC_CALL TAC_CALLRES
#define AST_RETURN == TAC_RETURN

falta:
#define AST_DEC_VARIABLE == XX
#define AST_DEC_VECTOR == XX
#define AST_DEC_VECTOR_SIZE == XX
#define AST_WHILE == XX
#define AST_PRINT == XX
#define AST_READ == XX
#define AST_LIST_ELEMENTS_STRING == XX
*/

typedef struct tac_node
{
	int type;
	HASH_NODE *res;
	HASH_NODE *op1;
	HASH_NODE *op2;
	struct tac_node *prev;
	struct tac_node *next;
} TAC;

TAC *tacCreate (int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
void tacPrint (TAC *tac);
void tacPrintBackwards (TAC *tac);
TAC *tacJoin (TAC *l1, TAC *l2);
TAC *generateCode (AST *node);

#endif