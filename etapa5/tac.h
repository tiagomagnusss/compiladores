#ifndef TAC_HEADER
#define TAC_HEADER

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
#define TAC_VARIABLE 14
#define TAC_FUNC_CALL 15
#define TAC_NOT 16
#define TAC_RETURN 17
#define TAC_READ 18
#define TAC_PRINT 19
#define TAC_WHILE 20
#define TAC_ELSE 21
#define TAC_IF 22
#define TAC_CHAR 23
#define TAC_INT 24
#define TAC_FLOAT 25
#define TAC_PARAM 26
#define TAC_DEC_FUNC 27
#define TAC_DEC_VECTOR 28
#define TAC_DEC_VECTOR_SIZE 29
#define TAC_DEC_VARIABLE 30
#define TAC_ACCESS_VECTOR 31
#define TAC_ATRIB_VARIAVEL 32
#define TAC_ATRIB_VETOR 33

typedef struct tac_node {
	int type;
	HASH_NODE* res;
	HASH_NODE* op1;
	HASH_NODE* op2;

	struct tac_node* prev;
	struct tac_node* next;
} TAC;

TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2);
void tacPrintSingle(TAC* tac);
void tacPrintBack(TAC* tac);
TAC* tacJoin(TAC* l1, TAC* l2);
TAC* generateCode(AST* node);

#endif
