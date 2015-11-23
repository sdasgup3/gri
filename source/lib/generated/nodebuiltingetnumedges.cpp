#include <cassert>
#include "generated/nodebuiltingetnumedges.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuegraph.h"
#include "valueint.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetNumEdges::NodeBuiltinGetNumEdges(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetNumEdges::~NodeBuiltinGetNumEdges(void)
{

}


/////////////////////////////////////////////////////////////////////////////

vector< CountPtr<Value> > 
NodeBuiltinGetNumEdges::getParametersValues(void) const
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
NodeBuiltinGetNumEdges::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL)
		return CountPtr<Value>(new ValueInt(g->getNumEdges()));
	else
	{
		assert(0 && "Bad parameters type: getNumEdges(graph) : int|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGetNumEdges::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetNumEdges::isBuiltIn(void) const 
{
  return true;
}

ostream& operator<<(ostream& os, const NodeBuiltinGetNumEdges& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetNumEdges::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


