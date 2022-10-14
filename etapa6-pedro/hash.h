/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_SIZE 997

#define SYMBOL_VARIABLE 6
#define SYMBOL_LABEL 9

typedef struct hash_node
{
	int type;
	char *text;
	struct hash_node *next;
} HASH_NODE;

void hashInit (void);
int hashAddress (char *text);
HASH_NODE *hashFind (char *text);
HASH_NODE *hashInsert (char *text, int type);
void hashPrint (void);
HASH_NODE *makeTemp (void);
HASH_NODE *makeLabel (void);

void printAsm(FILE *fout);

#endif