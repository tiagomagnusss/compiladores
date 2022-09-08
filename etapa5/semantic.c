
#include "semantic.h"

int semanticErrors = 0;
// Implementations

void setDeclarations(AST* node) {
	int i;

	if (!node) return;
	if (!node->symbol) return;

	if (node->type == AST_DEC_VARIABLE){
		if (node->symbol->type == SYMBOL_IDENTIFIER){
			if (node->son[0]->type == AST_INT)
				node->symbol->datatype = DATATYPE_INT;
			else if (node->son[0]->type == AST_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
		} else {
			fprintf(stderr, "Semantic error: symbol %s redeclared.\n", node->symbol->text);
			++semanticErrors;
		}
	}

	if (node->type == AST_DEC_FUNC){
		if (node->symbol->type == SYMBOL_IDENTIFIER){
			if (node->son[0]->type == AST_INT)
				node->symbol->datatype = DATATYPE_INT;
			else if (node->son[0]->type == AST_FLOAT)
				node->symbol->datatype = DATATYPE_FLOAT;
		} else {
			fprintf(stderr, "Semantic error: symbol %s redeclared.\n", node->symbol->text);
			++semanticErrors;
		}
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
		for (node = Table[i]; node; node = node->next)
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

	for(int i=0; i<MAX_SONS; ++i){
		setDeclarations(node->son[i]);
	}

	switch(node->type){
		case AST_ADD:
		case AST_SUB:
		// TODO complete
			if (1==1){
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
