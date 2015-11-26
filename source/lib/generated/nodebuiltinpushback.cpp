#include <cassert>
#include "generated/nodebuiltinpushback.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPushBack::NodeBuiltinPushBack(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinPushBack::~NodeBuiltinPushBack(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinPushBack::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinPushBack::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 2);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL) {
    a->pushBack(par[1]);
    return VALUENULL;
  } else {
    assert(0 &&"Bad parameters type: pushBack(array, object) : null");
    return VALUENULL;
  }

}
const CodePosition* 
NodeBuiltinPushBack::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPushBack::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinPushBack::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

ostream& operator<<(ostream& os, const NodeBuiltinPushBack& node)
{
  node.dump(os, 0);
  return os;
}

