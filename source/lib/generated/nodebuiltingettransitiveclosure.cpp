#include <cassert>
#include "generated/nodebuiltingettransitiveclosure.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"


NodeBuiltinGetTransitiveClosure::NodeBuiltinGetTransitiveClosure(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetTransitiveClosure::~NodeBuiltinGetTransitiveClosure(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetTransitiveClosure::getParametersValues(void) const
{
  const list<identifier>& pnames = getParameterNames();
  vector< CountPtr<Value> > pvalues;
  pvalues.reserve(pnames.size());

  list<identifier>::const_iterator it;
  for(it = pnames.begin(); it != pnames.end(); it++) {
    pvalues.push_back(CONTEXT->getLocalVariable(*it));
  }
  return pvalues;
}

CountPtr<Value> 
NodeBuiltinGetTransitiveClosure::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueGraph* g = NULL;

  if((g = par[0]->toValueGraph()) != NULL) {
    return g->getTransitiveClosure();
        } else {
    assert(0 && "Bad parameters type: getTransitiveClosure(graph) : array");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinGetTransitiveClosure::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetTransitiveClosure::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetTransitiveClosure& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetTransitiveClosure::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



