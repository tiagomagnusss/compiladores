/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include "ast.h"

extern FILE *output;

AST *astCreate (int type, HASH_NODE *symbol, AST *son0, AST *son1, AST *son2, AST *son3)
{
    AST* newnode;
    newnode = (AST*) calloc (1, sizeof(AST));
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
        case AST_VECTOR: fprintf (stderr, "AST_VECTOR"); break;
        case AST_FUNC_CALL: fprintf (stderr, "AST_FUNC_CALL"); break;
        case AST_ASSOCITIVITY: fprintf (stderr, "AST_ASSOCITIVITY"); break;
        case AST_NOT: fprintf (stderr, "AST_NOT"); break;
        case AST_LIST_ARGUMENTS: fprintf (stderr, "AST_LIST_ARGUMENTS"); break;
        //case AST: fprintf (stderr, "AST"); break;
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
        case AST_SYMBOL:
            fprintf (output, "%s", node->symbol->text);
            break;
        default: break;
    }
}