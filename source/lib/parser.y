%{
#include <cassert>
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
%}

%union
{
	int     int_val;
	float   float_val;
        char*  string_val;
	Node*   node;
	NodeBlock* nodeblock;
	list<identifier>* list_ids;
}

%token LEX_FUNCTION
%token LEX_RETURN
%token LEX_IF
%token LEX_ELSE
%token LEX_WHILE
%token LEX_FOR
%token LEX_FOREACH
%token LEX_BREAK
%token LEX_CONTINUE
%token LEX_GLOBAL

%right LEX_SUB_ASSIGN LEX_ADD_ASSIGN LEX_MUL_ASSIGN LEX_DIV_ASSIGN LEX_MOD_ASSIGN
%token LEX_INC_OP LEX_DEC_OP
%token LEX_EQ_OP LEX_NE_OP LEX_LE_OP LEX_GE_OP
%token LEX_OR_OP LEX_AND_OP
%token LEX_REF_ASSIGN

%token LEX_NULL
%token LEX_TRUE
%token LEX_FALSE
%token <int_val>    LEX_INT
%token <int_val>    LEX_IDENTIFIER
%token <float_val>  LEX_FLOAT
%token <string_val> LEX_STRING

%type <node> primary_expression postfix_expression unary_expression
%type <node> multiplicative_expression additive_expression expression
%type <node> relational_expression equality_expression logical_and_expression
%type <node> logical_or_expression conditional_expression assignment_expression
%type <node> statement expression_statement compound_statement
%type <nodeblock> argument_expression_list block_item_list
%type <list_ids> parameter_list
%type <int_val> function_and_name


// if-else conflicts: 1 shift/reduce
%expect 1

%error-verbose

%start start

%%

primary_expression
	: LEX_NULL { $$ = new NodeValue(VALUENULL); }
	| LEX_TRUE { $$ = new NodeValue(VALUEBOOL_TRUE); }
	| LEX_FALSE { $$ = new NodeValue(VALUEBOOL_FALSE); }
	| LEX_INT { $$ = new NodeValue(new ValueInt($1)); }
	| LEX_IDENTIFIER { $$ = new NodeValue(new ValueIdentifier($1)); }
	| LEX_FLOAT { $$ = new NodeValue(new ValueFloat($1)); }
	| LEX_STRING { $$ = new NodeValue(new ValueString(std::string($1))); }
	| '(' expression ')' { $$ = $2; }
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' { $$ = new NodeBinaryIndex($1, $3); }
	| LEX_IDENTIFIER '(' ')' { $$ = new NodeFunctionCall($1, new NodeBlock, new CodePosition(@1.last_column, @1.LINE)); }
	| LEX_IDENTIFIER '(' argument_expression_list ')' { $$ = new NodeFunctionCall($1, $3, new CodePosition(@1.last_column, @1.LINE)); }
	| postfix_expression '.' LEX_IDENTIFIER { $$ = new NodeBinaryMember($1, new NodeValue(new ValueIdentifier($3))); }
	| postfix_expression '.' LEX_IDENTIFIER '(' ')' { $$ = new NodeFunctionCall($3, new NodeBlock($1), new CodePosition(@3.last_column, @3.LINE)); }
	| postfix_expression '.' LEX_IDENTIFIER '(' argument_expression_list ')' { $5->pushCommandToFront($1); $$ = new NodeFunctionCall($3, $5, new CodePosition(@3.last_column, @3.LINE)); }
	| postfix_expression LEX_INC_OP { $$ = new NodeUnaryIncPost($1); }
	| postfix_expression LEX_DEC_OP { $$ = new NodeUnaryDecPost($1); }
	;

argument_expression_list
	: assignment_expression { $$ = new NodeBlock($1); }
	| argument_expression_list ',' assignment_expression { $1->pushCommandToBack($3); $$ = $1; }
	;

unary_expression
	: postfix_expression { $$ = $1; }
	| LEX_INC_OP unary_expression { $$ = new NodeUnaryIncPre($2); }
	| LEX_DEC_OP unary_expression { $$ = new NodeUnaryDecPre($2); }
	| '+' unary_expression { $$ = $2; }
	| '-' unary_expression { $$ = new NodeUnarySub($2); }
	| '!' unary_expression { $$ = new NodeUnaryNot($2); }
	;

multiplicative_expression
	: unary_expression { $$ = $1; }
	| multiplicative_expression '*' unary_expression { $$ = new NodeBinaryMult($1, $3); }
	| multiplicative_expression '/' unary_expression { $$ = new NodeBinaryDiv($1, $3); }
	| multiplicative_expression '%' unary_expression { $$ = new NodeBinaryMod($1, $3); }
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { $$ = new NodeBinaryAdd($1, $3); }
	| additive_expression '-' multiplicative_expression { $$ = new NodeBinarySub($1, $3); }
	;

relational_expression
	: additive_expression { $$ = $1; }
	| relational_expression '<' additive_expression { $$ = new NodeBinaryLt($1, $3); }
	| relational_expression '>' additive_expression { $$ = new NodeBinaryGt($1, $3); }
	| relational_expression LEX_LE_OP additive_expression { $$ = new NodeBinaryLe($1, $3); }
	| relational_expression LEX_GE_OP additive_expression { $$ = new NodeBinaryGe($1, $3); }
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression LEX_EQ_OP relational_expression { $$ = new NodeBinaryEq($1, $3); }
	| equality_expression LEX_NE_OP relational_expression { $$ = new NodeBinaryNe($1, $3); }
	;

logical_and_expression
	: equality_expression { $$ = $1; }
	| logical_and_expression LEX_AND_OP equality_expression { $$ = new NodeBinaryAnd($1, $3); }
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
        | logical_or_expression LEX_OR_OP logical_and_expression { $$ = new NodeBinaryOr($1, $3); }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { $$ = new NodeCondition($1, $3, $5); }
	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression '=' assignment_expression { $$ = new NodeBinaryAss($1, $3); }
	| unary_expression LEX_MUL_ASSIGN assignment_expression { $$ = new NodeBinaryAssMult($1, $3); }
	| unary_expression LEX_DIV_ASSIGN assignment_expression { $$ = new NodeBinaryAssDiv($1, $3); }
	| unary_expression LEX_MOD_ASSIGN assignment_expression { $$ = new NodeBinaryAssMod($1, $3); }
	| unary_expression LEX_ADD_ASSIGN assignment_expression { $$ = new NodeBinaryAssAdd($1, $3); }
	| unary_expression LEX_SUB_ASSIGN assignment_expression { $$ = new NodeBinaryAssSub($1, $3); }
	| unary_expression LEX_REF_ASSIGN assignment_expression { $$ = new NodeBinaryAssRef($1, $3); }
	;

expression
	: assignment_expression { $$ = $1; }
	;

statement
	: compound_statement { $$ = $1; }
	| expression_statement { $$ = new NodePosition($1, new CodePosition(@1.last_column, @1.LINE)); }
	/* "parser.y: conflicts: 1 shift/reduce" is ok */
	| LEX_IF '(' expression ')' statement { $$ = new NodeCondition(new NodePosition($3, new CodePosition(@3.last_column, @3.LINE)), $5, new NodeEmptyCommand); }
	| LEX_IF '(' expression ')' statement LEX_ELSE statement { $$ = new NodeCondition(new NodePosition($3, new CodePosition(@3.last_column, @3.LINE)), $5, $7); }
	| LEX_WHILE '(' expression ')' statement { $$ = new NodeLoop(new NodeEmptyCommand, new NodePosition($3, new CodePosition(@3.last_column, @3.LINE)), new NodeEmptyCommand, $5); }
	| LEX_FOR '(' expression_statement expression_statement ')' statement { $$ = new NodeLoop($3, new NodePosition($4, new CodePosition(@4.last_column, @4.LINE)), new NodeEmptyCommand, $6); }
	| LEX_FOR '(' expression_statement expression_statement expression ')' statement { $$ = new NodeLoop($3, new NodePosition($4, new CodePosition(@4.last_column, @4.LINE)), $5, $7); }
	| LEX_FOREACH '(' LEX_IDENTIFIER ';' expression ')' statement { $$ = new NodeForeach($3, new NodePosition($5, new CodePosition(@5.last_column, @5.LINE)), $7); }
	| LEX_BREAK ';' { $$ = new NodePosition(new NodeJumpBreak, new CodePosition(@2.last_column, @2.LINE)); }
	| LEX_CONTINUE ';' { $$ = new NodePosition(new NodeJumpContinue, new CodePosition(@2.last_column, @2.LINE)); }
	| LEX_RETURN ';' { $$ = new NodePosition(new NodeUnaryReturn(new NodeEmptyCommand), new CodePosition(@2.last_column, @2.LINE)); }
	| LEX_RETURN expression ';' { $$ = new NodePosition(new NodeUnaryReturn($2), new CodePosition(@3.last_column, @3.LINE)); }
	| LEX_GLOBAL LEX_IDENTIFIER ';' { $$ = new NodePosition(new NodeGlobal($2), new CodePosition(@3.last_column, @3.LINE)); }
	;

expression_statement
	: ';' { $$ = new NodeEmptyCommand; }
	| expression ';' { $$ = $1; }
	;

compound_statement
	: '{' '}' { $$ = new NodeEmptyCommand; }
	| '{' block_item_list '}' { $$ = $2; }
	;

block_item_list
	: statement {   $$ = new NodeBlock($1); }
	| block_item_list statement { $1->pushCommandToBack($2); $$ = $1; }
	;

function_definition
	: function_and_name '(' parameter_list ')' compound_statement { CONTEXT->addFunction(new NodeFunctionScript($1, $3, $5, new CodePosition(@1.last_column, @1.LINE))); }
	| function_and_name '(' ')' compound_statement { CONTEXT->addFunction(new NodeFunctionScript($1, new list<identifier>, $4, new CodePosition(@1.last_column, @1.LINE)));   }
	;

function_and_name
	: LEX_FUNCTION LEX_IDENTIFIER { $$ = $2; }
	;

parameter_list
	: LEX_IDENTIFIER { $$ = new list<identifier>; $$->push_back($1); }
	| parameter_list ',' LEX_IDENTIFIER { $1->push_back($3); $$ = $1; }
	;

start
	: /* empty */
	| start function_definition
	;
%%

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
