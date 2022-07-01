/*
Trabalho Pratico de Compiladores
Tiago de Carvalho Magnus - 00287710
Pedro Hoerlle de Oliveira - 00288548
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "hash.h"

extern char *yytext;
extern FILE *yyin;

int main(int argc, char** argv)
{
  FILE *gold = 0;
  int token = 0;
  int rd = 0;
  int lineNr = 0;
  int i=1;

  if (0==(yyin = fopen(argv[1],"r")))
  {
    printf("Cannot open file %s... \n",argv[1]);
    exit(1);
  }

  if (0==(gold = fopen(argv[2],"r")))
  {
    printf("Cannot open file %s... \n",argv[2]);
    exit(1);
  }

  while (isRunning())
  {
    if (!isRunning())
      break;

    token = yylex();
		// if(lineNr != getLineNumber()){
		// 	lineNr = getLineNumber();
		// 	printLineNumber();
		// }
    fscanf(gold,"%d",&rd);

    switch(rd){
      case KW_CHAR: 		  printf("KW_CHAR "); break;
			case KW_INT: 		    printf("KW_INT "); break;
			case KW_FLOAT: 		  printf("KW_FLOAT "); break;

      case KW_IF:         printf("KW_IF "); break;
      case KW_ELSE:       printf("KW_ELSE "); break;
      case KW_WHILE:      printf("KW_WHILE "); break;
      case KW_READ:       printf("KW_READ "); break;
      case KW_PRINT:      printf("KW_PRINT "); break;
      case KW_RETURN:     printf("KW_RETURN "); break;

      case ASSIGNMENT:    printf("ASSIGNMENT "); break;
      case OPERATOR_LE:   printf("OPERATOR_LE "); break;
      case OPERATOR_GE:   printf("OPERATOR_GE "); break;
      case OPERATOR_EQ:   printf("OPERATOR_EQ "); break;
      case OPERATOR_DIF:  printf("OPERATOR_DIF "); break;

      case TK_IDENTIFIER: printf("TK_IDENTIFIER "); break;
      case LIT_INTEGER:   printf("LIT_INTEGER "); break;
      case LIT_FLOAT:     printf("LIT_FLOAT "); break;
      case LIT_CHAR:      printf("LIT_CHAR "); break;
      case LIT_STRING:    printf("LIT_STRING "); break;
			case TOKEN_ERROR:	  printf("TOKEN_ERROR "); break;

			default: 			      printf("%s ", yytext); break;
		}
  }

  hashPrint();
  printLineNumber();
}
