/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <stdlib.h>
#include <stdio.h>

#include "tacs.h"

#define MAXSONS 4

TAC *tacCreate (int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2)
{
	TAC *newtac = 0;
	newtac = (TAC *) calloc (1, sizeof(TAC));
	newtac->type = type;
	newtac->res = res;
	newtac->op1 = op1;
	newtac->op2 = op2;
	newtac->prev = 0;
	newtac->next = 0;
	return newtac;
}

void tacPrint (TAC *tac)
{
	if (!tac)
	{
		return;
	}
	//if (tac->type == TAC_SYMBOL)
	//{
	//	return;
	//}
	fprintf (stderr, "TAC(");
	switch(tac->type)
	{
		case TAC_SYMBOL: fprintf (stderr, "TAC_SYMBOL"); break;
		case TAC_ADD: fprintf (stderr, "TAC_ADD"); break;
		case TAC_SUB: fprintf (stderr, "TAC_SUB"); break;
		case TAC_DIV: fprintf (stderr, "TAC_DIV"); break;
		case TAC_MUL: fprintf (stderr, "TAC_MUL"); break;
		case TAC_LT: fprintf (stderr, "TAC_LT"); break;
		case TAC_GT: fprintf (stderr, "TAC_GT"); break;
		case TAC_LE: fprintf (stderr, "TAC_LE"); break;
		case TAC_GE: fprintf (stderr, "TAC_GE"); break;
		case TAC_EQ: fprintf (stderr, "TAC_EQ"); break;
		case TAC_DIF: fprintf (stderr, "TAC_DIF"); break;
		case TAC_AND: fprintf (stderr, "TAC_AND"); break;
		case TAC_OR: fprintf (stderr, "TAC_OR"); break;
		case TAC_NOT: fprintf (stderr, "TAC_NOT"); break;
		case TAC_ATRIB_VARIAVEL: fprintf (stderr, "TAC_ATRIB_VARIAVEL"); break;
		case TAC_ATRIB_VETOR: fprintf (stderr, "TAC_ATRIB_VETOR"); break;
		case TAC_IFZ: fprintf (stderr, "TAC_IFZ"); break;
		case TAC_LABEL: fprintf (stderr, "TAC_LABEL"); break;
		case TAC_JUMP: fprintf (stderr, "TAC_JUMP"); break;
		/*case TAC_XXX: fprintf (stderr, "TAC_XXX"); break;*/
		default: fprintf (stderr, "TAC_UNKNOWN"); break;
	}
	fprintf (stderr, ", %s", (tac->res) ? tac->res->text : " ");
	fprintf (stderr, ", %s", (tac->op1) ? tac->op1->text : " ");
	fprintf (stderr, ", %s", (tac->op2) ? tac->op2->text : " ");
	fprintf (stderr, ");\n");
}

void tacPrintBackwards (TAC *tac)
{
	if (!tac)
	{
		return;
	}
	else
	{
		tacPrintBackwards (tac->prev);
		tacPrint (tac);
	}
}

TAC *tacJoin (TAC *l1, TAC *l2)
{
	TAC *point;

	if (!l1)
	{
		return l2;
	}
	if (!l2)
	{
		return l1;
	}
	for (point = l2; point->prev != 0; point = point->prev)
	{
		; // Nothing
	}
	point->prev = l1;
	return l2;
}

TAC *binaryOp (TAC *code[], int type)
{
	return tacJoin (tacJoin (code[0], code[1]), tacCreate (type, makeTemp(), code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
}

TAC *makeIf(TAC *code[])
{
	TAC *jumptac = 0;
	TAC *labeltac = 0;
	HASH_NODE *newlabel = 0;
	newlabel = makeLabel();
	jumptac = tacCreate (TAC_IFZ, newlabel, code[0] ? code[0]->res : 0, 0);
	jumptac->prev = code[0];
	labeltac = tacCreate (TAC_LABEL, newlabel, 0, 0);
	labeltac->prev = code[1];
	if(code[2])
	{
		TAC *jumptacelse = 0;
		TAC *labeltacelse = 0;
		HASH_NODE *newlabelelse = 0;
		newlabelelse = makeLabel();
		jumptacelse = tacCreate (TAC_JUMP, newlabelelse, 0, 0);
		jumptacelse->prev = 0;
		labeltacelse = tacCreate (TAC_LABEL, newlabelelse, 0, 0);
		labeltacelse->prev = code[2];
		return tacJoin (tacJoin (tacJoin (jumptac, labeltac), jumptacelse), labeltacelse);
	}
	else
	{
		return tacJoin (jumptac, labeltac);
	}
}

TAC *generateCode (AST* node)
{
	int i;
	TAC *result = 0;
	TAC *code[MAXSONS];

	if (!node)
	{
		return 0;
	}

	for(i = 0; i < MAXSONS; i++)
	{
		code[i] = generateCode (node->son[i]);
	}
	switch(node->type)
	{
		case AST_SYMBOL:
			result = tacCreate (TAC_SYMBOL, node->symbol, 0, 0);
			break;
		case AST_ADD:
			result = binaryOp (code, TAC_ADD);
			break;
		case AST_SUB:
			result = binaryOp (code, TAC_SUB);
			break;
		case AST_DIV:
			result = binaryOp (code, TAC_DIV);
			break;
		case AST_MUL:
			result = binaryOp (code, TAC_MUL);
			break;
		case AST_LT:
			result = binaryOp (code, TAC_LT);
			break;
		case AST_GT:
			result = binaryOp (code, TAC_GT);
			break;
		case AST_LE:
			result = binaryOp (code, TAC_LE);
			break;
		case AST_GE:
			result = binaryOp (code, TAC_GE);
			break;
		case AST_EQ:
			result = binaryOp (code, TAC_EQ);
			break;
		case AST_DIF:
			result = binaryOp (code, TAC_DIF);
			break;
		case AST_AND:
			result = binaryOp (code, TAC_AND);
			break;
		case AST_OR:
			result = binaryOp (code, TAC_OR);
			break;
		case AST_NOT:
			result = binaryOp (code, TAC_NOT);
			break;
		case AST_ATRIB_VARIAVEL:
			result = tacJoin (code[0], tacCreate (TAC_ATRIB_VARIAVEL, node->symbol, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_ATRIB_VETOR:
			result = tacJoin (tacJoin (code[0], code[1]), tacCreate (TAC_ATRIB_VETOR, node->symbol, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0));
			break;
		case AST_IF:
			result = makeIf (code);
			break;
		case AST_ELSE:
			result = makeIf (code);
			break;
		default:
			result = tacJoin (code[0], tacJoin (code[1], tacJoin (code[2], code[3])));
			break;
	}
	return result;
}