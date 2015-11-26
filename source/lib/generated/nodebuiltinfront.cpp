#include <cassert>
#include "generated/nodebuiltinfront.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinFront::NodeBuiltinFront(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinFront::~NodeBuiltinFront(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinFront::getParametersValues(void) const
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


CountPtr<Value> NodeBuiltinFront::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueArray* a = NULL;

  if((a = par[0]->toValueArray()) != NULL)
    return a->front();
  else {
    assert(0 && "Bad parameters type: front(array) : object|null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinFront::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinFront::isBuiltIn(void) const 
{
  return true;
}
void 
NodeBuiltinFront::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



ostream& operator<<(ostream& os, const NodeBuiltinFront& node)
{
  node.dump(os, 0);
  return os;
}

