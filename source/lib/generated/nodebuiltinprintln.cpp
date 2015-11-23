#include "generated/nodebuiltinprintln.h"
#include "valuenull.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinPrintln::NodeBuiltinPrintln(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinPrintln::~NodeBuiltinPrintln(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinPrintln::getParametersValues(void) const
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

CountPtr<Value> NodeBuiltinPrintln::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);
  std::cout << par[0]->toString() + '\n';
  return par[0];
}

const CodePosition* 
NodeBuiltinPrintln::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinPrintln::isBuiltIn(void) const 
{
  return true;
}




ostream& operator<<(ostream& os, const NodeBuiltinPrintln& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinPrintln::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

