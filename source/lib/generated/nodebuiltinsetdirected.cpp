#include <cassert>
#include "generated/nodebuiltinsetdirected.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuegraph.h"
#include "valuebool.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinSetDirected::NodeBuiltinSetDirected(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinSetDirected::~NodeBuiltinSetDirected(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

vector< CountPtr<Value> > 
NodeBuiltinSetDirected::getParametersValues(void) const
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
NodeBuiltinSetDirected::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 2);

  ValueGraph* g = NULL;

  if((g = par[0]->toValueGraph()) != NULL && par[1]->isNumeric()) {
    return CountPtr<Value>(g->setDirected(par[1]->toBool()) ? 
                    VALUEBOOL_TRUE : VALUEBOOL_FALSE);
  } else {
    assert(0 && "Bad parameters type: setDirected(graph, number) : bool|null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinSetDirected::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinSetDirected::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinSetDirected& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinSetDirected::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}
