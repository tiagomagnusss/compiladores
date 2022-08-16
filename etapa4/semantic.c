
#include "semantic.h"

int semanticErrors = 0;
// Implementations

void setDeclarations(AST* node) {
	int i;
	
	if (!node) return;

	if (node->type == AST_DECVARIABLE){
		if (node->symbol){
			if (node->symbol->type == SYMBOL_IDENTIFIER){
				if (node->son[0]->type == AST_TYPEINT)
					node->symbol->datatype = DATATYPE_INT;
				else (node->son[0]->type == AST_TYPEFLOAT)
					node->symbol->datatype = DATATYPE_INT;
					
				node->symbol->type = SYMBOL_VARIABLE;
			} else {
				fprintf(stderr, "Semantic error: symbol %s  redeclared.\n", node->text);
				++semanticErrors;
			}
		else
			//message semnsimbolo
	}

	if (node->type == AST_DECFUNCTION){
		//same as vars
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

void checkOperands(AST* node){
	if (!node) return;

	for(i=0; i<MAXSONS; ++i){
		setDeclarations(node->son[i]);
	}

	switch(node->type){
		case AST_ADD:
		case AST_SUB:
		// TODO complete
			if (){
				//ok
				// evaluate children
				// check types
			} else {
				fprintf(stderr, "Sem error operands don't match.\n");
				++semanticErrors;
			}
		break;
	}
}
