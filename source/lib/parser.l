%{
#include"parser.hpp"
#include "general.h"
#include "context.h"
//#include  "stringtable.h"
//#define STR2ID(str) STRTABLE.getID(str)
//#define ID2STR(id) STRTABLE.getString(id)
//StringTable STRTABLE;  

#define CONTEXT Context::getInstance()
#define STR2ID(str) CONTEXT->getStringTable()->getID(str)
#define ID2STR(id) CONTEXT.getStringTable()->getString(id)


map<identifier, string> m_defines;
YY_BUFFER_STATE main_buffer = 0 ;
YY_BUFFER_STATE expansion_buffer = 0 ;
  

extern void yyerror( const char *);  /* prints grammar violation message */


static void comment(void);
static void token_dump(const char* const );
static void strip_quotes(const char* const , int , std::string &, std::string &);
static bool expandMacro(std::string m_string);

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
QS  \"(\\.|[^\\"])*\"

%x  INCLUDE
%x  DEFINE

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
{D}"."{D}*{E}?			        { 
                                          yylval.float_val = strtod(yytext, NULL);                                
                                          token_dump(yytext);
                                          return LEX_FLOAT; 
                                        }
"."                                     {
                                          token_dump(yytext);
                                          return '.'; 
                                        }
"define"                                { 
                                          token_dump(yytext);
                                          BEGIN(DEFINE);
                                        }
<DEFINE>{S}\({S}                        {
                                          token_dump(yytext) ; 
                                        }        
<DEFINE>{QS}{S}\,{S}{QS}{S}\){S}\;      { 
                                          token_dump(yytext);
                                          std::string name1(""), name2("");
                                          strip_quotes(yytext, yyleng, name1, name2);
                                          pair< map<identifier, string>::iterator, bool > ret;
	                                  ret = m_defines.insert(pair<identifier,std::string>(STR2ID(std::string(name1.c_str())), std::string(name2.c_str())));
	                                  if(ret.second == false) {
		                            yyerror("Macro has been already defined: ");
                                          }
                                          BEGIN(INITIAL);
                                        }
"include"                               { 
                                          token_dump(yytext);
                                          BEGIN(INCLUDE);
                                        }
<INCLUDE>{S}\({S}                         {
                                          token_dump(yytext) ; 
                                        }        
<INCLUDE>{QS}{S}\){S}\;                 { 
                                          token_dump(yytext);
                                          std::string name1(""), name2("");
                                          strip_quotes(yytext, yyleng, name1, name2);
                                          yyin = fopen(name1.c_str(), "r");
                                          assert(yyin );
                                          if ( ! yyin )
                                            yyerror("Cannot open include file");
     			                  yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
                                          BEGIN(INITIAL);
                                        }
<<EOF>>                                 {
                                          if ( expansion_buffer ) {
                                            yy_switch_to_buffer(main_buffer);
                                            yy_delete_buffer(expansion_buffer);
                                            expansion_buffer = 0;
                                          } else {
     			                    yypop_buffer_state();
     
                                            if ( !YY_CURRENT_BUFFER ) {
                                              yyterminate();
                                            }
                                          }
                                        }
{ID}                                    {
                                          yylval.string_val = yytext;
                                          token_dump(yytext);
                                          if(false == expandMacro(std::string(yytext))) {
                                            return LEX_IDENTIFIER; 
                                          }
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

int yywrap(void)        
{
    return 1;          
}

static void comment(void)
{
    int c;

    while ((c = yyinput()) != 0)
        if (c == '*')
        {
            while ((c = yyinput()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

static void token_dump(const char* const  tok) {
  printf("<%s>\n", tok);
}

//static void token_dump(std::string &tok) {
//  std::cout << "<" << tok << ">"<< std::endl;
//}

static void 
strip_quotes(const char* const quoted_str, int len, std::string &name1, std::string &name2) {
  int i = 1;
  for(i = 1;i  < len-1 && quoted_str[i] != '"'; i++) {
    name1.push_back(quoted_str[i]);
  }
  name1.push_back('\0');
  token_dump(name1.c_str());

  while(quoted_str[i] != ' ' && quoted_str[i] != '\0') { i ++;}
  if('\0' == quoted_str[i]) {
    return;   
  }

  while(quoted_str[i] != '"' && quoted_str[i] != '\0') { i ++;}

  if('\0' == quoted_str[i]) {
    yyerror("Invalid input");
    return;   
  }
  i++;
  for(;'\0' != quoted_str[i] && '"' != quoted_str[i] ; i++) {
    name2.push_back(quoted_str[i]);
  }
  name2.push_back('\0');
  token_dump(name2.c_str());

  return ;
}

static bool 
expandMacro(std::string m_string)
{
  map<identifier, string>::iterator it = m_defines.find(STR2ID(m_string));
  if(it != m_defines.end()) {
    //std::cout << "DSAND: " << m_string << " " << STR2ID(m_string) << "\n";
    main_buffer = YY_CURRENT_BUFFER;
    expansion_buffer = yy_scan_string(it->second.c_str());
    yy_switch_to_buffer(expansion_buffer);
    return true;
  }

}
