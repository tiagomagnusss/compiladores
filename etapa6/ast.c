/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <stdlib.h>
#include <stdio.h>

#include "ast.h"

extern FILE *output;

AST *astCreate (int type, HASH_NODE *symbol, AST *son0, AST *son1, AST *son2, AST *son3)
{
	AST *newnode;
	newnode = (AST *) calloc (1, sizeof(AST));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
	return newnode;
}

void astPrint (AST *node, int level)
{
	int i = 0;

	if (node == 0)
	{
		return;
	}
	for (i = 0; i < level; ++i)
	{
		fprintf (stderr, "  ");
	}
	fprintf (stderr, "AST(");
	switch (node->type)
	{
		case AST_SYMBOL: fprintf (stderr, "AST_SYMBOL"); break;
		case AST_ADD: fprintf (stderr, "AST_ADD"); break;
		case AST_SUB: fprintf (stderr, "AST_SUB"); break;
		case AST_DIV: fprintf (stderr, "AST_DIV"); break;
		case AST_MUL: fprintf (stderr, "AST_MUL"); break;
		case AST_LT: fprintf (stderr, "AST_LT"); break;
		case AST_GT: fprintf (stderr, "AST_GT"); break;
		case AST_LE: fprintf (stderr, "AST_LE"); break;
		case AST_GE: fprintf (stderr, "AST_GE"); break;
		case AST_EQ: fprintf (stderr, "AST_EQ"); break;
		case AST_DIF: fprintf (stderr, "AST_DIF"); break;
		case AST_AND: fprintf (stderr, "AST_AND"); break;
		case AST_OR: fprintf (stderr, "AST_OR"); break;
		case AST_VARIABLE: fprintf (stderr, "AST_VARIABLE"); break;
		case AST_FUNC_CALL: fprintf (stderr, "AST_FUNC_CALL"); break;
		case AST_ASSOCITIVITY: fprintf (stderr, "AST_ASSOCITIVITY"); break;
		case AST_NOT: fprintf (stderr, "AST_NOT"); break;
		case AST_LIST_ARGUMENTS: fprintf (stderr, "AST_LIST_ARGUMENTS"); break;
		case AST_LIST_ELEMENTS_STRING: fprintf (stderr, "AST_LIST_ELEMENTS_STRING"); break;
		case AST_LIST_ELEMENTS_EXPR: fprintf (stderr, "AST_LIST_ELEMENTS_EXPR"); break;
		case AST_RETURN: fprintf (stderr, "AST_RETURN"); break;
		case AST_READ: fprintf (stderr, "AST_READ"); break;
		case AST_PRINT: fprintf (stderr, "AST_PRINT"); break;
		case AST_WHILE: fprintf (stderr, "AST_WHILE"); break;
		case AST_ELSE: fprintf (stderr, "AST_ELSE"); break;
		case AST_IF: fprintf (stderr, "AST_IF"); break;
		case AST_ATRIB_VARIAVEL: fprintf (stderr, "AST_ATRIB_VARIAVEL"); break;
		case AST_ATRIB_VETOR: fprintf (stderr, "AST_ATRIB_VETOR"); break;
		case AST_BLOCK: fprintf (stderr, "AST_BLOCK"); break;
		case AST_RESTO: fprintf (stderr, "AST_RESTO"); break;
		case AST_CHAR: fprintf (stderr, "AST_CHAR"); break;
		case AST_INT: fprintf (stderr, "AST_INT"); break;
		case AST_FLOAT: fprintf (stderr, "AST_FLOAT"); break;
		case AST_RESTO_PARAMS: fprintf (stderr, "AST_RESTO_PARAMS"); break;
		case AST_PARAM: fprintf (stderr, "AST_PARAM"); break;
		case AST_LISTA_PARAMS: fprintf (stderr, "AST_LISTA_PARAMS"); break;
		case AST_INIT: fprintf (stderr, "AST_INIT"); break;
		case AST_DEC_FUNC: fprintf (stderr, "AST_DEC_FUNC"); break;
		case AST_DEC_VECTOR: fprintf (stderr, "AST_DEC_VECTOR"); break;
		case AST_DEC_VECTOR_SIZE: fprintf (stderr, "AST_DEC_VECTOR_SIZE"); break;
		case AST_DEC_VARIABLE: fprintf (stderr, "AST_DEC_VARIABLE"); break;
		case AST_LIST_DEC: fprintf (stderr, "AST_LIST_DEC"); break;
		case AST_ACCESS_VECTOR: fprintf (stderr, "AST_ACCESS_VECTOR"); break;
		case AST_PROGRAM: fprintf (stderr, "AST_PROGRAM"); break;
		default: fprintf (stderr, "AST_UNKNOWN"); break;
	}
	if (node->symbol != 0)
	{
		fprintf (stderr, ", %s\n", node->symbol->text);
	}
	else
	{
		fprintf (stderr, ", 0\n");
	}
	for (i = 0; i < MAX_SONS; ++i)
	{
		astPrint (node->son[i], level + 1);
	}
}

void astDecompile (AST *node)
{
	if (node == 0)
	{
		return;
	}
	switch (node->type)
	{
		case AST_PROGRAM:
			astDecompile (node->son[0]);
			break;
		case AST_LIST_DEC:
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_DEC_VARIABLE:
			astDecompile (node->son[0]);
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, " (");
			astDecompile (node->son[1]);
			fprintf (output, ");");
			fprintf (output, "\n");
			break;
		case AST_DEC_VECTOR:
			astDecompile (node->son[0]);
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, "[");
			astDecompile (node->son[1]);
			fprintf (output, "]");
			astDecompile (node->son[2]);
			fprintf (output, ";");
			fprintf (output, "\n");
			break;
		case AST_DEC_VECTOR_SIZE:
			fprintf (output, "%s", node->symbol->text);
			break;
		case AST_DEC_FUNC:
			astDecompile (node->son[0]);
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, " (");
			astDecompile (node->son[1]);
			fprintf (output, ")");
			astDecompile (node->son[2]);
			fprintf (output, "\n");
			break;
		case AST_INIT:
			fprintf (output, " ");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_SYMBOL:
			fprintf (output, "%s", node->symbol->text);
			break;
		case AST_LIST_ARGUMENTS:
			fprintf (output, " ");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_BLOCK:
			fprintf (output, "\n");
			fprintf (output, "{");
			fprintf (output, "\n");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			fprintf (output, "\n");
			fprintf (output, "}");
			fprintf (output, "\n");
			break;
		case AST_RESTO:
			fprintf (output, ";");
			fprintf (output, "\n");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_LISTA_PARAMS:
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_PARAM:
			astDecompile (node->son[0]);
			fprintf (output, "%s", node->symbol->text);
			break;
		case AST_RESTO_PARAMS:
			fprintf (output, " ");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_CHAR:
			fprintf (output, "char ");
			break;
		case AST_INT:
			fprintf (output, "int ");
			break;
		case AST_FLOAT:
			fprintf (output, "float ");
			break;
		case AST_ATRIB_VARIAVEL:
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, " <- ");
			astDecompile (node->son[0]);
			break;
		case AST_ATRIB_VETOR:
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, "[");
			astDecompile (node->son[0]);
			fprintf (output, "] <- ");
			astDecompile (node->son[1]);
			break;
		case AST_IF:
			fprintf (output, "if (");
			astDecompile (node->son[0]);
			fprintf (output, ")");
			astDecompile (node->son[1]);
			astDecompile (node->son[2]);
			break;
		case AST_ELSE:
			fprintf (output, " else ");
			astDecompile (node->son[0]);
			break;
		case AST_WHILE:
			fprintf (output, "while (");
			astDecompile (node->son[0]);
			fprintf (output, ")");
			astDecompile (node->son[1]);
			break;
		case AST_PRINT:
			fprintf (output, "print");
			astDecompile (node->son[0]);
			break;
		case AST_READ:
			fprintf (output, "read ");
			fprintf (output, "%s", node->symbol->text);
			astDecompile (node->son[0]);
			break;
		case AST_ACCESS_VECTOR:
			fprintf (output, "[");
			astDecompile (node->son[0]);
			fprintf (output, "]");
			break;
		case AST_RETURN:
			fprintf (output, "return ");
			astDecompile (node->son[0]);
			break;
		case AST_LIST_ELEMENTS_STRING:
			fprintf (output, " ");
			fprintf (output, "%s", node->symbol->text);
			astDecompile (node->son[0]);
			break;
		case AST_LIST_ELEMENTS_EXPR:
			fprintf (output, " ");
			astDecompile (node->son[0]);
			astDecompile (node->son[1]);
			break;
		case AST_VARIABLE:
			fprintf (output, "%s", node->symbol->text);
			astDecompile (node->son[0]);
			break;
		case AST_FUNC_CALL:
			fprintf (output, "%s", node->symbol->text);
			fprintf (output, " (");
			astDecompile (node->son[0]);
			fprintf (output, ")");
			break;
		case AST_ADD:
			astDecompile (node->son[0]);
			fprintf (output, " + ");
			astDecompile (node->son[1]);
			break;
		case AST_SUB:
			astDecompile (node->son[0]);
			fprintf (output, " - ");
			astDecompile (node->son[1]);
			break;
		case AST_DIV:
			astDecompile (node->son[0]);
			fprintf (output, " / ");
			astDecompile (node->son[1]);
			break;
		case AST_MUL:
			astDecompile (node->son[0]);
			fprintf (output, " . ");
			astDecompile (node->son[1]);
			break;
		case AST_LT:
			astDecompile (node->son[0]);
			fprintf (output, " < ");
			astDecompile (node->son[1]);
			break;
		case AST_GT:
			astDecompile (node->son[0]);
			fprintf (output, " > ");
			astDecompile (node->son[1]);
			break;
		case AST_ASSOCITIVITY:
			fprintf (output, "(");
			astDecompile (node->son[0]);
			fprintf (output, ")");
			break;
		case AST_LE:
			astDecompile (node->son[0]);
			fprintf (output, " <= ");
			astDecompile (node->son[1]);
			break;
		case AST_GE:
			astDecompile (node->son[0]);
			fprintf (output, " >= ");
			astDecompile (node->son[1]);
			break;
		case AST_EQ:
			astDecompile (node->son[0]);
			fprintf (output, " == ");
			astDecompile (node->son[1]);
			break;
		case AST_DIF:
			astDecompile (node->son[0]);
			fprintf (output, " != ");
			astDecompile (node->son[1]);
			break;
		case AST_AND:
			astDecompile (node->son[0]);
			fprintf (output, " & ");
			astDecompile (node->son[1]);
			break;
		case AST_OR:
			astDecompile (node->son[0]);
			fprintf (output, " | ");
			astDecompile (node->son[1]);
			break;
		case AST_NOT:
			fprintf (output, "~");
			astDecompile (node->son[0]);
			break;
		default: break;
	}
}