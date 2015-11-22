#include <cassert>
#include "generated/nodebuiltinarray.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuearray.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinArray::NodeBuiltinArray(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinArray::~NodeBuiltinArray(void)
{

}


/////////////////////////////////////////////////////////////////////////////

vector< CountPtr<Value> > 
NodeBuiltinArray::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinArray::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	if(par[0]->isNumeric())
		return CountPtr<Value>(new ValueArray(par[0]->toInt()));
	else
	{
		assert(0 && "Bad parameters type: array(number) : array|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinArray::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinArray::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinArray& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinArray::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

