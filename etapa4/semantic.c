
#include "semantic.h"

int semanticErrors = 0;
// Implementations

void setDeclarations(AST* node) {
	int i;
	
	if (!node) return;

	if (node->type == AST_DECVARIABLE){
		if (node->symbol){
			if (node->type == SYMBOL_IDENTIFIER)
				node->type = SYMBOL_VARIABLE;
			else {
				fprintf(stderr, "Semantic error: symbol %s  redeclared.\n", node->text);
				++semanticErrors;
			}
		else
			//message semnsimbolo
	}
	
	for (i = 0; i < MAX_SONS; ++i)
	{
		setDeclarations(node->son[i]);
	}	
}

void checkUndeclared(){
	int i;
	HASH_NODE* node;

	for (i=0; i<HASH_SIZE; i++)
		for (node=Table[i]; node; node = node->next)
			if (node->type == SYMBOL_IDENTIFIER){
				fprintf(stderr, "Semantic error: symbol %s is undeclared.\n", node->text);
				++semanticErrors;
			}
}

int getSemanticErrors(){
	return semanticErrors;
}
