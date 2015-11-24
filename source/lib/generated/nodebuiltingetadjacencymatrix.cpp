#include <cassert>
#include "generated/nodebuiltingetadjacencymatrix.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"


NodeBuiltinGetAdjacencyMatrix::NodeBuiltinGetAdjacencyMatrix(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetAdjacencyMatrix::~NodeBuiltinGetAdjacencyMatrix(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetAdjacencyMatrix::getParametersValues(void) const
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
NodeBuiltinGetAdjacencyMatrix::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueGraph* g = NULL;

  if((g = par[0]->toValueGraph()) != NULL) {
    return g->getAdjacencyMatrix();
        } else {
    assert(0 && "Bad parameters type: getAdjacencyMatrix(graph) : array");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinGetAdjacencyMatrix::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetAdjacencyMatrix::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetAdjacencyMatrix& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetAdjacencyMatrix::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



