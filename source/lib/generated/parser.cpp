/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

#include "general.h"

#include "node.h"
#include "nodebinaryadd.h"
#include "nodebinaryand.h"
#include "nodebinaryass.h"
#include "nodebinaryassadd.h"
#include "nodebinaryasssub.h"
#include "nodebinaryassmult.h"
#include "nodebinaryassdiv.h"
#include "nodebinaryassmod.h"
#include "nodebinaryassref.h"
#include "nodebinarydiv.h"
#include "nodebinaryeq.h"
#include "nodebinaryge.h"
#include "nodebinarygt.h"
#include "nodebinaryle.h"
#include "nodebinarylt.h"
#include "nodebinarymod.h"
#include "nodebinarymult.h"
#include "nodebinaryne.h"
#include "nodebinaryor.h"
#include "nodebinarysub.h"
#include "nodebinaryindex.h"
#include "nodebinarymember.h"
#include "nodeblock.h"
#include "nodecondition.h"
#include "nodeemptycommand.h"
#include "nodefunctioncall.h"
#include "nodefunctionscript.h"
#include "nodeloop.h"
#include "nodeforeach.h"
#include "nodeunarynot.h"
#include "nodeunaryreturn.h"
#include "nodeunarysub.h"
#include "nodeunaryincpre.h"
#include "nodeunaryincpost.h"
#include "nodeunarydecpre.h"
#include "nodeunarydecpost.h"
#include "nodevalue.h"
#include "nodejumpbreak.h"
#include "nodejumpcontinue.h"
#include "nodeglobal.h"

#include "valuebool.h"
#include "valueedge.h"
#include "valuefloat.h"
#include "valuegraph.h"
#include "valueint.h"
#include "valuenull.h"
#include "valuestring.h"
#include "valuestruct.h"
#include "valuevertex.h"
#include "valueidentifier.h"
#include "codeposition.h"
#include "nodeposition.h"

#define LINE last_line


extern FILE* yyin;
int yylex(void);
void yyerror( const char *msg);


/* Line 268 of yacc.c  */
#line 138 "generated/parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LEX_FUNCTION = 258,
     LEX_RETURN = 259,
     LEX_IF = 260,
     LEX_ELSE = 261,
     LEX_WHILE = 262,
     LEX_FOR = 263,
     LEX_FOREACH = 264,
     LEX_BREAK = 265,
     LEX_CONTINUE = 266,
     LEX_GLOBAL = 267,
     LEX_MOD_ASSIGN = 268,
     LEX_DIV_ASSIGN = 269,
     LEX_MUL_ASSIGN = 270,
     LEX_ADD_ASSIGN = 271,
     LEX_SUB_ASSIGN = 272,
     LEX_INC_OP = 273,
     LEX_DEC_OP = 274,
     LEX_EQ_OP = 275,
     LEX_NE_OP = 276,
     LEX_LE_OP = 277,
     LEX_GE_OP = 278,
     LEX_OR_OP = 279,
     LEX_AND_OP = 280,
     LEX_REF_ASSIGN = 281,
     LEX_NULL = 282,
     LEX_TRUE = 283,
     LEX_FALSE = 284,
     LEX_INT = 285,
     LEX_IDENTIFIER = 286,
     LEX_FLOAT = 287,
     LEX_STRING = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 68 "parser.y"

	int     int_val;
	float   float_val;
        char*  string_val;
	Node*   node;
	NodeBlock* nodeblock;
	list<identifier>* list_ids;



/* Line 293 of yacc.c  */
#line 218 "generated/parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 243 "generated/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    45,     2,     2,
      34,    35,    43,    40,    39,    41,    38,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    51,
      46,    50,    47,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      21,    23,    28,    32,    37,    41,    47,    54,    57,    60,
      62,    66,    68,    71,    74,    77,    80,    83,    85,    89,
      93,    97,    99,   103,   107,   109,   113,   117,   121,   125,
     127,   131,   135,   137,   141,   143,   147,   149,   155,   157,
     161,   165,   169,   173,   177,   181,   185,   187,   189,   191,
     197,   205,   211,   218,   226,   234,   237,   240,   243,   247,
     251,   253,   256,   259,   263,   265,   268,   274,   279,   282,
     284,   288,   289
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    67,    35,
      -1,    55,    -1,    56,    36,    67,    37,    -1,    31,    34,
      35,    -1,    31,    34,    57,    35,    -1,    56,    38,    31,
      -1,    56,    38,    31,    34,    35,    -1,    56,    38,    31,
      34,    57,    35,    -1,    56,    18,    -1,    56,    19,    -1,
      66,    -1,    57,    39,    66,    -1,    56,    -1,    18,    58,
      -1,    19,    58,    -1,    40,    58,    -1,    41,    58,    -1,
      42,    58,    -1,    58,    -1,    59,    43,    58,    -1,    59,
      44,    58,    -1,    59,    45,    58,    -1,    59,    -1,    60,
      40,    59,    -1,    60,    41,    59,    -1,    60,    -1,    61,
      46,    60,    -1,    61,    47,    60,    -1,    61,    22,    60,
      -1,    61,    23,    60,    -1,    61,    -1,    62,    20,    61,
      -1,    62,    21,    61,    -1,    62,    -1,    63,    25,    62,
      -1,    63,    -1,    64,    24,    63,    -1,    64,    -1,    64,
      48,    67,    49,    65,    -1,    65,    -1,    58,    50,    66,
      -1,    58,    15,    66,    -1,    58,    14,    66,    -1,    58,
      13,    66,    -1,    58,    16,    66,    -1,    58,    17,    66,
      -1,    58,    26,    66,    -1,    66,    -1,    70,    -1,    69,
      -1,     5,    34,    67,    35,    68,    -1,     5,    34,    67,
      35,    68,     6,    68,    -1,     7,    34,    67,    35,    68,
      -1,     8,    34,    69,    69,    35,    68,    -1,     8,    34,
      69,    69,    67,    35,    68,    -1,     9,    34,    31,    51,
      67,    35,    68,    -1,    10,    51,    -1,    11,    51,    -1,
       4,    51,    -1,     4,    67,    51,    -1,    12,    31,    51,
      -1,    51,    -1,    67,    51,    -1,    52,    53,    -1,    52,
      71,    53,    -1,    68,    -1,    71,    68,    -1,    73,    34,
      74,    35,    70,    -1,    73,    34,    35,    70,    -1,     3,
      31,    -1,    31,    -1,    74,    39,    31,    -1,    -1,    75,
      72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   123,   124,   125,   126,   127,   128,   129,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   145,
     146,   150,   151,   152,   153,   154,   155,   159,   160,   161,
     162,   166,   167,   168,   172,   173,   174,   175,   176,   180,
     181,   182,   186,   187,   191,   192,   196,   197,   201,   202,
     203,   204,   205,   206,   207,   208,   212,   216,   217,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     233,   234,   238,   239,   243,   244,   248,   249,   253,   257,
     258,   261,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_FUNCTION", "LEX_RETURN", "LEX_IF",
  "LEX_ELSE", "LEX_WHILE", "LEX_FOR", "LEX_FOREACH", "LEX_BREAK",
  "LEX_CONTINUE", "LEX_GLOBAL", "LEX_MOD_ASSIGN", "LEX_DIV_ASSIGN",
  "LEX_MUL_ASSIGN", "LEX_ADD_ASSIGN", "LEX_SUB_ASSIGN", "LEX_INC_OP",
  "LEX_DEC_OP", "LEX_EQ_OP", "LEX_NE_OP", "LEX_LE_OP", "LEX_GE_OP",
  "LEX_OR_OP", "LEX_AND_OP", "LEX_REF_ASSIGN", "LEX_NULL", "LEX_TRUE",
  "LEX_FALSE", "LEX_INT", "LEX_IDENTIFIER", "LEX_FLOAT", "LEX_STRING",
  "'('", "')'", "'['", "']'", "'.'", "','", "'+'", "'-'", "'!'", "'*'",
  "'/'", "'%'", "'<'", "'>'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "statement",
  "expression_statement", "compound_statement", "block_item_list",
  "function_definition", "function_and_name", "parameter_list", "start", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    40,    41,    91,    93,    46,    44,
      43,    45,    33,    42,    47,    37,    60,    62,    63,    58,
      61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     5,     6,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     5,
       7,     5,     6,     7,     7,     2,     2,     2,     3,     3,
       1,     2,     2,     3,     1,     2,     5,     4,     2,     1,
       3,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      81,     0,     1,     0,    82,     0,    78,     0,    79,     0,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     0,    70,    72,    10,    21,
      27,    31,    34,    39,    42,    44,    46,    48,    56,     0,
      74,    58,    57,     0,    76,    80,    67,     0,     0,     0,
       0,     0,    65,    66,     0,    22,    23,     0,     0,    24,
      25,    26,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    73,    75,
      68,     0,     0,     0,     0,    69,    12,     0,    19,     9,
       0,    14,    52,    51,    50,    53,    54,    55,    49,    28,
      29,    30,    27,    32,    33,    37,    38,    35,    36,    40,
      41,    43,    45,     0,     0,     0,     0,     0,    13,     0,
      11,     0,     0,    59,    61,     0,     0,     0,    20,    15,
       0,    47,     0,    62,     0,     0,    16,    60,    63,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    38,    39,   107,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     4,     5,
      10,     1
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     -70,    35,   -70,    15,   -70,    18,   -70,     1,   -70,     2,
      -2,   105,   -70,     2,    29,   231,    44,    53,    55,    57,
      39,    41,    62,   335,   335,   -70,   -70,   -70,   -70,    60,
     -70,   -70,   335,   335,   335,   335,   -70,   -70,   -70,    12,
      -8,    13,    34,    -7,    56,    71,   -14,   -70,   -70,    46,
     -70,   -70,   -70,   155,   -70,   -70,   -70,    47,   335,   335,
     256,    68,   -70,   -70,    49,   -70,   -70,   281,    66,   -70,
     -70,   -70,   -70,   -70,   335,    72,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   -70,   -70,   -70,
     -70,    73,    76,   256,    67,   -70,   -70,     6,   -70,   -70,
      69,    85,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,    13,    13,    34,    34,    34,    34,    -7,
      -7,    56,    71,    58,   205,   205,   299,   335,   -70,   335,
     -70,   317,   335,   119,   -70,   205,    91,    92,   -70,   -70,
      14,   -70,   205,   -70,   205,   205,   -70,   -70,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -12,   -22,    -4,   -69,   -13,    36,    33,
     -70,   -11,   -53,   -15,   -50,   -56,    42,   -70,   -70,   -70,
     -70,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,    65,    66,    99,   103,    76,    77,    78,    79,    80,
      95,    69,    70,    71,   108,    88,    89,    68,    81,   125,
     126,   127,   128,   112,   113,   114,   115,   116,   117,   118,
      72,    73,     8,    13,    96,     2,     9,    14,     3,    90,
      91,   138,    82,   101,   102,   139,     6,   136,    74,   156,
      75,    12,     7,   139,    11,    54,    83,    84,    85,   110,
      55,   119,   120,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,    86,    87,    92,    93,    58,   129,
     130,   133,   123,   124,   143,   144,   148,    59,   108,    60,
      62,    61,    63,    64,    67,   153,    94,    97,   100,   104,
     105,   109,   157,   111,   158,   159,   140,   142,   134,    15,
      16,   135,    17,    18,    19,    20,    21,    22,   137,   141,
     122,   146,   147,    23,    24,   152,   154,   155,   132,   150,
     131,   151,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    11,    37,    15,
      16,     0,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    11,    98,    15,
      16,     0,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,     0,    23,
      24,     0,     0,     0,     0,     0,    36,    11,    25,    26,
      27,    28,    29,    30,    31,    32,     0,     0,     0,     0,
       0,    33,    34,    35,    23,    24,     0,     0,     0,     0,
       0,     0,    56,    25,    26,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    33,    34,    35,    23,
      24,     0,     0,     0,     0,     0,     0,    36,    25,    26,
      27,    28,    29,    30,    31,    32,   106,    23,    24,     0,
       0,    33,    34,    35,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,   145,    23,    24,     0,     0,    33,
      34,    35,     0,     0,    25,    26,    27,    28,    29,    30,
      31,    32,   149,    23,    24,     0,     0,    33,    34,    35,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-70))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      15,    23,    24,    53,    60,    13,    14,    15,    16,    17,
      24,    33,    34,    35,    67,    22,    23,    32,    26,    88,
      89,    90,    91,    76,    77,    78,    79,    80,    81,    82,
      18,    19,    31,    35,    48,     0,    35,    39,     3,    46,
      47,    35,    50,    58,    59,    39,    31,   103,    36,    35,
      38,     9,    34,    39,    52,    13,    43,    44,    45,    74,
      31,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    40,    41,    20,    21,    34,    92,
      93,    96,    86,    87,   134,   135,   139,    34,   141,    34,
      51,    34,    51,    31,    34,   145,    25,    51,    51,    31,
      51,    35,   152,    31,   154,   155,    37,    49,    35,     4,
       5,    35,     7,     8,     9,    10,    11,    12,    51,    34,
     142,   136,   137,    18,    19,     6,    35,    35,    95,   141,
      94,   142,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    51,    52,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    51,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    18,    19,    -1,
      -1,    40,    41,    42,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    18,    19,    -1,    -1,    40,
      41,    42,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    18,    19,    -1,    -1,    40,    41,    42,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     3,    72,    73,    31,    34,    31,    35,
      74,    52,    70,    35,    39,     4,     5,     7,     8,     9,
      10,    11,    12,    18,    19,    27,    28,    29,    30,    31,
      32,    33,    34,    40,    41,    42,    51,    53,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    70,    31,    51,    67,    34,    34,
      34,    34,    51,    51,    31,    58,    58,    34,    67,    58,
      58,    58,    18,    19,    36,    38,    13,    14,    15,    16,
      17,    26,    50,    43,    44,    45,    40,    41,    22,    23,
      46,    47,    20,    21,    25,    24,    48,    51,    53,    68,
      51,    67,    67,    69,    31,    51,    35,    57,    66,    35,
      67,    31,    66,    66,    66,    66,    66,    66,    66,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    63,    67,    35,    35,    69,    51,    35,    39,
      37,    34,    49,    68,    68,    35,    67,    67,    66,    35,
      57,    65,     6,    68,    35,    35,    35,    68,    68,    68
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = new NodeValue(VALUENULL); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 123 "parser.y"
    { (yyval.node) = new NodeValue(VALUEBOOL_TRUE); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 124 "parser.y"
    { (yyval.node) = new NodeValue(VALUEBOOL_FALSE); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 125 "parser.y"
    { (yyval.node) = new NodeValue(new ValueInt((yyvsp[(1) - (1)].int_val))); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 126 "parser.y"
    { (yyval.node) = new NodeValue(new ValueIdentifier((yyvsp[(1) - (1)].int_val))); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 127 "parser.y"
    { (yyval.node) = new NodeValue(new ValueFloat((yyvsp[(1) - (1)].float_val))); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 128 "parser.y"
    { (yyval.node) = new NodeValue(new ValueString(std::string((yyvsp[(1) - (1)].string_val)))); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 129 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 133 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 134 "parser.y"
    { (yyval.node) = new NodeBinaryIndex((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 135 "parser.y"
    { (yyval.node) = new NodeFunctionCall((yyvsp[(1) - (3)].int_val), new NodeBlock, new CodePosition((yylsp[(1) - (3)]).last_column, (yylsp[(1) - (3)]).LINE)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 136 "parser.y"
    { (yyval.node) = new NodeFunctionCall((yyvsp[(1) - (4)].int_val), (yyvsp[(3) - (4)].nodeblock), new CodePosition((yylsp[(1) - (4)]).last_column, (yylsp[(1) - (4)]).LINE)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 137 "parser.y"
    { (yyval.node) = new NodeBinaryMember((yyvsp[(1) - (3)].node), new NodeValue(new ValueIdentifier((yyvsp[(3) - (3)].int_val)))); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 138 "parser.y"
    { (yyval.node) = new NodeFunctionCall((yyvsp[(3) - (5)].int_val), new NodeBlock((yyvsp[(1) - (5)].node)), new CodePosition((yylsp[(3) - (5)]).last_column, (yylsp[(3) - (5)]).LINE)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 139 "parser.y"
    { (yyvsp[(5) - (6)].nodeblock)->pushCommandToFront((yyvsp[(1) - (6)].node)); (yyval.node) = new NodeFunctionCall((yyvsp[(3) - (6)].int_val), (yyvsp[(5) - (6)].nodeblock), new CodePosition((yylsp[(3) - (6)]).last_column, (yylsp[(3) - (6)]).LINE)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 140 "parser.y"
    { (yyval.node) = new NodeUnaryIncPost((yyvsp[(1) - (2)].node)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { (yyval.node) = new NodeUnaryDecPost((yyvsp[(1) - (2)].node)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    { (yyval.nodeblock) = new NodeBlock((yyvsp[(1) - (1)].node)); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 146 "parser.y"
    { (yyvsp[(1) - (3)].nodeblock)->pushCommandToBack((yyvsp[(3) - (3)].node)); (yyval.nodeblock) = (yyvsp[(1) - (3)].nodeblock); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 150 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 151 "parser.y"
    { (yyval.node) = new NodeUnaryIncPre((yyvsp[(2) - (2)].node)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 152 "parser.y"
    { (yyval.node) = new NodeUnaryDecPre((yyvsp[(2) - (2)].node)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 153 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    { (yyval.node) = new NodeUnarySub((yyvsp[(2) - (2)].node)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 155 "parser.y"
    { (yyval.node) = new NodeUnaryNot((yyvsp[(2) - (2)].node)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 159 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 160 "parser.y"
    { (yyval.node) = new NodeBinaryMult((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 161 "parser.y"
    { (yyval.node) = new NodeBinaryDiv((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    { (yyval.node) = new NodeBinaryMod((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 166 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 167 "parser.y"
    { (yyval.node) = new NodeBinaryAdd((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 168 "parser.y"
    { (yyval.node) = new NodeBinarySub((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 172 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { (yyval.node) = new NodeBinaryLt((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 174 "parser.y"
    { (yyval.node) = new NodeBinaryGt((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 175 "parser.y"
    { (yyval.node) = new NodeBinaryLe((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    { (yyval.node) = new NodeBinaryGe((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 180 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    { (yyval.node) = new NodeBinaryEq((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    { (yyval.node) = new NodeBinaryNe((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { (yyval.node) = new NodeBinaryAnd((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 191 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 192 "parser.y"
    { (yyval.node) = new NodeBinaryOr((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 196 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { (yyval.node) = new NodeCondition((yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 201 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 202 "parser.y"
    { (yyval.node) = new NodeBinaryAss((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    { (yyval.node) = new NodeBinaryAssMult((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    { (yyval.node) = new NodeBinaryAssDiv((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 205 "parser.y"
    { (yyval.node) = new NodeBinaryAssMod((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 206 "parser.y"
    { (yyval.node) = new NodeBinaryAssAdd((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { (yyval.node) = new NodeBinaryAssSub((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { (yyval.node) = new NodeBinaryAssRef((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 212 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 216 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 217 "parser.y"
    { (yyval.node) = new NodePosition((yyvsp[(1) - (1)].node), new CodePosition((yylsp[(1) - (1)]).last_column, (yylsp[(1) - (1)]).LINE)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    { (yyval.node) = new NodeCondition(new NodePosition((yyvsp[(3) - (5)].node), new CodePosition((yylsp[(3) - (5)]).last_column, (yylsp[(3) - (5)]).LINE)), (yyvsp[(5) - (5)].node), new NodeEmptyCommand); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    { (yyval.node) = new NodeCondition(new NodePosition((yyvsp[(3) - (7)].node), new CodePosition((yylsp[(3) - (7)]).last_column, (yylsp[(3) - (7)]).LINE)), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 221 "parser.y"
    { (yyval.node) = new NodeLoop(new NodeEmptyCommand, new NodePosition((yyvsp[(3) - (5)].node), new CodePosition((yylsp[(3) - (5)]).last_column, (yylsp[(3) - (5)]).LINE)), new NodeEmptyCommand, (yyvsp[(5) - (5)].node)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 222 "parser.y"
    { (yyval.node) = new NodeLoop((yyvsp[(3) - (6)].node), new NodePosition((yyvsp[(4) - (6)].node), new CodePosition((yylsp[(4) - (6)]).last_column, (yylsp[(4) - (6)]).LINE)), new NodeEmptyCommand, (yyvsp[(6) - (6)].node)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    { (yyval.node) = new NodeLoop((yyvsp[(3) - (7)].node), new NodePosition((yyvsp[(4) - (7)].node), new CodePosition((yylsp[(4) - (7)]).last_column, (yylsp[(4) - (7)]).LINE)), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 224 "parser.y"
    { (yyval.node) = new NodeForeach((yyvsp[(3) - (7)].int_val), new NodePosition((yyvsp[(5) - (7)].node), new CodePosition((yylsp[(5) - (7)]).last_column, (yylsp[(5) - (7)]).LINE)), (yyvsp[(7) - (7)].node)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 225 "parser.y"
    { (yyval.node) = new NodePosition(new NodeJumpBreak, new CodePosition((yylsp[(2) - (2)]).last_column, (yylsp[(2) - (2)]).LINE)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    { (yyval.node) = new NodePosition(new NodeJumpContinue, new CodePosition((yylsp[(2) - (2)]).last_column, (yylsp[(2) - (2)]).LINE)); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 227 "parser.y"
    { (yyval.node) = new NodePosition(new NodeUnaryReturn(new NodeEmptyCommand), new CodePosition((yylsp[(2) - (2)]).last_column, (yylsp[(2) - (2)]).LINE)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { (yyval.node) = new NodePosition(new NodeUnaryReturn((yyvsp[(2) - (3)].node)), new CodePosition((yylsp[(3) - (3)]).last_column, (yylsp[(3) - (3)]).LINE)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 229 "parser.y"
    { (yyval.node) = new NodePosition(new NodeGlobal((yyvsp[(2) - (3)].int_val)), new CodePosition((yylsp[(3) - (3)]).last_column, (yylsp[(3) - (3)]).LINE)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 233 "parser.y"
    { (yyval.node) = new NodeEmptyCommand; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 234 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { (yyval.node) = new NodeEmptyCommand; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].nodeblock); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    {   (yyval.nodeblock) = new NodeBlock((yyvsp[(1) - (1)].node)); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    { (yyvsp[(1) - (2)].nodeblock)->pushCommandToBack((yyvsp[(2) - (2)].node)); (yyval.nodeblock) = (yyvsp[(1) - (2)].nodeblock); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    { CONTEXT->addFunction(new NodeFunctionScript((yyvsp[(1) - (5)].int_val), (yyvsp[(3) - (5)].list_ids), (yyvsp[(5) - (5)].node), new CodePosition((yylsp[(1) - (5)]).last_column, (yylsp[(1) - (5)]).LINE))); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 249 "parser.y"
    { CONTEXT->addFunction(new NodeFunctionScript((yyvsp[(1) - (4)].int_val), new list<identifier>, (yyvsp[(4) - (4)].node), new CodePosition((yylsp[(1) - (4)]).last_column, (yylsp[(1) - (4)]).LINE)));   }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    { (yyval.int_val) = (yyvsp[(2) - (2)].int_val); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 257 "parser.y"
    { (yyval.list_ids) = new list<identifier>; (yyval.list_ids)->push_back((yyvsp[(1) - (1)].int_val)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 258 "parser.y"
    { (yyvsp[(1) - (3)].list_ids)->push_back((yyvsp[(3) - (3)].int_val)); (yyval.list_ids) = (yyvsp[(1) - (3)].list_ids); }
    break;



/* Line 1806 of yacc.c  */
#line 2258 "generated/parser.cpp"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 265 "parser.y"


void 
yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "from yacc %s\n", s);
}
/*
void yyerror(char const *msg)
{
	stringstream ss;
	ss << ID2STR(g_lexan->getFile()) << ":" << g_lexan->getLine();
	ERR_PP(ss.str(), msg);
}
*/

int 
parseCode(char* filename)
{
  FILE *myfile = fopen(filename, "r");
  if (!myfile) {
    printf("Cannot open file %s\n", filename);
    return -1;
  }
  yyin = myfile;

  yyparse();

  return 0;
}

