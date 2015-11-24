#include "generated/nodebuiltinprint.h"
#include "valuenull.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPrint::NodeBuiltinPrint(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinPrint::~NodeBuiltinPrint(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinPrint::getParametersValues(void) const
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

CountPtr<Value> NodeBuiltinPrint::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);
  std::cout << par[0]->toString();
  return par[0];
}

const CodePosition* 
NodeBuiltinPrint::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPrint::isBuiltIn(void) const 
{
  return true;
}




ostream& operator<<(ostream& os, const NodeBuiltinPrint& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinPrint::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

