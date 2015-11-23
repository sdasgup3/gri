#include <cassert>
#include "generated/nodebuiltingetvertices.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuegraph.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetVertices::NodeBuiltinGetVertices(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetVertices::~NodeBuiltinGetVertices(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetVertices::getParametersValues(void) const
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
NodeBuiltinGetVertices::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL)
		return g->getVertices();
	else
	{
		assert(0 && "Bad parameters type: getVertices(graph) : set|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGetVertices::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetVertices::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetVertices& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetVertices::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


