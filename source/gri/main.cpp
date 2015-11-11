#include <typeinfo>
#include <stdexcept>
#include "general.h"
#include "context.h"


extern int 
parseCode(char*);


int main(int argc, char** argv)
{
  if(argc > 0) {
    parseCode(argv[1]);
 //   CONTEXT->dump(cout, 0);
  }
  return 0;
}
