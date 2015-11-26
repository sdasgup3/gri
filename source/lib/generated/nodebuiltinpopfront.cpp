#include <cassert>
#include "generated/nodebuiltinpopfront.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPopFront::NodeBuiltinPopFront(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinPopFront::~NodeBuiltinPopFront(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinPopFront::getParametersValues(void) const
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

CountPtr<Value> NodeBuiltinPopFront::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL) {
    a->popFront();
    return VALUENULL;
  } else {
    assert(0 && "Bad parameters type: popFront(array) : null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinPopFront::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPopFront::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinPopFront::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


ostream& operator<<(ostream& os, const NodeBuiltinPopFront& node)
{
  node.dump(os, 0);
  return os;
}

