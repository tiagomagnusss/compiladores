/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tacs.h"
#include "ast.h"
#include "hash.h"
#include "y.tab.h"

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
			result =  tacJoin (code[1], tacCreate (TAC_MOVE, node->symbol, code[1] ? code[1]->res : 0, 0));
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

// ASM GENERATION
TAC* tacReverse(TAC* tac) {
	TAC* t = tac;
	for ( t = tac; t->prev; t = t->prev){
		t->prev->next = t;
	}

	return t;
}

void generateConstants(FILE* fout){
	fprintf(fout, "## INIT CONSTANTS\n");

	for(int i = 0; i < HASH_SIZE; i++) {
		for(HASH_NODE *node = getTable()[i]; node; node = node->next){
			if (node->type == LIT_FLOAT) {
				//?
			} else if (node->type == LIT_INTEGER || node->type == LIT_CHAR) {
				fprintf(fout, "\t.globl	_%s\n"
										"\t.data\n"
										"\t.type	_%s, @object\n"
										"\t.size	_%s, 4\n"
										"_%s:\n", node->text, node->text, node->text, node->text);
				fprintf(fout, "\t.long  %s\n", node->text);
			}
		}
	}
	fprintf(fout, "## FINISH OF CONSTANTS\n\n");
}

void generateData(FILE* fout, AST* node){
	if(!node) return;
	static int LC = 2;

	if (node->type == AST_DEC_VARIABLE){
		fprintf(fout, "\t.globl	_%s\n"
										"\t.data\n"
										"\t.type	_%s, @object\n"
										"\t.size	_%s, 4\n"
										"_%s:\n", node->symbol->text, node->symbol->text,
										node->symbol->text, node->symbol->text);
		fprintf(fout, "\t.long   %s\n", node->son[1]->symbol->text);
	} else if (node->type == AST_DEC_VECTOR){
    fprintf(fout, "\t.globl	_%s\n"
									"\t.data\n"
									"\t.type	_%s, @object\n"
									"\t.size	_%s, %d\n"
									"_%s:\n", node->symbol->text, node->symbol->text, node->symbol->text,
									4*atoi(node->son[1]->symbol->text), node->symbol->text);

    for(AST* child = node->son[2]; child; child = child->son[1]) {
			fprintf(fout, "\t.long	%s\n", child->son[0]->symbol->text);
    }
	} else if (node->type == AST_LIST_ELEMENTS_STRING){
		fprintf(fout, "\t.section\t .rodata\n"
			".LC%d:\n"
				"\t.string %s \n", LC, node->symbol->text);
		LC++;
	} else if (node->type == AST_PARAM){
  	fprintf(fout, "\t.globl	_%s\n"
                  "\t.data\n"
                  "\t.type	_%s, @object\n"
                  "\t.size	_%s, 4\n"
                  "_%s:\n", node->symbol->text, node->symbol->text, node->symbol->text, node->symbol->text);
		fprintf(fout, "\t.long	0\n");
	}

	for(int i = 0; i < MAX_SONS; i++){
		generateData(fout, node->son[i]);
	}
}

void generateAsm(TAC* first, AST* ast){
	FILE* fout;
	int LC = 2;
	int TH = 0;
	fout = fopen("out.s", "w+");

	TAC* tac;
	fprintf(fout, "## FIXED INIT\n"
	".LC0:\n"
		"\t.string	\"%%d\"\n"
  	"\t.section	.rodata\n"
	".LC1:\n"
		"\t.string	\"%%f\"\n"
		"\t.section\t .rodata\n");

	generateConstants(fout);
	generateData(fout, ast);

	// Each TAC
	for (tac = first; tac; tac = tac->next){
		switch (tac->type) {
			case TAC_BEGINFUN:
				if (strcmp(tac->res->text, "main") == 0){
					fprintf(fout, "## TAC_BEGINFUN\n"
						"\t.globl %s\n"
						"\t.type	%s, @function\n"
					"%s:\n"
						"\tpushq %%rbp\n"
						"\tmovq %%rsp, %%rbp\n", tac->res->text, tac->res->text, tac->res->text);
				} else {
					fprintf(fout, "## TAC_BEGINFUN\n"
						"\t.globl _%s\n"
						"\t.type	_%s, @function\n"
					"_%s:\n"
						"\tpushq %%rbp\n"
						"\tmovq %%rsp, %%rbp\n", tac->res->text, tac->res->text, tac->res->text);
				}
				break;
			case TAC_ENDFUN:
				fprintf(fout, "\tpopq %%rbp\n"
					"\tretq\n\n"
					"## TAC_ENDFUN\n\n");
				break;
			case TAC_PRINT:
				if (tac->res->text[0] == '\"'){
					fprintf(fout, "## TAC_PRINT STRING\n"
												"\tleaq	.LC%d(%%rip), %%rdi\n"
												"\tmovl	$0, %%eax\n"
												"\tcall	printf@PLT\n", LC++);
				} else if (tac->res->type == LIT_FLOAT) {
					// ?
				} else if (tac->res->type == LIT_CHAR){
					fprintf(fout, "## TAC_PRINT CHAR\n"
												"\tmovl	$%d, %%edi\n"
												"\tcall	putchar@PLT\n", tac->res->text[1]);
				} else {
					fprintf(fout, "## TAC_PRINT INT\n"
												"\tmovl	_%s(%%rip), %%eax\n"
                        "\tmovl	%%eax, %%esi\n"
                        "\tleaq	.LC0(%%rip), %%rdi\n"
                        "\tmovl	$0, %%eax\n"
                        "\tcall	printf@PLT\n", tac->res->text);
				}
				break;
			case TAC_ADD:
				fprintf(fout, "## TAC_ADD\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\taddl %%eax, %%edx\n"
											"\tmovl %%edx, _%s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
				break;
			case TAC_SUB:
				fprintf(fout, "## TAC_SUB\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\tsubl %%eax, %%edx\n"
											"\tmovl %%edx, _%s(%%rip)\n", tac->op2->text, tac->op1->text, tac->res->text);
				break;
			case TAC_DIV:
				fprintf(fout, "## TAC_DIV\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%ecx\n"
											"\tcltd\n"
											"\tidivl %%ecx\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
				break;
			case TAC_MUL:
				fprintf(fout, "## TAC_MUL\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\timull %%eax, %%edx\n"
											"\tmovl %%edx, _%s(%%rip)\n", tac->op1->text, tac->op2->text, tac->res->text);
				break;
			case TAC_LT:
				fprintf(fout, "## TAC_LT\n"
											"\tmovl _%s(%%rip), %%eax\n"
                      "\tmovl _%s(%%rip), %%edx\n"
                      "\tcmpl %%eax, %%edx\n"
                      "\tjl .TH%d\n"
                      "\tmovl $0, %%eax\n"
                      "\tjmp .TH%d\n"
                      ".TH%d:\n"
                      "\tmovl $1, %%eax\n"
                      ".TH%d:\n"
                      "\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_GT:
				fprintf(fout, "## TAC_GT\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\tcmpl %%eax, %%edx\n"
											"\tjg .TH%d\n"
											"\tmovl $0, %%eax\n"
											"\tjmp .TH%d\n"
											".TH%d:\n"
											"\tmovl $1, %%eax\n"
											".TH%d:\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_LE:
				fprintf(fout, "## TAC_LE\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\tcmpl %%eax, %%edx\n"
											"\tjle .TH%d\n"
											"\tmovl $0, %%eax\n"
											"\tjmp .TH%d\n"
											".TH%d:\n"
											"\tmovl $1, %%eax\n"
											".TH%d:\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_GE:
				fprintf(fout, "## TAC_GE\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\tcmpl %%eax, %%edx\n"
											"\tjge .TH%d\n"
											"\tmovl $0, %%eax\n"
											"\tjmp .TH%d\n"
											".TH%d:\n"
											"\tmovl $1, %%eax\n"
											".TH%d:\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_EQ:
				fprintf(fout, "## TAC_EQ\n"
											"\tmovl _%s(%%rip), %%eax\n"
                      "\tmovl _%s(%%rip), %%edx\n"
                      "\tcmpl %%eax, %%edx\n"
                      "\tje .TH%d\n"
                      "\tmovl $0, %%eax\n"
                      "\tjmp .TH%d\n"
                      ".TH%d:\n"
                      "\tmovl $1, %%eax\n"
                      ".TH%d:\n"
                      "\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_DIF:
				fprintf(fout, "## TAC_DIF\n"
											"\tmovl _%s(%%rip), %%eax\n"
                      "\tmovl _%s(%%rip), %%edx\n"
                      "\tcmpl %%eax, %%edx\n"
                      "\tjne .TH%d\n"
                      "\tmovl $0, %%eax\n"
                      "\tjmp .TH%d\n"
                      ".TH%d:\n"
                      "\tmovl $1, %%eax\n"
                      ".TH%d:\n"
                      "\tmovl %%eax, _%s(%%rip)\n", tac->op2->text, tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_AND:
				fprintf(fout, "## TAC_AND\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl _%s(%%rip), %%edx\n"
											"\tandl %%eax, %%edx\n"
											"\tjz .TH%d\n"
											"\tmovl $1, %%eax\n"
											"\tjmp .TH%d\n"
											".TH%d:\n"
											"\tmovl $0, %%eax\n"
											".TH%d:\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op1->text, tac->op2->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_OR:
				fprintf(fout, "## TAC_OR\n"
											"\tmovl _%s(%%rip), %%eax\n"
                      "\tmovl _%s(%%rip), %%edx\n"
                      "\torl %%eax, %%edx\n"
                      "\tjz .TH%d\n"
                      "\tmovl $1, %%eax\n"
                      "\tjmp .TH%d\n"
                      ".TH%d:\n"
                      "\tmovl $0, %%eax\n"
                      ".TH%d:\n"
                      "\tmovl %%eax, _%s(%%rip)\n", tac->op1->text, tac->op2->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_NOT:
				fprintf(fout, "## TAC_NOT\n"
											"\tmovl _%s(%%rip), %%eax\n"
                      "\tmovl $1, %%edx\n"
                      "\tandl %%eax, %%edx\n"
                      "\tjz .TH%d\n"
                      "\tmovl $0, %%eax\n"
                      "\tjmp .TH%d\n"
                      ".TH%d:\n"
                      "\tmovl $1, %%eax\n"
                      ".TH%d:\n"
                      "\tmovl %%eax, _%s(%%rip)\n", tac->op1->text, TH, TH+1, TH, TH+1, tac->res->text);
				TH+=2;
				break;
			case TAC_MOVE:
				fprintf(fout,  "## TAC_MOVE\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl %%eax, _%s(%%rip)\n", tac->op1->text, tac->res->text);
				break;
			case TAC_MOVE_VECTOR:
				break;
			case TAC_IFZ:
				fprintf(fout, "## TAC_IFZ\n"
											"\tmovl _%s(%%rip), %%eax\n"
											"\tmovl $1, %%edx\n"
											"\tandl %%eax, %%edx\n"
											"\tjz .%s\n", tac->op1->text, tac->res->text);
				break;
			case TAC_LABEL:
				fprintf(fout, "## TAC_LABEL\n"
											".%s:\n", tac->res->text);
				break;
			case TAC_JUMP:
				fprintf(fout, "## TAC_JUMP\n"
											"\tjmp .%s\n", tac->res->text);
				break;
			case TAC_VECTOR_INDEX:
				break;
			case TAC_VARIABLE_VECTOR:
				break;
			case TAC_ELSE:
				fprintf(fout, "## TAC_ELSE\n");
				break;
			case TAC_PARAM:
				break;
			case TAC_ARG:
				break;
			case TAC_CALL:
				fprintf(fout, "## TAC_CALL\n"
											"\tcall	_%s\n"
											"\tmovl	%%eax, _%s(%%rip)\n" , tac->op1->text, tac->res->text);
				break;
			case TAC_RETURN:
				fprintf(fout, "## TAC_RETURN\n"
											"\tmovl	_%s(%%rip), %%eax\n"
											"\tpopq	%%rbp\n"
											"\tret\n", tac->res->text);
				break;
			case TAC_READ:
				fprintf(fout, "## TAC_READ\n"
											"\tleaq	_%s(%%rip), %%rsi\n"
											"\tleaq	.LC0(%%rip), %%rdi\n"
											"\tmovl	$0, %%eax\n"
											"\tcall	__isoc99_scanf@PLT\n", tac->res->text);
				break;
			default:
				break;
		}
	}

	// Hash Table
	printAsm(fout);

	fclose(fout);
}

