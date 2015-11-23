#include <cassert>
#include "generated/nodebuiltindeleteedge.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinDeleteEdge::NodeBuiltinDeleteEdge(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinDeleteEdge::~NodeBuiltinDeleteEdge(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////
vector< CountPtr<Value> > 
NodeBuiltinDeleteEdge::getParametersValues(void) const
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
NodeBuiltinDeleteEdge::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 2);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL && par[1]->toValueEdge() != NULL) {
		g->deleteEdge(par[1]);
        } else {
		assert(0 &&"Bad parameters type: deleteEdge(graph, edge) : null");
        }

	return VALUENULL;

}

const CodePosition* 
NodeBuiltinDeleteEdge::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinDeleteEdge::isBuiltIn(void) const 
{
  return true;
}

ostream& operator<<(ostream& os, const NodeBuiltinDeleteEdge& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinDeleteEdge::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

