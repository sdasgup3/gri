#include <typeinfo>
#include <stdexcept>
#include "general.h"
#include "context.h"


extern int 
parseCode(char*);


int main(int argc, char** argv)
{

  bool ast_dump = false;
  bool parsecode = false;

  for(int i = 1 ; i < argc; i++) {
    if(0 == strcmp(argv[i], "-d") || 0 == strcmp(argv[i], "-dump-ast")) {
      ast_dump = true;
    } else if(0 == strcmp(argv[i], "-f") || 0 == strcmp(argv[i], "-file")) {
      if(-1 != parseCode(argv[i+1])) {
        parsecode = true;
        i++;
      } else {
        break;
      }
    } else {
      cerr << "Unrecognized options. (-dump-ast|-d; )" << std::endl;
      return 1;
    }
  }

  if(false == parsecode) {
    cerr << "file not parsed. Pass a existing file name using -file|-f " << std::endl;
    return 1;
  }

  if(true == ast_dump) {
    CONTEXT->dump(cout, 0);
  }


  return 0;
}
