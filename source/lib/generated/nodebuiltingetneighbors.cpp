#include <cassert>
#include "generated/nodebuiltingetneighbors.h"
#include "valuenull.h"
#include "context.h"
#include "valuevertex.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetNeighbors::NodeBuiltinGetNeighbors(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetNeighbors::~NodeBuiltinGetNeighbors(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetNeighbors::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinGetNeighbors::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueVertex* v = NULL;

  if((v = par[0]->toValueVertex()) != NULL)
    return v->getNeighbors();
  else
  {
    assert( 0 && "Bad parameters type: getNeighbors(vertex) : set|null");
    return VALUENULL;
  }

}
const CodePosition* 
NodeBuiltinGetNeighbors::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetNeighbors::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetNeighbors& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetNeighbors::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


