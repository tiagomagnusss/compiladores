/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <stdio.h>

#include "asm.h"

void generateAsm(TAC* first)
{
	TAC *tac;
	FILE *fout;
	fout = fopen("out.s", "w");

	//int LC = 2;
	
	// INIT
	fprintf(fout, "## FIXED INIT\n"
			"\t.section	.rodata\n\n");
	
	// HASH TABLE
	printAsm(fout);

	//EACH TAC

	for (tac = first; tac; tac = tac->next)
	{
		switch (tac->type)
		{
			case TAC_BEGINFUN:
				fprintf(fout,	"## TAC BEGIN_FUNCTION\n"
								"\t.globl	_%s\n"
								"\t.type	_%s, @function\n" 
								"_%s:\n"
								"\tpushq	%%rbp\n"
								"\tmovq	%%rsp, %%rbp\n\n",
								tac->res->text,tac->res->text,tac->res->text);
				break;
			case TAC_ENDFUN:
				fprintf(fout, "## TAC END_FUNCTION\n"
								"\tpopq	%%rbp\n"
								"\tret\n");
				break;
			case TAC_PRINT: 
				fprintf(fout, "## PRINT\n"
								"\tmovl	_%s(%%rip), %%eax\n"
								"\tmovl	%%eax, %%esi\n"
								"\tleaq	.printIntStr(%%rip), %%rdi\n"
								"\tmovl	$0, %%eax\n"
								"\tcall	_printf@PLT\n\n",
								tac->res?tac->res->text:"");
				break; 
		}
	}

	fclose(fout);

}