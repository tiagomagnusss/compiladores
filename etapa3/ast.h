/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#ifndef AST_HEADER
#define AST_HEADER

#include "hash.h"

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_DIV 4
#define AST_MUL 5
#define AST_LT 6
#define AST_GT 7
#define AST_LE 8
#define AST_GE 9
#define AST_EQ 10
#define AST_DIF 11
#define AST_AND 12
#define AST_OR 13
#define AST_VARIABLE 14
#define AST_FUNC_CALL 15
#define AST_ASSOCITIVITY 16
#define AST_NOT 17
#define AST_LIST_ARGUMENTS 18
#define AST_LIST_ELEMENTS_STRING 19
#define AST_LIST_ELEMENTS_EXPR 20
#define AST_RETURN 21
#define AST_READ 22
#define AST_PRINT 23
#define AST_WHILE 24
#define AST_ELSE 25
#define AST_IF 26
#define AST_ATRIB_VARIAVEL 27
#define AST_ATRIB_VETOR 28
#define AST_BLOCK 29
#define AST_RESTO 30
#define AST_CHAR 31
#define AST_INT 32
#define AST_FLOAT 33
#define AST_RESTO_PARAMS 34
#define AST_PARAM 35
#define AST_LISTA_PARAMS 36
#define AST_INIT 37
#define AST_DEC_FUNC 38
#define AST_DEC_VECTOR 39
#define AST_DEC_VECTOR_SIZE 40
#define AST_DEC_VARIABLE 41
#define AST_LIST_DEC 42
#define AST_ACCESS_VECTOR 43
#define AST_PROGRAM 44

typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate (int type, HASH_NODE *symbol, AST *son0, AST *son1, AST *son2, AST *son3);
void astPrint (AST *node, int level);
void astDecompile (AST *node);

#endif