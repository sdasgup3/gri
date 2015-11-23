#include <cassert>
#include "generated/nodebuiltingenerateedge.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"
#include "valuevertex.h"
#include "valueedge.h"
#include<assert.h>



/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGenerateEdge::NodeBuiltinGenerateEdge(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGenerateEdge::~NodeBuiltinGenerateEdge(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////
vector< CountPtr<Value> > 
NodeBuiltinGenerateEdge::getParametersValues(void) const
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
NodeBuiltinGenerateEdge::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 3);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL && 
            par[1]->toValueVertex() != NULL && par[2]->toValueVertex() != NULL) {
		return g->generateEdge(par[1], par[2]);
        } else {
		assert(0 && "Bad parameters type: generateEdge(graph, vertex, vertex) : edge|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGenerateEdge::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGenerateEdge::isBuiltIn(void) const 
{
  return true;
}




ostream& operator<<(ostream& os, const NodeBuiltinGenerateEdge& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGenerateEdge::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

