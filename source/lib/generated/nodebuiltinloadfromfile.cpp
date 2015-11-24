#include <cassert>
#include "generated/nodebuiltinloadfromfile.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"
#include "valuestring.h"
#include "valuebool.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinLoadFromFile::NodeBuiltinLoadFromFile(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinLoadFromFile::~NodeBuiltinLoadFromFile(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinLoadFromFile::getParametersValues(void) const
{
  const list<identifier>& pnames = getParameterNames();
  vector< CountPtr<Value> > pvalues;
  pvalues.reserve(pnames.size());

  list<identifier>::const_iterator it;
  for(it = pnames.begin(); it != pnames.end(); it++) {
    pvalues.push_back(CONTEXT->getLocalVariable(*it));
  }
  return pvalues;
}



CountPtr<Value> NodeBuiltinLoadFromFile::execute(void)
{
	vector< CountPtr<Value> > par = getParametersValues();
	assert(par.size() == 2);

	ValueGraph* g = NULL;
	ValueString* path = NULL;

	if((g = par[0]->toValueGraph()) != NULL && (path = par[1]->toValueString()) != NULL)
		return g->loadFromFile(path->getVal()) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE;
	else
	{
		assert(0 &&"Bad parameters type: loadFromFile(graph, string) : bool");
		return VALUEBOOL_FALSE;
	}

}

const CodePosition* 
NodeBuiltinLoadFromFile::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinLoadFromFile::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinLoadFromFile& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinLoadFromFile::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


