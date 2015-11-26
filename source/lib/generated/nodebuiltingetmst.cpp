#include <cassert>
#include "generated/nodebuiltingetmst.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"
#include "valuestring.h"
#include "valuevertex.h"
#include "valuegraph.h"


NodeBuiltinGetMST::NodeBuiltinGetMST(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetMST::~NodeBuiltinGetMST(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetMST::getParametersValues(void) const
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
NodeBuiltinGetMST::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 2);

  ValueGraph*   g     = par[0]->toValueGraph();
  ValueString*  wt    = par[1]->toValueString();

  if(g == NULL || wt == NULL) {
    assert(0 && "Bad parameters type: getShortestPath(graph) : array");
    return VALUENULL;
  }

  return g->getMST(wt->getVal());
}

const CodePosition* 
NodeBuiltinGetMST::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetMST::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetMST& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetMST::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}



