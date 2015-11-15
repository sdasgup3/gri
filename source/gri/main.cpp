#include <typeinfo>
#include <stdexcept>
#include "general.h"
#include "context.h"
#include "generated/nodebuiltinprintln.h"


extern int 
parseCode(char*);

int
_debugflag_ = 1;

void
addExternalFunctions(void) {
  std::list<identifier> *fparameters = new std::list<identifier>;
  fparameters->push_back(STR2ID("__a__"));
  fparameters->push_back(STR2ID("__b__"));
  fparameters->push_back(STR2ID("__c__"));
  fparameters->push_back(STR2ID("__d__"));
  fparameters->push_back(STR2ID("__e__"));

  std::list<identifier>::iterator p0 = fparameters->begin();
  std::list<identifier>::iterator p1 = ++p0;
  p0 = fparameters->begin();

  CONTEXT->addFunction(
      new NodeBuiltinPrintln(STR2ID("println"), new std::list<identifier>(p0,p1) ));

  delete fparameters;
}


int main(int argc, char** argv)
{

  bool ast_dump = false;
  bool parsecode = false;

  for(int i = 1 ; i < argc; i++) {

    if(0 == strcmp(argv[i], "-d") || 0 == strcmp(argv[i], "-dump-ast")) {
      ast_dump = true;
    } else if(0 == strcmp(argv[i], "-f") || 0 == strcmp(argv[i], "-file")) {
      i++;
      if(-1 != parseCode(argv[i])) {
        parsecode = true;
        addExternalFunctions();
        if(true == ast_dump) {
          CONTEXT->dump(cout, 0);
        }
        CONTEXT->executeMain(argc - (i+1), &argv[i+1]);
      } else {
        cerr << "file not parsed. Pass a existing file name using -file|-f " << std::endl;
        return 1;
      }
      break;
    } else {
      cerr << "Unrecognized options. (-dump-ast|-d; )" << std::endl;
      return 1;
    }
  }

  return 0;
}
