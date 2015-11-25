#include <cassert>
#include "generated/nodebuiltingetshortestdistance.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"
#include "valuestring.h"
#include "valuevertex.h"
#include "valuegraph.h"


NodeBuiltinGetShortestDistance::NodeBuiltinGetShortestDistance(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetShortestDistance::~NodeBuiltinGetShortestDistance(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetShortestDistance::getParametersValues(void) const
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
NodeBuiltinGetShortestDistance::execute(void)
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

  return g->getShortestDistance(wt->getVal(), start, end);
}

const CodePosition* 
NodeBuiltinGetShortestDistance::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetShortestDistance::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetShortestDistance& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetShortestDistance::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



