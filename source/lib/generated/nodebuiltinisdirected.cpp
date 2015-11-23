#include <cassert>
#include "generated/nodebuiltinisdirected.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuebool.h"
#include "valuegraph.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinIsDirected::NodeBuiltinIsDirected(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinIsDirected::~NodeBuiltinIsDirected(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

vector< CountPtr<Value> > 
NodeBuiltinIsDirected::getParametersValues(void) const
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


CountPtr<Value> 
NodeBuiltinIsDirected::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueGraph* g = NULL;

  if((g = par[0]->toValueGraph()) != NULL)
    return CountPtr<Value>((g->isDirected()) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE);
  else
  {
    assert(0 && "Bad parameters type: isDirected(graph) : bool|null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinIsDirected::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinIsDirected::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinIsDirected& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinIsDirected::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


