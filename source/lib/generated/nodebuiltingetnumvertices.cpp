#include <cassert>
#include "generated/nodebuiltingetnumvertices.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuegraph.h"
#include "valueint.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetNumVertices::NodeBuiltinGetNumVertices(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetNumVertices::~NodeBuiltinGetNumVertices(void)
{

}


/////////////////////////////////////////////////////////////////////////////

vector< CountPtr<Value> > 
NodeBuiltinGetNumVertices::getParametersValues(void) const
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



CountPtr<Value> NodeBuiltinGetNumVertices::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueGraph* g = NULL;

	if((g = par[0]->toValueGraph()) != NULL)
		return CountPtr<Value>(new ValueInt(g->getNumVertices()));
	else
	{
		assert(0 && "Bad parameters type: getNumVertices(graph) : int|null");
		return VALUENULL;
	}

}
const CodePosition* 
NodeBuiltinGetNumVertices::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetNumVertices::isBuiltIn(void) const 
{
  return true;
}




ostream& operator<<(ostream& os, const NodeBuiltinGetNumVertices& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetNumVertices::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

