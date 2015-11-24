#include <cassert>
#include "generated/nodebuiltiniterator.h"
#include "valuenull.h"
#include "context.h"


NodeBuiltinIterator::NodeBuiltinIterator(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinIterator::~NodeBuiltinIterator(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinIterator::getParametersValues(void) const
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
NodeBuiltinIterator::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  return par[0]->iterator();
}

const CodePosition* 
NodeBuiltinIterator::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinIterator::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinIterator& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinIterator::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


