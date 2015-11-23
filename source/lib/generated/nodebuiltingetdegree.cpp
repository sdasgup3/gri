#include <cassert>
#include "generated/nodebuiltingetdegree.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuevertex.h"
#include "valueint.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetDegree::NodeBuiltinGetDegree(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetDegree::~NodeBuiltinGetDegree(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetDegree::getParametersValues(void) const
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
NodeBuiltinGetDegree::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueVertex* v = NULL;

	if((v = par[0]->toValueVertex()) != NULL)
		return CountPtr<Value>(new ValueInt(v->getDegree()));
	else
	{
		assert(0 &&"Bad parameters type: getDegree(vertex) : int|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGetDegree::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetDegree::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetDegree& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetDegree::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


