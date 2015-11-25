#include <cassert>
#include "generated/nodebuiltingetshortestpath.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"
#include "valuestring.h"
#include "valuevertex.h"
#include "valuegraph.h"



NodeBuiltinGetShortestPath::NodeBuiltinGetShortestPath(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetShortestPath::~NodeBuiltinGetShortestPath(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetShortestPath::getParametersValues(void) const
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
NodeBuiltinGetShortestPath::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 4);

  ValueGraph*   g     = par[0]->toValueGraph();
  ValueString*  wt    = par[1]->toValueString();
  ValueVertex*  start = par[2]->toValueVertex();
  ValueVertex*  end   = par[3]->toValueVertex();

  if(g == NULL || wt == NULL || start == NULL) {
    assert(0 && "Bad parameters type: getShortestPath(graph) : array");
    return VALUENULL;
  }

  return g->getShortestPath(wt->getVal(), start, end);
}

const CodePosition* 
NodeBuiltinGetShortestPath::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetShortestPath::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetShortestPath& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetShortestPath::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



