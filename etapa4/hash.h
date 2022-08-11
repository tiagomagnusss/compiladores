/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 997

#define SYMBOL_IDENTIFIER 1
#define SYMBOL_LIT_INT 2
#define SYMBOL_VARIABLE 3
#define SYMBOL_FUNCTION 4

#define DATATYPE_INT 1
#define DATATYPE_FLOAT 2
#define DATATYPE_BOOL 3 //opt

typedef struct hash_node
{
    int type;
    int datatype;
    char *text;
    struct hash_node * next;
} HASH_NODE;

void hashInit (void);
int hashAddress (char *text);
HASH_NODE *hashFind (char *text);
HASH_NODE *hashInsert (char *text, int type);
void hashPrint (void);

#endif
