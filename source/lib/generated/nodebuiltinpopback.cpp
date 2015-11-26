#include <cassert>
#include "generated/nodebuiltinpopback.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPopBack::NodeBuiltinPopBack(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinPopBack::~NodeBuiltinPopBack(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinPopBack::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinPopBack::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL) {
    a->popBack();
    return VALUENULL;
  } else {
    assert(0 && "Bad parameters type: popBack(array) : null");
    return VALUENULL;
  }

}
const CodePosition* 
NodeBuiltinPopBack::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPopBack::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinPopBack::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



ostream& operator<<(ostream& os, const NodeBuiltinPopBack& node)
{
  node.dump(os, 0);
  return os;
}

