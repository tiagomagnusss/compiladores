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

	// fprintf(stderr, "TAC(");
	switch(tac->type){
		case TAC_SYMBOL:
			fprintf(stderr,"\nTAC_SYMBOL");
			break;
		case TAC_ADD:
			fprintf(stderr,"\nTAC_ADD");
			break;
		case TAC_SUB:
			fprintf(stderr,"\nTAC_SUB");
			break;
		case TAC_DIV:
			fprintf(stderr,"\nTAC_DIV");
			break;
		case TAC_MUL:
			fprintf(stderr,"\nTAC_MUL");
			break;
		case TAC_LT:
			fprintf(stderr,"\nTAC_LT");
			break;
		case TAC_GT:
			fprintf(stderr,"\nTAC_GT");
			break;
		case TAC_LE:
			fprintf(stderr,"\nTAC_LE");
			break;
		case TAC_GE:
			fprintf(stderr,"\nTAC_GE");
			break;
		case TAC_EQ:
			fprintf(stderr,"\nTAC_EQ");
			break;
		case TAC_DIF:
			fprintf(stderr,"\nTAC_DIF");
			break;
		case TAC_AND:
			fprintf(stderr,"\nTAC_AND");
			break;
		case TAC_OR:
			fprintf(stderr,"\nTAC_OR");
			break;
		case TAC_VARIABLE:
			fprintf(stderr,"\nTAC_VARIABLE");
			break;
		case TAC_FUNC_CALL:
			fprintf(stderr,"\nTAC_FUNC_CALL");
			break;
		case TAC_NOT:
			fprintf(stderr,"\nTAC_NOT");
			break;
		case TAC_RETURN:
			fprintf(stderr,"\nTAC_RETURN");
			break;
		case TAC_READ:
			fprintf(stderr,"\nTAC_READ");
			break;
		case TAC_PRINT:
			fprintf(stderr,"\nTAC_PRINT");
			break;
		case TAC_WHILE:
			fprintf(stderr,"\nTAC_WHILE");
			break;
		case TAC_ELSE:
			fprintf(stderr,"\nTAC_ELSE");
			break;
		case TAC_IF:
			fprintf(stderr,"\nTAC_IF");
			break;
		case TAC_CHAR:
			fprintf(stderr,"\nTAC_CHAR");
			break;
		case TAC_INT:
			fprintf(stderr,"\nTAC_INT");
			break;
		case TAC_FLOAT:
			fprintf(stderr,"\nTAC_FLOAT");
			break;
		case TAC_PARAM:
			fprintf(stderr,"\nTAC_PARAM");
			break;
		case TAC_DEC_FUNC:
			fprintf(stderr,"\nTAC_DEC_FUNC");
			break;
		case TAC_DEC_VECTOR:
			fprintf(stderr,"\nTAC_DEC_VECTOR");
			break;
		case TAC_DEC_VECTOR_SIZE:
			fprintf(stderr,"\nTAC_DEC_VECTOR_SIZE");
			break;
		case TAC_DEC_VARIABLE:
			fprintf(stderr,"\nTAC_DEC_VARIABLE");
			break;
		case TAC_ACCESS_VECTOR:
			fprintf(stderr,"\nTAC_ACCESS_VECTOR");
			break;
		case TAC_ATRIB_VARIAVEL:
			fprintf(stderr,"\nTAC_ATRIB_VARIAVEL");
			break;
		case TAC_ATRIB_VETOR:
			fprintf(stderr,"\nTAC_ATRIB_VETOR");
			break;
		default:
			fprintf(stderr, "\nTAC_UKNOWN(%d) ", tac->type);
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

	fprintf(stderr, ")");
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
	TAC* code[MAX_SONS];

	if (!node)
		return 0;
	for(i=0; i<MAX_SONS; i++)
		code[i] = generateCode(node->son[i]);

	switch(node->type){
		case AST_SYMBOL:
			result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
			break;
		case AST_ADD:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_ADD, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_SUB:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_SUB, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_MUL:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_MUL, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_DIV:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_DIV, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_LT:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_LT, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_GT:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_GT, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_LE:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_LE, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_GE:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_GE, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_EQ:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_EQ, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_DIF:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_DIF, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_AND:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_AND, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_OR:
			result = tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_OR, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_NOT:
			result = tacJoin(code[0], tacCreate(AST_NOT, 0, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_RETURN:
			result = tacJoin(code[0], tacCreate(AST_RETURN, 0, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_READ:
			result = tacJoin(code[0], tacCreate(AST_READ, 0, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_PRINT:
			result = tacJoin(code[0], tacCreate(AST_PRINT, 0, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_WHILE:
			result = tacJoin(code[0], tacCreate(AST_WHILE, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_IF:
			result = tacJoin(code[0], tacCreate(AST_IF, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_ELSE:
			result = tacJoin(code[0], tacCreate(AST_ELSE, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_ATRIB_VETOR:
			result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_ATRIB_VETOR, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0)));
			break;
		case AST_ATRIB_VARIAVEL:
			result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_ATRIB_VARIAVEL, 0, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0)));
			break;
		case AST_CHAR:
		case AST_INT:
		case AST_FLOAT:
				result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
				break;
		case AST_VARIABLE:
				result = tacCreate(TAC_SYMBOL, node->symbol, 0, 0);
				break;
		default:
			result = tacJoin(tacJoin(tacJoin(code[0], code[1]), code[2]), code[3]);
			break;
	}

	return result;
}
