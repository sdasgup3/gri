#include <cassert>
#include "generated/nodebuiltinpushfront.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPushFront::NodeBuiltinPushFront(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinPushFront::~NodeBuiltinPushFront(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinPushFront::getParametersValues(void) const
{
  const list<identifier>& pnames = getParameterNames();
  //std::cout <<  pnames.size() << "\n" ;
  vector< CountPtr<Value> > pvalues;
  pvalues.reserve(pnames.size());

  list<identifier>::const_iterator it;
  for(it = pnames.begin(); it != pnames.end(); it++) {
    pvalues.push_back(CONTEXT->getLocalVariable(*it));
  }
  return pvalues;
}




CountPtr<Value> NodeBuiltinPushFront::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 2);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL) {
    a->pushFront(par[1]);
    return VALUENULL;
  } else {
    assert(0 && "Bad parameters type: pushFront(array, object) : null");
    return VALUENULL;
  }

}
const CodePosition* 
NodeBuiltinPushFront::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPushFront::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinPushFront::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


ostream& operator<<(ostream& os, const NodeBuiltinPushFront& node)
{
  node.dump(os, 0);
  return os;
}

