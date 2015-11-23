#include <cassert>
#include "generated/nodebuiltindeletevertex.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinDeleteVertex::NodeBuiltinDeleteVertex(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinDeleteVertex::~NodeBuiltinDeleteVertex(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

vector< CountPtr<Value> > 
NodeBuiltinDeleteVertex::getParametersValues(void) const
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
NodeBuiltinDeleteVertex::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 2);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL && par[1]->toValueVertex() != NULL)
		g->deleteVertex(par[1]);
	else
		assert(0 && "Bad parameters type: deleteVertex(graph, vertex) : null");

	return VALUENULL;

}

const CodePosition* 
NodeBuiltinDeleteVertex::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinDeleteVertex::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinDeleteVertex& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinDeleteVertex::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}
