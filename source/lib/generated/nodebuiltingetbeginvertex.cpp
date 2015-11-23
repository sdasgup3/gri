#include <cassert>
#include "generated/nodebuiltingetbeginvertex.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valueedge.h"
#include "valuevertex.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetBeginVertex::NodeBuiltinGetBeginVertex(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetBeginVertex::~NodeBuiltinGetBeginVertex(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetBeginVertex::getParametersValues(void) const
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


CountPtr<Value> NodeBuiltinGetBeginVertex::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueEdge* e = NULL;

	if((e = par[0]->toValueEdge()) != NULL)
		return e->getBeginVertex();
	else
	{
		assert(0 && "Bad parameters type: getBeginVertex(edge) : vertex|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGetBeginVertex::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetBeginVertex::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetBeginVertex& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetBeginVertex::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

