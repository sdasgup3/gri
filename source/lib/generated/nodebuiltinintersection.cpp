#include <cassert>
#include "generated/nodebuiltinintersection.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valueset.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinIntersection::NodeBuiltinIntersection(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinIntersection::~NodeBuiltinIntersection(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinIntersection::getParametersValues(void) const
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




CountPtr<Value> NodeBuiltinIntersection::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 2);

  ValueSet* vset1 = NULL;
  ValueSet* vset2 = NULL;

  if((vset1 = par[0]->toValueSet()) != NULL && (vset2 = par[1]->toValueSet()) != NULL)
    return vset1->getIntersection(*vset2);
  else {
    assert(0 && "Bad parameters type: intersection(set, set) : set|null");
    return VALUENULL;
  }

}

const CodePosition* 
NodeBuiltinIntersection::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}


bool 
NodeBuiltinIntersection::isBuiltIn(void) const 
{
  return true;
}

void 
NodeBuiltinIntersection::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

ostream& operator<<(ostream& os, const NodeBuiltinIntersection& node)
{
  node.dump(os, 0);
  return os;
}

