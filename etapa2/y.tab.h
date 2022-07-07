/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 291,                 /* error  */
    YYUNDEF = 292,                 /* "invalid token"  */
    KW_CHAR = 256,                 /* KW_CHAR  */
    KW_INT = 257,                  /* KW_INT  */
    KW_FLOAT = 258,                /* KW_FLOAT  */
    KW_IF = 261,                   /* KW_IF  */
    KW_ELSE = 263,                 /* KW_ELSE  */
    KW_WHILE = 264,                /* KW_WHILE  */
    KW_READ = 266,                 /* KW_READ  */
    KW_PRINT = 267,                /* KW_PRINT  */
    KW_RETURN = 268,               /* KW_RETURN  */
    ASSIGNMENT = 269,              /* ASSIGNMENT  */
    OPERATOR_LE = 270,             /* OPERATOR_LE  */
    OPERATOR_GE = 271,             /* OPERATOR_GE  */
    OPERATOR_EQ = 272,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 273,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 280,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 281,             /* LIT_INTEGER  */
    LIT_FLOAT = 282,               /* LIT_FLOAT  */
    LIT_CHAR = 285,                /* LIT_CHAR  */
    LIT_STRING = 286,              /* LIT_STRING  */
    TOKEN_ERROR = 290              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 291
#define YYUNDEF 292
#define KW_CHAR 256
#define KW_INT 257
#define KW_FLOAT 258
#define KW_IF 261
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_READ 266
#define KW_PRINT 267
#define KW_RETURN 268
#define ASSIGNMENT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_DIF 273
#define TK_IDENTIFIER 280
#define LIT_INTEGER 281
#define LIT_FLOAT 282
#define LIT_CHAR 285
#define LIT_STRING 286
#define TOKEN_ERROR 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
