/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

int main(int argc, char **argv)
{
//  int tok;
    if (argc < 2)
        {
            fprintf(stderr,"Call: ./etapa1 input.txt\n");
            exit(1);
        }
    if ((yyin = fopen(argv[1],"r")) == 0)
        {
            printf("Cannot open file %s... \n",argv[1]);
            exit(2);
        }

/*
    while(isRunning())
    {
        tok = yylex();
        if (!isRunning())
            break;
        switch(tok)
        {
            case KW_CHAR: printf("KW_CHAR na linha %d\n", getLineNumber()); break;
            case KW_INT: printf("KW_INT na linha %d\n", getLineNumber()); break;
            case KW_FLOAT: printf("KW_FLOAT na linha %d\n", getLineNumber()); break;
            case KW_IF: printf("KW_IF na linha %d\n", getLineNumber()); break;
            case KW_ELSE: printf("KW_ELSE na linha %d\n", getLineNumber()); break;
            case KW_WHILE: printf("KW_WHILE na linha %d\n", getLineNumber()); break;
            case KW_READ: printf("KW_READ na linha %d\n", getLineNumber()); break;
            case KW_PRINT: printf("KW_PRINT na linha %d\n", getLineNumber()); break;
            case KW_RETURN: printf("KW_RETURN na linha %d\n", getLineNumber()); break;
            case ASSIGNMENT: printf("ASSIGNMENT na linha %d\n", getLineNumber()); break;
            case OPERATOR_LE: printf("OPERATOR_LE na linha %d\n", getLineNumber()); break;
            case OPERATOR_GE: printf("OPERATOR_GE na linha %d\n", getLineNumber()); break;
            case OPERATOR_EQ: printf("OPERATOR_EQ na linha %d\n", getLineNumber()); break;
            case OPERATOR_DIF: printf("OPERATOR_DIF na linha %d\n", getLineNumber()); break;
            case TK_IDENTIFIER: printf("TK_IDENTIFIER na linha %d\n", getLineNumber()); break;
            case LIT_INTEGER: printf("LIT_INTEGER na linha %d\n", getLineNumber()); break;
            case LIT_CHAR: printf("LIT_CHAR na linha %d\n", getLineNumber()); break;
            case LIT_FLOAT: printf("LIT_FLOAT na linha %d\n", getLineNumber()); break;
            case LIT_STRING: printf("LIT_STRING na linha %d\n", getLineNumber()); break;
            case TOKEN_ERROR: printf("TOKEN_ERROR na linha %d\n", getLineNumber()); break;
            default: printf("%c na linha %d\n", tok, getLineNumber()); break; 
        }
    }
*/

    initMe();
    yyparse();
    printf("Main done! File has %d lines\n", getLineNumber());
    hashPrint();
    printf("Sucesso\n");
    exit(0);
}
