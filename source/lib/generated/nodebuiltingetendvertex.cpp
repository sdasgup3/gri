#include <cassert>
#include "generated/nodebuiltingetendvertex.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valueedge.h"
#include "valuevertex.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGetEndVertex::NodeBuiltinGetEndVertex(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGetEndVertex::~NodeBuiltinGetEndVertex(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetEndVertex::getParametersValues(void) const
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
NodeBuiltinGetEndVertex::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 1);

	ValueEdge* e = NULL;

	if((e = par[0]->toValueEdge()) != NULL)
		return e->getEndVertex();
	else
	{
		assert(0 && "Bad parameters type: getEndVertex(edge) : vertex|null");
		return VALUENULL;
	}

}

const CodePosition* 
NodeBuiltinGetEndVertex::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetEndVertex::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetEndVertex& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGetEndVertex::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

