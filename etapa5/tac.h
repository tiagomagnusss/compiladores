#ifndef TAC_HEADER
#define TAC_HEADER

#include "hash.h"
#include "ast.h"

#define TAC_SYMBOL 1
#define TAC_ADD 2

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
