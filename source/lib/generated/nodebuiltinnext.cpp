#include <cassert>
#include "generated/nodebuiltinnext.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinNext::NodeBuiltinNext(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinNext::~NodeBuiltinNext(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinNext::getParametersValues(void) const
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


CountPtr<Value> NodeBuiltinNext::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  return par[0]->next();
}

const CodePosition* 
NodeBuiltinNext::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinNext::isBuiltIn(void) const 
{
  return true;
}

ostream& operator<<(ostream& os, const NodeBuiltinNext& node)
{
  node.dump(os, 0);
  return os;
}
void 
NodeBuiltinNext::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

