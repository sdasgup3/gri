%{
#include "parser.tab.h"
#include <assert.h>

extern int yyerror( char *);  /* prints grammar violation message */

extern int sym_type(const char *);  /* returns type from symbol table */

#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

static void comment(void);
static void token_dump(const char const *);
static char* strip_quotes(const char const *, int);
%}

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]
S   [ \t]*
ID  [_]?{L}{A}*

%x  INCLUDE

%%
"/*"                                    { 
                                          comment(); 
                                        }
"//".*                                  {
                                        }  
"function"                              { 
                                          token_dump(yytext);
                                          return LEX_FUNCTION;  
                                        }
"return"				{ 
                                          token_dump(yytext);
                                          return LEX_RETURN;  
                                        }
"if"					{ 
                                          token_dump(yytext);
                                          return LEX_IF;     
                                        }
"else"					{ 
                                          token_dump(yytext);
                                          return LEX_ELSE;   
                                        }
"while"					{ 
                                          token_dump(yytext);
                                          return LEX_WHILE; 
                                        }
"for"					{ 
                                          token_dump(yytext);
                                          return LEX_FOR;   
                                        }
"foreach"				{ 
                                          token_dump(yytext);
                                          return LEX_FOREACH;  
                                        }
"break"					{ 
                                          token_dump(yytext);
                                          return LEX_BREAK;    
                                        }
"continue"				{ 
                                          token_dump(yytext);
                                          return LEX_CONTINUE; 
                                        }
"true"				        { 
                                          token_dump(yytext);
                                          return LEX_TRUE;     
                                        }
"false"				        { 
                                          token_dump(yytext);
                                          return LEX_FALSE;    
                                        }
"null"				        { 
                                          token_dump(yytext);
                                          return LEX_NULL;    
                                        }
"global"				{ 
                                          token_dump(yytext);
                                          return LEX_GLOBAL;   
                                        }
"__FILE__"				{ 
                                          yylval.string_val = "dummy";  
                                          token_dump(yytext);
                                          return LEX_STRING; 
                                        }
"__LINE__"				{   
                                          yylval.int_val = 0 ;          
                                          token_dump(yytext);
                                          return LEX_INT;    
                                        }
"__FUNCTION__"				{ 
                                          yylval.string_val = "dummy";  
                                          token_dump(yytext);
                                          return LEX_STRING; 
                                        }

{NZ}{D}*				{
                                          yylval.int_val = atoi(yytext);                                
                                          token_dump(yytext);
                                          return LEX_INT; 
                                        }
"0"{O}*				        {
                                          yylval.int_val = strtol(yytext, NULL, 8);                                
                                          token_dump(yytext);
                                          return LEX_INT; 
                                        }
{HP}{H}+				{ 
                                          yylval.int_val = strtol(yytext, NULL, 16);                                
                                          token_dump(yytext);
                                          return LEX_INT; 
                                        }
{D}+{E}				        { 
                                          yylval.float_val = strtod(yytext, NULL);                                
                                          token_dump(yytext);
                                          return LEX_FLOAT; 
                                        }
{D}*"."{D}*{E}?			        { 
                                          yylval.float_val = strtod(yytext, NULL);                                
                                          token_dump(yytext);
                                          return LEX_FLOAT; 
                                        }
"include"                               { 
                                          token_dump(yytext);
                                          BEGIN(INCLUDE);
                                        }
<INCLUDE>{S}\({S}                         {
                                          token_dump(yytext) ; 
                                        }        
<INCLUDE>\"(\\.|[^\\"])*\"{S}\){S}\;    { 
                                          token_dump(yytext);
                                          char* file = strip_quotes(yytext, yyleng);
                                          yyin = fopen(file, "r");
                                          assert(yyin );
                                          if ( ! yyin )
                                            yyerror("Cannot open include file");
     			                  yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
                                          BEGIN(INITIAL);
                                        }
<<EOF>>                                 {
     			                  yypop_buffer_state();
     
                                          if ( !YY_CURRENT_BUFFER ) {
                                            yyterminate();
                                          }
                                        }
{ID}                                    {
                                          yylval.string_val = yytext;
                                          token_dump(yytext);
                                          return LEX_IDENTIFIER; 
                                        }
\"(\\.|[^\\"])*\"	                { 
                                          yylval.string_val = yytext;
                                          token_dump(yytext);
                                          return LEX_STRING; 
                                        }

"="					{ 
                                          token_dump(yytext);
                                          return '='; 
                                        }   
"=="					{ 
                                          token_dump(yytext);
                                          return LEX_EQ_OP; 
                                        }
"<"					{ 
                                          token_dump(yytext);
                                          return '<'; 
                                        }
"<="					{ 
                                          token_dump(yytext);
                                          return LEX_LE_OP; 
                                        }
"!"					{ 
                                          token_dump(yytext);
                                          return '!'; 
                                        }
"!="					{ 
                                          token_dump(yytext);
                                          return LEX_NE_OP; 
                                        }
">"					{ 
                                          token_dump(yytext);
                                          return '>'; 
                                        }
">="					{ 
                                          token_dump(yytext);
                                          return LEX_GE_OP; 
                                        }
"+"					{ 
                                          token_dump(yytext);
                                          return '+'; 
                                        }
"+="					{ 
                                          token_dump(yytext);
                                          return LEX_ADD_ASSIGN; 
                                        }
"++"					{ 
                                          token_dump(yytext);
                                          return LEX_INC_OP; 
                                        }
"-"					{ 
                                          token_dump(yytext);
                                          return '-'; 
                                        }
"-="					{ 
                                          token_dump(yytext);
                                          return LEX_SUB_ASSIGN; 
                                        }
"--"					{ 
                                          token_dump(yytext);
                                          return LEX_DEC_OP; 
                                        }
"*"					{ 
                                          token_dump(yytext);
                                          return '*'; }
"*="					{ 
                                          token_dump(yytext);
                                          return LEX_MUL_ASSIGN; 
                                        }
"/"					{ 
                                          token_dump(yytext);
                                          return '/'; 
                                        }
"/="					{ 
                                          token_dump(yytext);
                                          return LEX_DIV_ASSIGN; 
                                        }
"%"					{ 
                                          token_dump(yytext);
                                          return '%'; 
                                        }
"%="					{ 
                                          token_dump(yytext);
                                          return LEX_MOD_ASSIGN; 
                                        }
"&&"					{ 
                                          token_dump(yytext);
                                          return LEX_AND_OP; 
                                        }
"&="					{
                                          token_dump(yytext);
                                          return LEX_REF_ASSIGN; 
                                        }
"||"					{ 
                                          token_dump(yytext);
                                          return LEX_OR_OP; 
                                        }
","					{ 
                                          token_dump(yytext);
                                          return ','; 
                                        }
";"					{ 
                                          token_dump(yytext);
                                          return ';'; 
                                        }
"?"					{ 
                                          token_dump(yytext);
                                          return '?'; 
                                        }
"("					{ 
                                          token_dump(yytext);
                                          return '('; 
                                        }
")"					{ 
                                          token_dump(yytext);
                                          return ')'; 
                                        }
"["					{ 
                                          token_dump(yytext);
                                          return '['; 
                                        }
"]"					{ 
                                          token_dump(yytext);
                                          return ']'; 
                                        }
"{"					{ 
                                          token_dump(yytext);
                                          return '{'; 
                                        }
"}"					{ 
                                          token_dump(yytext);
                                          return '}'; 
                                        }
":"					{ 
                                          token_dump(yytext);
                                          return ':'; 
                                        }
{WS}					{ /* whitespace separates tokens */ }
.					{ /* discard bad characters */ }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

static void token_dump(const char const * tok) {
  printf("<%s>\n", tok);
}

static char* strip_quotes(const char const * quoted_str, int len) {
  char* ret = (char*) malloc(len-1);
  int i = 1, k=0;
  for(i = 1;i  < len-1 && quoted_str[i] != '"'; i++) {
    ret[k++] = quoted_str[i];
  }
  ret[k] = '\0';

  token_dump(ret);

  return ret;
}







