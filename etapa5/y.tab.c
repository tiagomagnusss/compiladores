/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "parser.y"


#include "hash.h"
#include "ast.h"
#include "semantic.h"
#include "tac.h"

int yylex (void);
int getLineNumber (void);

/* Declaracao correta de yyerror segundo manual */
void yyerror (char const *);


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_IF = 261,                   /* KW_IF  */
    KW_ELSE = 262,                 /* KW_ELSE  */
    KW_WHILE = 263,                /* KW_WHILE  */
    KW_READ = 264,                 /* KW_READ  */
    KW_PRINT = 265,                /* KW_PRINT  */
    KW_RETURN = 266,               /* KW_RETURN  */
    ASSIGNMENT = 267,              /* ASSIGNMENT  */
    OPERATOR_LE = 268,             /* OPERATOR_LE  */
    OPERATOR_GE = 269,             /* OPERATOR_GE  */
    OPERATOR_EQ = 270,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 271,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 272,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 273,             /* LIT_INTEGER  */
    LIT_FLOAT = 274,               /* LIT_FLOAT  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    TOKEN_ERROR = 277              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_ELSE 262
#define KW_WHILE 263
#define KW_READ 264
#define KW_PRINT 265
#define KW_RETURN 266
#define ASSIGNMENT 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INTEGER 273
#define LIT_FLOAT 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

	HASH_NODE *symbol;
	AST *ast;

#line 188 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_IF = 6,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 7,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 8,                   /* KW_WHILE  */
  YYSYMBOL_KW_READ = 9,                    /* KW_READ  */
  YYSYMBOL_KW_PRINT = 10,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 11,                 /* KW_RETURN  */
  YYSYMBOL_ASSIGNMENT = 12,                /* ASSIGNMENT  */
  YYSYMBOL_OPERATOR_LE = 13,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 14,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 15,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 16,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 17,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INTEGER = 18,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_FLOAT = 19,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 22,               /* TOKEN_ERROR  */
  YYSYMBOL_23_ = 23,                       /* '|'  */
  YYSYMBOL_24_ = 24,                       /* '&'  */
  YYSYMBOL_25_ = 25,                       /* '~'  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '.'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_lista_dec = 41,                 /* lista_dec  */
  YYSYMBOL_dec = 42,                       /* dec  */
  YYSYMBOL_inicializacao = 43,             /* inicializacao  */
  YYSYMBOL_valor = 44,                     /* valor  */
  YYSYMBOL_lista_argumentos = 45,          /* lista_argumentos  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_resto = 47,                     /* resto  */
  YYSYMBOL_lista_params = 48,              /* lista_params  */
  YYSYMBOL_param = 49,                     /* param  */
  YYSYMBOL_resto_params = 50,              /* resto_params  */
  YYSYMBOL_tipo = 51,                      /* tipo  */
  YYSYMBOL_cmd_simples = 52,               /* cmd_simples  */
  YYSYMBOL_cmd_atrib = 53,                 /* cmd_atrib  */
  YYSYMBOL_cmd_if = 54,                    /* cmd_if  */
  YYSYMBOL_cmd_else = 55,                  /* cmd_else  */
  YYSYMBOL_cmd_while = 56,                 /* cmd_while  */
  YYSYMBOL_cmd_print = 57,                 /* cmd_print  */
  YYSYMBOL_cmd_read = 58,                  /* cmd_read  */
  YYSYMBOL_index = 59,                     /* index  */
  YYSYMBOL_cmd_return = 60,                /* cmd_return  */
  YYSYMBOL_lista_elementos = 61,           /* lista_elementos  */
  YYSYMBOL_resto_print = 62,               /* resto_print  */
  YYSYMBOL_expr = 63                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,     2,
      32,    33,     2,    28,     2,    29,    30,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      26,     2,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    23,    38,    25,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    87,    88,    91,    92,    93,    96,    97,
     100,   101,   102,   105,   106,   109,   112,   113,   116,   117,
     120,   123,   124,   127,   128,   129,   132,   133,   134,   135,
     136,   137,   138,   139,   142,   143,   146,   149,   150,   153,
     156,   159,   162,   163,   166,   169,   170,   173,   174,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_READ", "KW_PRINT",
  "KW_RETURN", "ASSIGNMENT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INTEGER", "LIT_FLOAT", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'|'", "'&'", "'~'", "'<'", "'>'", "'+'",
  "'-'", "'.'", "'/'", "'('", "')'", "';'", "'['", "']'", "'{'", "'}'",
  "$accept", "programa", "lista_dec", "dec", "inicializacao", "valor",
  "lista_argumentos", "bloco", "resto", "lista_params", "param",
  "resto_params", "tipo", "cmd_simples", "cmd_atrib", "cmd_if", "cmd_else",
  "cmd_while", "cmd_print", "cmd_read", "index", "cmd_return",
  "lista_elementos", "resto_print", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,   -59,   -59,   -59,     5,   -59,    54,    -3,   -59,   -59,
      -5,    -1,    -2,   -59,   -59,   -59,    19,    44,    54,    11,
      -4,     4,    35,    54,   -59,   -59,    80,   -59,    45,   -59,
     -59,    51,    80,    65,    69,    87,   -10,    46,   -11,   -59,
      82,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,    46,
      46,    83,     2,   -59,   -59,   -59,   -10,    46,    46,   -59,
     161,   201,    46,    46,    45,    81,    98,   119,    46,   -59,
      46,   -59,   -59,   -59,   207,   140,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,   -59,   201,
      60,    82,   -59,    45,    45,    79,    84,   181,   -59,    39,
      39,    39,    39,   207,   207,    39,    39,    49,    49,   -59,
     -59,   108,   -59,   116,   -59,   -59,   -59,   -59,    46,    45,
     -59,   201,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    23,    24,    25,     0,     2,     4,     0,     1,     3,
       0,    19,     0,    10,    11,    12,     0,     0,    22,     0,
       0,     0,     0,    22,    18,    20,     9,     5,    33,     7,
      21,     0,     9,     0,     0,     0,     0,     0,     0,    32,
      17,    26,    27,    28,    29,    30,    31,     6,     8,     0,
       0,    43,    43,    49,    50,    51,    48,     0,     0,    40,
      48,    44,     0,     0,    33,     0,     0,     0,     0,    41,
      14,    52,    47,    45,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    34,
       0,    17,    15,    33,    33,     0,     0,    14,    60,    61,
      62,    63,    64,    66,    65,    58,    59,    54,    55,    57,
      56,     0,    16,    38,    39,    42,    53,    13,     0,    33,
      36,    35,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   124,   -59,   104,   126,    41,   117,    50,   -59,
     129,   121,    23,   -58,   -59,   -59,   -59,   -59,   -59,   -59,
      99,   -59,   122,    97,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    31,    32,    96,    39,    65,    17,
      23,    24,    19,    40,    41,    42,   120,    43,    44,    45,
      69,    46,    72,    73,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    62,     1,     2,     3,     8,    91,    52,    53,    54,
      55,    56,    66,    67,    10,    57,    20,    13,    14,    15,
      74,    75,    58,     7,    63,    89,    90,    11,    25,     7,
      12,    95,    26,    97,    70,   113,   114,    68,    27,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    33,    21,    34,    35,    36,    37,     1,     2,     3,
      97,   122,    38,    52,    53,    54,    55,    84,    85,    86,
      87,    57,    28,    76,    77,    78,    79,    22,    58,    86,
      87,   121,    28,    80,    81,    47,    82,    83,    84,    85,
      86,    87,    76,    77,    78,    79,   111,    49,    13,    14,
      15,    50,    80,    81,    51,    82,    83,    84,    85,    86,
      87,    76,    77,    78,    79,   115,    64,   116,    68,    92,
     118,    80,    81,   119,    82,    83,    84,    85,    86,    87,
       9,    93,    76,    77,    78,    79,    48,    16,   117,    29,
      18,   112,    80,    81,    30,    82,    83,    84,    85,    86,
      87,    71,    94,    76,    77,    78,    79,    88,    59,     0,
       0,     0,     0,    80,    81,     0,    82,    83,    84,    85,
      86,    87,     0,    98,    76,    77,    78,    79,    52,    53,
      54,    55,    56,     0,    80,    81,    57,    82,    83,    84,
      85,    86,    87,    58,    76,    77,    78,    79,    52,    53,
      54,    55,     0,     0,    80,    81,    57,    82,    83,    84,
      85,    86,    87,    58,    76,    77,    78,    79,     0,     0,
      76,    77,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    86,    87,    82,    83,    84,    85,    86,    87
};

static const yytype_int8 yycheck[] =
{
      37,    12,     3,     4,     5,     0,    64,    17,    18,    19,
      20,    21,    49,    50,    17,    25,    18,    18,    19,    20,
      57,    58,    32,     0,    35,    62,    63,    32,    17,     6,
      35,    68,    36,    70,    32,    93,    94,    35,    34,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     6,    33,     8,     9,    10,    11,     3,     4,     5,
      97,   119,    17,    17,    18,    19,    20,    28,    29,    30,
      31,    25,    37,    13,    14,    15,    16,    33,    32,    30,
      31,   118,    37,    23,    24,    34,    26,    27,    28,    29,
      30,    31,    13,    14,    15,    16,    36,    32,    18,    19,
      20,    32,    23,    24,    17,    26,    27,    28,    29,    30,
      31,    13,    14,    15,    16,    36,    34,    33,    35,    38,
      12,    23,    24,     7,    26,    27,    28,    29,    30,    31,
       6,    33,    13,    14,    15,    16,    32,    11,    97,    22,
      11,    91,    23,    24,    23,    26,    27,    28,    29,    30,
      31,    52,    33,    13,    14,    15,    16,    60,    36,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    -1,    33,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    13,    14,    15,    16,    -1,    -1,
      13,    14,    15,    16,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    26,    27,    28,    29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    40,    41,    42,    51,     0,    41,
      17,    32,    35,    18,    19,    20,    44,    48,    49,    51,
      18,    33,    33,    49,    50,    17,    36,    34,    37,    46,
      50,    43,    44,     6,     8,     9,    10,    11,    17,    46,
      52,    53,    54,    56,    57,    58,    60,    34,    43,    32,
      32,    17,    17,    18,    19,    20,    21,    25,    32,    61,
      63,    63,    12,    35,    34,    47,    63,    63,    35,    59,
      32,    59,    61,    62,    63,    63,    13,    14,    15,    16,
      23,    24,    26,    27,    28,    29,    30,    31,    62,    63,
      63,    52,    38,    33,    33,    63,    45,    63,    33,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    36,    47,    52,    52,    36,    33,    45,    12,     7,
      55,    63,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      44,    44,    44,    45,    45,    46,    47,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    54,    55,    55,    56,
      57,    58,    59,    59,    60,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     7,     6,     2,     0,
       1,     1,     1,     2,     0,     4,     3,     0,     2,     0,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     6,     6,     2,     0,     5,
       2,     3,     3,     0,     2,     2,     2,     1,     0,     1,
       1,     1,     2,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_dec  */
#line 84 "parser.y"
                                                                                        { (yyval.ast) = astCreate(AST_PROGRAM, 0, (yyvsp[0].ast), 0, 0, 0); astPrint((yyval.ast), 0); astDecompile((yyval.ast)); setDeclarations((yyvsp[0].ast)); checkUndeclared(); if (getSemanticErrors() > 0){ exit(4); }; tacPrintBack(generateCode((yyvsp[0].ast))); }
#line 1331 "y.tab.c"
    break;

  case 3: /* lista_dec: dec lista_dec  */
#line 87 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_LIST_DEC, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1337 "y.tab.c"
    break;

  case 4: /* lista_dec: %empty  */
#line 88 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1343 "y.tab.c"
    break;

  case 5: /* dec: tipo TK_IDENTIFIER '(' valor ')' ';'  */
#line 91 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_DEC_VARIABLE, (yyvsp[-4].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), 0, 0); }
#line 1349 "y.tab.c"
    break;

  case 6: /* dec: tipo TK_IDENTIFIER '[' LIT_INTEGER ']' inicializacao ';'  */
#line 92 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_DEC_VECTOR, (yyvsp[-5].symbol), (yyvsp[-6].ast), astCreate (AST_DEC_VECTOR_SIZE, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast), 0); }
#line 1355 "y.tab.c"
    break;

  case 7: /* dec: tipo TK_IDENTIFIER '(' lista_params ')' bloco  */
#line 93 "parser.y"
                                                        { (yyval.ast) = astCreate (AST_DEC_FUNC, (yyvsp[-4].symbol), (yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1361 "y.tab.c"
    break;

  case 8: /* inicializacao: valor inicializacao  */
#line 96 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_INIT, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1367 "y.tab.c"
    break;

  case 9: /* inicializacao: %empty  */
#line 97 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1373 "y.tab.c"
    break;

  case 10: /* valor: LIT_INTEGER  */
#line 100 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1379 "y.tab.c"
    break;

  case 11: /* valor: LIT_FLOAT  */
#line 101 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1385 "y.tab.c"
    break;

  case 12: /* valor: LIT_CHAR  */
#line 102 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1391 "y.tab.c"
    break;

  case 13: /* lista_argumentos: expr lista_argumentos  */
#line 105 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_LIST_ARGUMENTS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1397 "y.tab.c"
    break;

  case 14: /* lista_argumentos: %empty  */
#line 106 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1403 "y.tab.c"
    break;

  case 15: /* bloco: '{' cmd_simples resto '}'  */
#line 109 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_BLOCK, 0, (yyvsp[-2].ast), (yyvsp[-1].ast), 0, 0); }
#line 1409 "y.tab.c"
    break;

  case 16: /* resto: ';' cmd_simples resto  */
#line 112 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_RESTO, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1415 "y.tab.c"
    break;

  case 17: /* resto: %empty  */
#line 113 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1421 "y.tab.c"
    break;

  case 18: /* lista_params: param resto_params  */
#line 116 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_LISTA_PARAMS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1427 "y.tab.c"
    break;

  case 19: /* lista_params: %empty  */
#line 117 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1433 "y.tab.c"
    break;

  case 20: /* param: tipo TK_IDENTIFIER  */
#line 120 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_PARAM, (yyvsp[0].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1439 "y.tab.c"
    break;

  case 21: /* resto_params: param resto_params  */
#line 123 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_RESTO_PARAMS, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1445 "y.tab.c"
    break;

  case 22: /* resto_params: %empty  */
#line 124 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1451 "y.tab.c"
    break;

  case 23: /* tipo: KW_CHAR  */
#line 127 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_CHAR, 0, 0, 0, 0, 0); }
#line 1457 "y.tab.c"
    break;

  case 24: /* tipo: KW_INT  */
#line 128 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_INT, 0, 0, 0, 0, 0); }
#line 1463 "y.tab.c"
    break;

  case 25: /* tipo: KW_FLOAT  */
#line 129 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_FLOAT, 0, 0, 0, 0, 0); }
#line 1469 "y.tab.c"
    break;

  case 26: /* cmd_simples: cmd_atrib  */
#line 132 "parser.y"
                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1475 "y.tab.c"
    break;

  case 27: /* cmd_simples: cmd_if  */
#line 133 "parser.y"
                                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1481 "y.tab.c"
    break;

  case 28: /* cmd_simples: cmd_while  */
#line 134 "parser.y"
                                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1487 "y.tab.c"
    break;

  case 29: /* cmd_simples: cmd_print  */
#line 135 "parser.y"
                                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1493 "y.tab.c"
    break;

  case 30: /* cmd_simples: cmd_read  */
#line 136 "parser.y"
                                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1499 "y.tab.c"
    break;

  case 31: /* cmd_simples: cmd_return  */
#line 137 "parser.y"
                                                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1505 "y.tab.c"
    break;

  case 32: /* cmd_simples: bloco  */
#line 138 "parser.y"
                                                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1511 "y.tab.c"
    break;

  case 33: /* cmd_simples: %empty  */
#line 139 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1517 "y.tab.c"
    break;

  case 34: /* cmd_atrib: TK_IDENTIFIER ASSIGNMENT expr  */
#line 142 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_ATRIB_VARIAVEL, (yyvsp[-2].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1523 "y.tab.c"
    break;

  case 35: /* cmd_atrib: TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr  */
#line 143 "parser.y"
                                                        { (yyval.ast) = astCreate (AST_ATRIB_VETOR, (yyvsp[-5].symbol), (yyvsp[-3].ast), (yyvsp[0].ast), 0, 0); }
#line 1529 "y.tab.c"
    break;

  case 36: /* cmd_if: KW_IF '(' expr ')' cmd_simples cmd_else  */
#line 146 "parser.y"
                                                        { (yyval.ast) = astCreate (AST_IF, 0, (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast), 0); }
#line 1535 "y.tab.c"
    break;

  case 37: /* cmd_else: KW_ELSE cmd_simples  */
#line 149 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_ELSE, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1541 "y.tab.c"
    break;

  case 38: /* cmd_else: %empty  */
#line 150 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1547 "y.tab.c"
    break;

  case 39: /* cmd_while: KW_WHILE '(' expr ')' cmd_simples  */
#line 153 "parser.y"
                                                        { (yyval.ast) = astCreate (AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1553 "y.tab.c"
    break;

  case 40: /* cmd_print: KW_PRINT lista_elementos  */
#line 156 "parser.y"
                                                                        { (yyval.ast) = astCreate (AST_PRINT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1559 "y.tab.c"
    break;

  case 41: /* cmd_read: KW_READ TK_IDENTIFIER index  */
#line 159 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_READ, (yyvsp[-1].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1565 "y.tab.c"
    break;

  case 42: /* index: '[' expr ']'  */
#line 162 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_ACCESS_VECTOR, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1571 "y.tab.c"
    break;

  case 43: /* index: %empty  */
#line 163 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1577 "y.tab.c"
    break;

  case 44: /* cmd_return: KW_RETURN expr  */
#line 166 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_RETURN, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1583 "y.tab.c"
    break;

  case 45: /* lista_elementos: LIT_STRING resto_print  */
#line 169 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_LIST_ELEMENTS_STRING, (yyvsp[-1].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1589 "y.tab.c"
    break;

  case 46: /* lista_elementos: expr resto_print  */
#line 170 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_LIST_ELEMENTS_EXPR, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1595 "y.tab.c"
    break;

  case 47: /* resto_print: lista_elementos  */
#line 173 "parser.y"
                                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1601 "y.tab.c"
    break;

  case 48: /* resto_print: %empty  */
#line 174 "parser.y"
                                                                                        { (yyval.ast) = 0; }
#line 1607 "y.tab.c"
    break;

  case 49: /* expr: LIT_INTEGER  */
#line 177 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1613 "y.tab.c"
    break;

  case 50: /* expr: LIT_FLOAT  */
#line 178 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1619 "y.tab.c"
    break;

  case 51: /* expr: LIT_CHAR  */
#line 179 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_SYMBOL, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1625 "y.tab.c"
    break;

  case 52: /* expr: TK_IDENTIFIER index  */
#line 180 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_VARIABLE, (yyvsp[-1].symbol), (yyvsp[0].ast), 0, 0, 0); }
#line 1631 "y.tab.c"
    break;

  case 53: /* expr: TK_IDENTIFIER '(' lista_argumentos ')'  */
#line 181 "parser.y"
                                                                { (yyval.ast) = astCreate (AST_FUNC_CALL, (yyvsp[-3].symbol), (yyvsp[-1].ast), 0, 0, 0); }
#line 1637 "y.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 182 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_ADD, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1643 "y.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 183 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1649 "y.tab.c"
    break;

  case 56: /* expr: expr '/' expr  */
#line 184 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1655 "y.tab.c"
    break;

  case 57: /* expr: expr '.' expr  */
#line 185 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_MUL, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1661 "y.tab.c"
    break;

  case 58: /* expr: expr '<' expr  */
#line 186 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1667 "y.tab.c"
    break;

  case 59: /* expr: expr '>' expr  */
#line 187 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1673 "y.tab.c"
    break;

  case 60: /* expr: '(' expr ')'  */
#line 188 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_ASSOCITIVITY, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1679 "y.tab.c"
    break;

  case 61: /* expr: expr OPERATOR_LE expr  */
#line 189 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1685 "y.tab.c"
    break;

  case 62: /* expr: expr OPERATOR_GE expr  */
#line 190 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1691 "y.tab.c"
    break;

  case 63: /* expr: expr OPERATOR_EQ expr  */
#line 191 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1697 "y.tab.c"
    break;

  case 64: /* expr: expr OPERATOR_DIF expr  */
#line 192 "parser.y"
                                                                                { (yyval.ast) = astCreate (AST_DIF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1703 "y.tab.c"
    break;

  case 65: /* expr: expr '&' expr  */
#line 193 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1709 "y.tab.c"
    break;

  case 66: /* expr: expr '|' expr  */
#line 194 "parser.y"
                                                                                        { (yyval.ast) = astCreate (AST_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1715 "y.tab.c"
    break;

  case 67: /* expr: '~' expr  */
#line 195 "parser.y"
                                                                                                { (yyval.ast) = astCreate (AST_NOT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1721 "y.tab.c"
    break;


#line 1725 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 197 "parser.y"


void yyerror (char const *s)
{
	fprintf (stderr, "%s at line %d\n", s, getLineNumber ());
	exit (3);
}
