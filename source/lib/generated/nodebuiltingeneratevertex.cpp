#include <cassert>
#include "generated/nodebuiltingeneratevertex.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"
#include "valuevertex.h"
#include<assert.h>


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGenerateVertex::NodeBuiltinGenerateVertex(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGenerateVertex::~NodeBuiltinGenerateVertex(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

vector< CountPtr<Value> > 
NodeBuiltinGenerateVertex::getParametersValues(void) const
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
NodeBuiltinGenerateVertex::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL) {
		return g->generateVertex();
        } else {
		assert(0 && "Bad parameters type: generateVertex(graph) : vertex|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGenerateVertex::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGenerateVertex::isBuiltIn(void) const 
{
  return true;
}

ostream& operator<<(ostream& os, const NodeBuiltinGenerateVertex& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGenerateVertex::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

