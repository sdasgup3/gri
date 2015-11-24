#include <cassert>
#include "generated/nodebuiltinhasnext.h"
#include "valuenull.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinHasNext::NodeBuiltinHasNext(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinHasNext::~NodeBuiltinHasNext(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinHasNext::getParametersValues(void) const
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
NodeBuiltinHasNext::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  return par[0]->hasNext();
}

const CodePosition* 
NodeBuiltinHasNext::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinHasNext::isBuiltIn(void) const 
{
  return true;
}

ostream& operator<<(ostream& os, const NodeBuiltinHasNext& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinHasNext::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

