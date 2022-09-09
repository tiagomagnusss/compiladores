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
#define TAC_COPY 15
#define TAC_COPY_VECTOR 16
#define TAC_JFALSE 17
#define TAC_LABEL 18
#define TAC_JUMP 19
#define TAC_VECTOR_INDEX 20
#define TAC_VARIABLE_VECTOR 21
#define TAC_ELSE 22

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