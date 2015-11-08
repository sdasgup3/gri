#include <typeinfo>
#include <stdexcept>
#include "general.h"


extern int 
parseCode(char*);


int main(int argc, char** argv)
{
  if(argc > 0) {
    parseCode(argv[1]);
  }
  return 0;
}
