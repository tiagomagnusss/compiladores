
#include "ast.h"

// Prototypes

void setDeclarations(AST* node);
void checkUndeclared();
int getSemanticErrors();
void checkOperands(AST* node);
