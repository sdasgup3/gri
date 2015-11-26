#include <cassert>
#include "generated/nodebuiltinback.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinBack::NodeBuiltinBack(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinBack::~NodeBuiltinBack(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinBack::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinBack::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL)
    return a->back();
  else {
    assert(0 && "Bad parameters type: back(array) : object|null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinBack::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinBack::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinBack::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


ostream& operator<<(ostream& os, const NodeBuiltinBack& node)
{
  node.dump(os, 0);
  return os;
}

