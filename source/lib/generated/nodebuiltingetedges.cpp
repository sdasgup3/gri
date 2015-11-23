#include <cassert>
#include "generated/nodebuiltingetedges.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetEdges::NodeBuiltinGetEdges(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetEdges::~NodeBuiltinGetEdges(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetEdges::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinGetEdges::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL)
		return g->getEdges();
	else
	{
		assert( 0 && "Bad parameters type: getEdges(graph) : set|null");
		return VALUENULL;
	}

}
const CodePosition* 
NodeBuiltinGetEdges::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetEdges::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetEdges& node)
{
	node.dump(os, 0);
	return os;
}
void 
NodeBuiltinGetEdges::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


