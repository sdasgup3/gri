/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
    LEX_NULL = 282,
    LEX_TRUE = 283,
    LEX_FALSE = 284,
    LEX_INT = 285,
    LEX_IDENTIFIER = 286,
    LEX_FLOAT = 287,
    LEX_STRING = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 68 "parser.y" /* yacc.c:1909  */

	int     int_val;
	float   float_val;
        char*  string_val;
	Node*   node;
	NodeBlock* nodeblock;
	list<identifier>* list_ids;

#line 97 "generated/parser.hpp" /* yacc.c:1909  */
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
