#Trabalho Pratico de Compiladores
#Tiago de Carvalho Magnus - 00287710
#Pedro Hoerlle de Oliveira - 00288548


#Make 1
# Makefile for single compiler call
# All source files must be included from code embedded in scanner.l
# In our case, you probably need #include "hash.c" at the beginning
# and #include "main.c" in the last part of the scanner.l

#etapa2: y.tab.c lex.yy.c
#	gcc -Wall -o etapa2 y.tab.c lex.yy.c
#
#y.tab.c: parser.y
#	yacc -d parser.y
#
#lex.yy.c: scanner.l
#	flex scanner.l
#
#clean:
#	rm -f lex.yy.c y.tab.* y.output etapa2

#Make 2
# Makefile for two compiler calls
# The code generated by lex and main.c are separately compiled
# You must include lex.yy.h in your main as well as the definition of
# other interfaces like getLineNumber, initMe, running...
# Use make clean to remove old files before remaking everything

#etapa1: lex.yy.o main.o
#	gcc -o etapa1 lex.yy.o main.o
#main.o: main.c
#	gcc -c main.c
#lex.yy.o: lex.yy.c
#	gcc -c lex.yy.c
#lex.yy.c: scanner.l
#	flex --header-file=lex.yy.h scanner.l
#clean:
#	rm *.o lex.yy.c etapa1

#Make 3
# Makefile for three compiler calls
# Read the comments on Makefile2. All of them apply here too.
# But now the hash table is compiled in a separate gcc call
# Therefore, there must be a header of it to be included in scanner.l

etapa3: y.tab.o lex.yy.o hash.o ast.o main.o
	gcc -Wall main.o lex.yy.o y.tab.o hash.o ast.o -o etapa3

main.o: main.c
	gcc -Wall -c main.c

hash.o: hash.c
	gcc -Wall -c hash.c

ast.o: ast.c
	gcc -Wall -c ast.c

y.tab.o: y.tab.c
	gcc -Wall -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

clean:
	rm lex.yy.c lex.yy.h y.tab.c y.tab.h *.o etapa3
