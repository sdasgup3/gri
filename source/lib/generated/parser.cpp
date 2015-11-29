/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include "general.h"

#include "node.h"
#include "nodebinaryadd.h"
#include "nodebinaryngbaccess.h"
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

#line 133 "generated/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_GENERATED_PARSER_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    LEX_SUB_ASSIGN = 268,
    LEX_ADD_ASSIGN = 269,
    LEX_MUL_ASSIGN = 270,
    LEX_DIV_ASSIGN = 271,
    LEX_MOD_ASSIGN = 272,
    LEX_INC_OP = 273,
    LEX_DEC_OP = 274,
    LEX_EQ_OP = 275,
    LEX_NE_OP = 276,
    LEX_LE_OP = 277,
    LEX_GE_OP = 278,
    LEX_OR_OP = 279,
    LEX_AND_OP = 280,
    LEX_REF_ASSIGN = 281,
    LEX_NGB_ACCESS_TYPE1 = 282,
    LEX_NGB_ACCESS_TYPE2 = 283,
    LEX_NGB_ACCESS_TYPE3 = 284,
    LEX_NULL = 285,
    LEX_TRUE = 286,
    LEX_FALSE = 287,
    LEX_INT = 288,
    LEX_IDENTIFIER = 289,
    LEX_FLOAT = 290,
    LEX_STRING = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "parser.y" /* yacc.c:355  */

	int     int_val;
	float   float_val;
        char*  string_val;
	Node*   node;
	NodeBlock* nodeblock;
	list<identifier>* list_ids;

#line 219 "generated/parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "generated/parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    48,     2,     2,
      37,    38,    46,    43,    42,    44,    41,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    54,
      49,    53,    50,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   126,   127,   128,   129,   130,   131,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   147,
     148,   152,   153,   154,   155,   156,   157,   161,   162,   163,
     164,   168,   169,   170,   171,   172,   173,   177,   178,   179,
     180,   181,   185,   186,   187,   191,   192,   196,   197,   201,
     202,   206,   207,   208,   209,   210,   211,   212,   213,   217,
     221,   222,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   238,   239,   243,   244,   248,   249,   253,
     254,   258,   262,   263,   266,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_FUNCTION", "LEX_RETURN", "LEX_IF",
  "LEX_ELSE", "LEX_WHILE", "LEX_FOR", "LEX_FOREACH", "LEX_BREAK",
  "LEX_CONTINUE", "LEX_GLOBAL", "LEX_SUB_ASSIGN", "LEX_ADD_ASSIGN",
  "LEX_MUL_ASSIGN", "LEX_DIV_ASSIGN", "LEX_MOD_ASSIGN", "LEX_INC_OP",
  "LEX_DEC_OP", "LEX_EQ_OP", "LEX_NE_OP", "LEX_LE_OP", "LEX_GE_OP",
  "LEX_OR_OP", "LEX_AND_OP", "LEX_REF_ASSIGN", "LEX_NGB_ACCESS_TYPE1",
  "LEX_NGB_ACCESS_TYPE2", "LEX_NGB_ACCESS_TYPE3", "LEX_NULL", "LEX_TRUE",
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
  "function_definition", "function_and_name", "parameter_list", "start", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    40,    41,    91,
      93,    46,    44,    43,    45,    33,    42,    47,    37,    60,
      62,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,    34,   -59,   -27,   -59,    -1,   -59,    11,   -59,   -45,
      39,    88,   -59,   -45,    13,   222,    23,    43,    48,    51,
      40,    62,    68,   341,   341,   -59,   -59,   -59,   -59,    80,
     -59,   -59,   341,   341,   341,   341,   -59,   -59,   -59,     7,
      25,   -19,   -13,   -17,    37,   104,   -16,   -59,   -59,    76,
     -59,   -59,   -59,   141,   -59,   -59,   -59,    81,   341,   341,
     250,   100,   -59,   -59,    82,   -59,   -59,   278,    99,   -59,
     -59,   -59,   -59,   -59,   341,   105,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     -59,   -59,   -59,   -59,   102,   103,   250,    84,   -59,   -59,
      41,   -59,   -59,   107,   117,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -19,   -19,   -19,   -19,
     -19,   -13,   -13,   -13,   -13,   -17,   -17,    37,   104,   106,
     194,   194,   299,   341,   -59,   341,   -59,   320,   341,   149,
     -59,   194,   118,   119,   -59,   -59,    44,   -59,   194,   -59,
     194,   194,   -59,   -59,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      84,     0,     1,     0,    85,     0,    81,     0,    82,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     0,    73,    75,    10,    21,
      27,    31,    37,    42,    45,    47,    49,    51,    59,     0,
      77,    61,    60,     0,    79,    83,    70,     0,     0,     0,
       0,     0,    68,    69,     0,    22,    23,     0,     0,    24,
      25,    26,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    76,    78,    71,     0,     0,     0,     0,    72,    12,
       0,    19,     9,     0,    14,    57,    56,    53,    54,    55,
      58,    52,    28,    29,    30,    27,    34,    35,    36,    32,
      33,    40,    41,    38,    39,    43,    44,    46,    48,     0,
       0,     0,     0,     0,    13,     0,    11,     0,     0,    62,
      64,     0,     0,     0,    20,    15,     0,    50,     0,    65,
       0,     0,    16,    63,    66,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,    14,   -22,   -34,    21,     8,    65,    66,
     -59,    15,   -58,   -15,   -50,   -56,    96,   -59,   -59,   -59,
     -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    38,    39,   110,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     4,     5,
      10,     1
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    65,    66,   102,   106,    91,    92,     6,    98,   111,
      11,    69,    70,    71,    86,    87,    88,    68,   115,   116,
     117,   118,   119,   120,   121,    72,    73,    83,    84,    85,
      89,    90,    93,    94,     2,    99,     7,     3,    76,    77,
      78,    79,    80,   104,   105,     8,    74,    55,    75,     9,
     142,    81,   126,   127,   128,   129,   130,    95,    96,   113,
      58,   122,   123,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,    13,    82,   144,
      59,    14,   162,   145,   139,    60,   145,   154,    61,   111,
     149,   150,    15,    16,    62,    17,    18,    19,    20,    21,
      22,   159,    64,   135,   136,    12,    23,    24,   163,    54,
     164,   165,   131,   132,   133,   134,    63,    67,    25,    26,
      27,    28,    29,    30,    31,    32,   125,   152,   153,    97,
     100,    33,    34,    35,   107,   103,   108,   112,   143,   114,
     140,   141,    36,    11,    37,    15,    16,   146,    17,    18,
      19,    20,    21,    22,   147,   158,   160,   161,   148,    23,
      24,   156,   137,   157,   138,     0,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,     0,     0,     0,    33,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    11,   101,    15,    16,
       0,    17,    18,    19,    20,    21,    22,     0,     0,     0,
       0,     0,    23,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
      31,    32,     0,     0,     0,     0,     0,    33,    34,    35,
      23,    24,     0,     0,     0,     0,     0,     0,    36,    11,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,    23,    24,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    33,    34,    35,    23,    24,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,   109,    23,    24,     0,
       0,    33,    34,    35,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,    30,    31,    32,   151,    23,    24,
       0,     0,    33,    34,    35,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,   155,    23,
      24,     0,     0,    33,    34,    35,     0,     0,     0,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,     0,
       0,     0,     0,     0,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
      15,    23,    24,    53,    60,    22,    23,    34,    24,    67,
      55,    33,    34,    35,    27,    28,    29,    32,    76,    77,
      78,    79,    80,    81,    82,    18,    19,    46,    47,    48,
      43,    44,    49,    50,     0,    51,    37,     3,    13,    14,
      15,    16,    17,    58,    59,    34,    39,    34,    41,    38,
     106,    26,    86,    87,    88,    89,    90,    20,    21,    74,
      37,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    38,    53,    38,
      37,    42,    38,    42,    99,    37,    42,   145,    37,   147,
     140,   141,     4,     5,    54,     7,     8,     9,    10,    11,
      12,   151,    34,    95,    96,     9,    18,    19,   158,    13,
     160,   161,    91,    92,    93,    94,    54,    37,    30,    31,
      32,    33,    34,    35,    36,    37,   148,   142,   143,    25,
      54,    43,    44,    45,    34,    54,    54,    38,    54,    34,
      38,    38,    54,    55,    56,     4,     5,    40,     7,     8,
       9,    10,    11,    12,    37,     6,    38,    38,    52,    18,
      19,   147,    97,   148,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    18,    19,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    18,    19,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    18,
      19,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    78,     0,     3,    75,    76,    34,    37,    34,    38,
      77,    55,    73,    38,    42,     4,     5,     7,     8,     9,
      10,    11,    12,    18,    19,    30,    31,    32,    33,    34,
      35,    36,    37,    43,    44,    45,    54,    56,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    73,    34,    54,    70,    37,    37,
      37,    37,    54,    54,    34,    61,    61,    37,    70,    61,
      61,    61,    18,    19,    39,    41,    13,    14,    15,    16,
      17,    26,    53,    46,    47,    48,    27,    28,    29,    43,
      44,    22,    23,    49,    50,    20,    21,    25,    24,    51,
      54,    56,    71,    54,    70,    70,    72,    34,    54,    38,
      60,    69,    38,    70,    34,    69,    69,    69,    69,    69,
      69,    69,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    65,    66,    70,
      38,    38,    72,    54,    38,    42,    40,    37,    52,    71,
      71,    38,    70,    70,    69,    38,    60,    68,     6,    71,
      38,    38,    38,    71,    71,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     5,     6,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     2,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     5,     7,     5,     6,     7,     7,     2,     2,
       2,     3,     3,     1,     2,     2,     3,     1,     2,     5,
       4,     2,     1,     3,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(VALUENULL); }
#line 1585 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(VALUEBOOL_TRUE); }
#line 1591 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(VALUEBOOL_FALSE); }
#line 1597 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(new ValueInt((yyvsp[0].int_val))); }
#line 1603 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(new ValueIdentifier((yyvsp[0].int_val))); }
#line 1609 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(new ValueFloat((yyvsp[0].float_val))); }
#line 1615 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeValue(new ValueString(std::string((yyvsp[0].string_val)))); }
#line 1621 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1627 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1633 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryIndex((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1639 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeFunctionCall((yyvsp[-2].int_val), new NodeBlock, new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)); }
#line 1645 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeFunctionCall((yyvsp[-3].int_val), (yyvsp[-1].nodeblock), new CodePosition((yylsp[-3]).last_column, (yylsp[-3]).LINE)); }
#line 1651 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryMember((yyvsp[-2].node), new NodeValue(new ValueIdentifier((yyvsp[0].int_val)))); }
#line 1657 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeFunctionCall((yyvsp[-2].int_val), new NodeBlock((yyvsp[-4].node)), new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)); }
#line 1663 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].nodeblock)->pushCommandToFront((yyvsp[-5].node)); (yyval.node) = new NodeFunctionCall((yyvsp[-3].int_val), (yyvsp[-1].nodeblock), new CodePosition((yylsp[-3]).last_column, (yylsp[-3]).LINE)); }
#line 1669 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnaryIncPost((yyvsp[-1].node)); }
#line 1675 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnaryDecPost((yyvsp[-1].node)); }
#line 1681 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.nodeblock) = new NodeBlock((yyvsp[0].node)); }
#line 1687 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nodeblock)->pushCommandToBack((yyvsp[0].node)); (yyval.nodeblock) = (yyvsp[-2].nodeblock); }
#line 1693 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1699 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnaryIncPre((yyvsp[0].node)); }
#line 1705 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnaryDecPre((yyvsp[0].node)); }
#line 1711 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1717 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnarySub((yyvsp[0].node)); }
#line 1723 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeUnaryNot((yyvsp[0].node)); }
#line 1729 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1735 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryMult((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1741 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryDiv((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1747 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryMod((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1753 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1759 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAdd((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1765 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinarySub((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1771 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryNgbAccess((yyvsp[-2].node), (yyvsp[0].node), 1); }
#line 1777 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryNgbAccess((yyvsp[-2].node), (yyvsp[0].node), 2); }
#line 1783 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryNgbAccess((yyvsp[-2].node), (yyvsp[0].node), 3); }
#line 1789 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1795 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryLt((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1801 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryGt((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1807 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryLe((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1813 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryGe((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1819 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1825 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryEq((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1831 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryNe((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1837 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1843 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAnd((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1849 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1855 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryOr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1861 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1867 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeCondition((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1873 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1879 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAss((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1885 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssMult((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1891 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssDiv((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1897 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssMod((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1903 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssAdd((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1909 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssSub((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1915 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeBinaryAssRef((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1921 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1927 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1933 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition((yyvsp[0].node), new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 1939 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 224 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeCondition(new NodePosition((yyvsp[-2].node), new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)), (yyvsp[0].node), new NodeEmptyCommand); }
#line 1945 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeCondition(new NodePosition((yyvsp[-4].node), new CodePosition((yylsp[-4]).last_column, (yylsp[-4]).LINE)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1951 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeLoop(new NodeEmptyCommand, new NodePosition((yyvsp[-2].node), new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)), new NodeEmptyCommand, (yyvsp[0].node)); }
#line 1957 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeLoop((yyvsp[-3].node), new NodePosition((yyvsp[-2].node), new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)), new NodeEmptyCommand, (yyvsp[0].node)); }
#line 1963 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeLoop((yyvsp[-4].node), new NodePosition((yyvsp[-3].node), new CodePosition((yylsp[-3]).last_column, (yylsp[-3]).LINE)), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1969 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeForeach((yyvsp[-4].int_val), new NodePosition((yyvsp[-2].node), new CodePosition((yylsp[-2]).last_column, (yylsp[-2]).LINE)), (yyvsp[0].node)); }
#line 1975 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition(new NodeJumpBreak, new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 1981 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition(new NodeJumpContinue, new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 1987 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition(new NodeUnaryReturn(new NodeEmptyCommand), new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 1993 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition(new NodeUnaryReturn((yyvsp[-1].node)), new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 1999 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodePosition(new NodeGlobal((yyvsp[-1].int_val)), new CodePosition((yylsp[0]).last_column, (yylsp[0]).LINE)); }
#line 2005 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 238 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeEmptyCommand; }
#line 2011 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2017 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = new NodeEmptyCommand; }
#line 2023 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].nodeblock); }
#line 2029 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 248 "parser.y" /* yacc.c:1646  */
    {   (yyval.nodeblock) = new NodeBlock((yyvsp[0].node)); }
#line 2035 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].nodeblock)->pushCommandToBack((yyvsp[0].node)); (yyval.nodeblock) = (yyvsp[-1].nodeblock); }
#line 2041 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 253 "parser.y" /* yacc.c:1646  */
    { CONTEXT->addFunction(new NodeFunctionScript((yyvsp[-4].int_val), (yyvsp[-2].list_ids), (yyvsp[0].node), new CodePosition((yylsp[-4]).last_column, (yylsp[-4]).LINE))); }
#line 2047 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 254 "parser.y" /* yacc.c:1646  */
    { CONTEXT->addFunction(new NodeFunctionScript((yyvsp[-3].int_val), new list<identifier>, (yyvsp[0].node), new CodePosition((yylsp[-3]).last_column, (yylsp[-3]).LINE)));   }
#line 2053 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 2059 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.list_ids) = new list<identifier>; (yyval.list_ids)->push_back((yyvsp[0].int_val)); }
#line 2065 "generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].list_ids)->push_back((yyvsp[0].int_val)); (yyval.list_ids) = (yyvsp[-2].list_ids); }
#line 2071 "generated/parser.cpp" /* yacc.c:1646  */
    break;


#line 2075 "generated/parser.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 270 "parser.y" /* yacc.c:1906  */


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
