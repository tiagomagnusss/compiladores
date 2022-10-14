/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

HASH_NODE* Table[HASH_SIZE];

void hashInit (void)
{
	int i;

	for (i = 0; i < HASH_SIZE; ++i)
	{
		Table[i] = 0;
	}
}

int hashAddress (char *text)
{
	int address = 1;
	int i;

	for (i = 0; i < strlen (text); ++i)
	{
		address = (address *text[i]) % HASH_SIZE + 1;
	}
	return address - 1;
}

HASH_NODE *hashFind (char *text)
{
	HASH_NODE *node;
	int address = hashAddress (text);

	for (node = Table[address]; node; node = node->next)
	{
		if (strcmp(node->text,text) == 0)
		{
			return node;
		}
	}
	return 0;
}

HASH_NODE *hashInsert (char *text, int type)
{
	HASH_NODE *newnode;
	int address = hashAddress (text);

	if ((newnode = hashFind (text)) != 0)
	{
		return newnode;
	}
	newnode = (HASH_NODE *) calloc (1, sizeof(HASH_NODE));
	newnode->type = type;
	newnode->text = (char *) calloc (strlen (text) + 1, sizeof(char));
	strcpy (newnode->text, text);
	newnode->next = Table[address];
	Table[address] = newnode;
	return newnode;
}

void hashPrint (void)
{
	int i;
	HASH_NODE *node;

	for (i = 0; i < HASH_SIZE; ++i)
	{
		for (node = Table[i]; node; node = node->next)
		{
			printf ("Table[%d] has %s\n",i,node->text);
		}
	}
}

void printAsm(FILE* fout){
	HASH_NODE *node;

	fprintf(fout, "## DATA SECTION\n\n");

	for(int i = 0; i < HASH_SIZE; i++) {
		for(node = Table[i]; node; node = node->next){
			if (strncmp(node->text, "Temp", 4) == 0){
				fprintf(fout, "\t.globl	_%s\n"
										 "\t.data\n"
										 "\t.type	_%s, @object\n"
										 "\t.size	_%s, 4\n"
										 "_%s:\n", node->text, node->text, node->text, node->text);

				fprintf(fout, "\t.long  0\n");
			}
		}
	}
}

HASH_NODE *makeTemp (void)
{
	static int serialNumber = 0;
	char buffer[256] = "";
	sprintf (buffer, "Temp%d", serialNumber++);
	return hashInsert (buffer, SYMBOL_VARIABLE);
}

HASH_NODE *makeLabel (void)
{
	static int serialNumber = 0;
	char buffer[256] = "";
	sprintf (buffer, "Label%d", serialNumber++);
	return hashInsert (buffer, SYMBOL_LABEL);
}

HASH_NODE** getTable(){
	return Table;
}
