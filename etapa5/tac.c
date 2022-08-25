#include <stdio.h>
#include <stdlib.h>

#include "tac.h"

#define MAXSONS 4 
TAC* tacCreate(int type, HASH_NODE* res, HASH_NODE* op1, HASH_NODE* op2){
	TAC* newtac;
	newtac = (TAC*) calloc(1, sizeof(TAC));
	newtac->type = type;
	newtac->res = res;
	newtac->op1 = op1;
	newtac->op2 = op2;
	newtac->prev = 0;
	newtac->next = 0;

	return newtac;
}


void tacPrintSingle(TAC* tac){
	if (!tac)
		return;

	fprintf(stderr, "TAC(");
	switch(tac->type){
		case TAC_SYMBOL:
			fprintf(stderr,"TAC_SYMBOL");
			break;
		case TAC_ADD:
			fprintf(stderr,"TAC_ADD");
			break;
		default:
			break;
	}

	if (tac->res){
		fprintf(stderr, ",%s", tac->res->text);
	} else {
		fprintf(stderr, ",0");
	}

	if (tac->op1){
       fprintf(stderr, ",%s", tac->op1->text);
	} else {
	   fprintf(stderr, ",0");
	}

	if (tac->op2){
		fprintf(stderr, ",%s", tac->op2->text);
	} else {
		fprintf(stderr, ",0");
	}

	fprintf(stderr, ")\n");
}


void tacPrintBack(TAC* tac){
	TAC* node;

	for(node=tac; node; node = node->prev){
		tacPrintSingle(node);
	}
}

TAC* tacJoin(TAC* l1, TAC* l2){
	if (!l1) return l2;
	if (!l2) return l1;

	TAC* tac;
	for(tac=l2; tac->prev; tac = tac->prev){
		// nothing
	}

	tac->prev = l1;
	return l2;
}

TAC* generateCode(AST* node){
	int i;
	TAC* result = 0;
	TAC* code[MAXSONS];
	
	if (!node)
		return 0;
	for(i=0; i<MAXSONS; i++)
		code[i] = generateCode(node->son[i]);

	switch(node->type){
		case AST_SYMBOL: 
			result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
			break;
		case AST_ADD:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_ADD, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		default:
			result = tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
			break;
	}

	return result;
}
