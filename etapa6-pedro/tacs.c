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
	switch(tac->type)
	{
		case TAC_SYMBOL: return;
		case TAC_VECTOR_INDEX: return;
		case TAC_ELSE: return;
	}
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
		case TAC_MOVE: fprintf (stderr, "TAC_MOVE"); break;
		case TAC_IFZ: fprintf (stderr, "TAC_IFZ"); break;
		case TAC_LABEL: fprintf (stderr, "TAC_LABEL"); break;
		case TAC_JUMP: fprintf (stderr, "TAC_JUMP"); break;
		case TAC_VECTOR_INDEX: fprintf (stderr, "TAC_VECTOR_INDEX"); break;
		case TAC_VARIABLE_VECTOR: fprintf (stderr, "TAC_VARIABLE_VECTOR"); break;
		case TAC_MOVE_VECTOR: fprintf (stderr, "TAC_MOVE_VECTOR"); break;
		case TAC_ELSE: fprintf (stderr, "TAC_ELSE"); break;
		case TAC_BEGINFUN: fprintf (stderr, "TAC_BEGINFUN"); break;
		case TAC_ENDFUN: fprintf (stderr, "TAC_ENDFUN"); break;
		case TAC_PARAM: fprintf (stderr, "TAC_PARAM"); break;
		case TAC_ARG: fprintf (stderr, "TAC_ARG"); break;
		case TAC_CALL: fprintf (stderr, "TAC_CALL"); break;
		case TAC_CALLRES: fprintf (stderr, "TAC_CALLRES"); break;
		case TAC_RETURN: fprintf (stderr, "TAC_RETURN"); break;
		case TAC_INIT: fprintf (stderr, "TAC_INIT"); break;
		case TAC_INIT_VECTOR: fprintf (stderr, "TAC_INIT_VECTOR"); break;
		case TAC_PRINT: fprintf (stderr, "TAC_PRINT"); break;
		case TAC_READ: fprintf (stderr, "TAC_READ"); break;
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

TAC *makeIf (TAC *code[])
{
	TAC *jumpTac = 0, *jumpTacElse = 0;
	TAC *labelTac = 0, *labelTacElse = 0;
	HASH_NODE *newLabel = 0, *labelElse = 0;

	newLabel = makeLabel();
	jumpTac = tacJoin (code[0], tacCreate (TAC_IFZ, newLabel, code[0] ? code[0]->res : 0, 0));
	labelTac = tacCreate (TAC_LABEL, newLabel, 0, 0);
	if (code[2])
	{
		labelElse = makeLabel();
		labelTacElse = tacCreate (TAC_LABEL, labelElse, 0, 0);
		jumpTacElse = tacCreate (TAC_JUMP, labelElse, 0, 0);
		return tacJoin (tacJoin (tacJoin (tacJoin (tacJoin (jumpTac, code[1]), jumpTacElse), labelTac), code[2]), labelTacElse);
	}
	return tacJoin (tacJoin (jumpTac, code[1]), labelTac);
}

TAC *makeVariable(TAC *code[], AST *node)
{
	if (code[0])
	{
		return tacJoin (code[0], tacCreate (TAC_VARIABLE_VECTOR, makeTemp(), node->symbol, code[0] ? code[0]->res : 0));
	}
	else
	{
		return tacCreate (TAC_SYMBOL, node->symbol, 0, 0);
	}
}

TAC *makeFunction (TAC *code[], AST *node)
{
	TAC *symbol = tacCreate (TAC_SYMBOL, node->symbol, 0, 0);
	return tacJoin (tacJoin (tacJoin (tacCreate (TAC_BEGINFUN, symbol->res, 0, 0), code[1]), code[2]), tacCreate (TAC_ENDFUN, symbol->res, 0, 0));
}

TAC *makeFunctionCall (TAC *code[], AST *node)
{
	HASH_NODE *newLabel = makeLabel();
	return tacJoin (tacJoin (tacJoin (tacCreate (TAC_CALL, node->symbol, newLabel, 0), code[0]), 
	tacJoin (tacCreate (TAC_JUMP, node->symbol, 0, 0), tacCreate (TAC_LABEL, newLabel, 0, 0))), tacCreate (TAC_CALLRES, makeTemp(), 0, 0));
}

TAC *makePrint(TAC *code[], AST *node)
{
	if (code[1])
	{
		return tacJoin (tacJoin (code[0], tacCreate (TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0)), code[1]);
	}
	else
	{
		if (node->symbol)
			{
				return tacJoin (tacCreate (TAC_PRINT, node->symbol, 0, 0), code[0]);
			}
		else
			{
				return tacJoin (code[0], tacCreate (TAC_PRINT, code[0] ? code[0]->res : 0, 0, 0));
			}
	}
}

TAC *makeWhile (TAC *code[])
{
	HASH_NODE* whileLabel = makeLabel();
	HASH_NODE* jumpLabel = makeLabel();

	TAC *whileTac = tacCreate (TAC_IFZ, jumpLabel, code[0] ? code[0]->res : 0, 0);
	TAC *whileLabelTac = tacCreate (TAC_LABEL, whileLabel, 0, 0);
	TAC *jumpTac = tacCreate (TAC_JUMP, whileLabel, 0, 0);
	TAC *jumpLabelTac = tacCreate (TAC_LABEL, jumpLabel, 0, 0);

	return tacJoin (tacJoin (tacJoin (tacJoin (tacJoin (whileLabelTac, code[0]), whileTac), code[1]), jumpTac), jumpLabelTac);
}

TAC *generateCode (AST *node)
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
			result = tacJoin (code[0], tacCreate (TAC_MOVE, node->symbol, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_ATRIB_VETOR:
			result = tacJoin (code[1], tacJoin (code[0], tacCreate (TAC_MOVE_VECTOR, node->symbol, code[0] ? code[0]->res : 0, code[1] ? code[1]->res : 0)));
			break;
		case AST_IF:
			result = makeIf(code);
			break;
		case AST_ELSE:
			result = tacJoin (code[0], tacCreate (TAC_ELSE, code[0] ? code[0]->res : 0, 0, 0));
			break;
		case AST_VARIABLE:
			result = makeVariable (code, node);
			break;
		//case AST_ACCESS_VECTOR:
		//	result = tacJoin (code[0], tacCreate (TAC_VECTOR_INDEX, code[0] ? code[0]->res : 0, 0, 0));
		//	break;
		case AST_DEC_FUNC:
			result = makeFunction (code, node);
			break;
		case AST_PARAM:
			result = tacCreate (TAC_PARAM, node->symbol, 0, 0);
			break;
		case AST_LIST_ARGUMENTS:
			result = tacJoin (tacJoin (code[0], tacCreate (TAC_ARG, code[0]->res, 0, 0)), code[1]);
			break;
		case AST_FUNC_CALL:
			//result = makeFunctionCall (code, node);
			result = tacJoin (code[0], tacCreate (TAC_CALL, makeTemp(), node->symbol, 0));
			break;
		case AST_RETURN:
			result = tacJoin (code[0], tacCreate (TAC_RETURN, code[0] ? code[0]->res : 0, 0, 0));
			break;
		case AST_DEC_VARIABLE:
			result = tacJoin (code[1], tacCreate (TAC_MOVE, node->symbol, code[1] ? code[1]->res : 0, 0));
			break;
		case AST_DEC_VECTOR:
			result = tacJoin (code[2] ,tacJoin (code[1], tacCreate (TAC_INIT_VECTOR, node->symbol, code[1] ? code[1]->res : 0, 0)));
			break;
		case AST_DEC_VECTOR_SIZE:
			result = tacJoin (code[0], tacCreate (TAC_VECTOR_INDEX, node->symbol, 0, 0));
			break;
		case AST_LIST_ELEMENTS_STRING:
			result = makePrint (code, node);
			break;
		case AST_LIST_ELEMENTS_EXPR:
			result = makePrint (code, node);
			break;
		case AST_READ:
			result = tacJoin(code[0], tacCreate (TAC_READ, node->symbol, code[0] ? code[0]->res : 0, 0));
			break;
		case AST_WHILE:
			result = makeWhile (code);
			break;
		default:
			result = tacJoin (code[0], tacJoin (code[1], tacJoin (code[2], code[3])));
			break;
	}
	return result;
}

TAC *tacReverse(TAC *tac)
{
	TAC *t = tac;

	if (t)
	{
		for (t = tac; t->prev; t = t->prev)
		{
			t->prev->next = t;
		}
		return t;
	}
	return 0;
}