#include <cassert>
#include "generated/nodebuiltingraph.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"

/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinGraph::NodeBuiltinGraph(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinGraph::~NodeBuiltinGraph(void)
{

}


CountPtr<Value> 
NodeBuiltinGraph::execute(void)
{
	return CountPtr<Value>(new ValueGraph);
}

const CodePosition* 
NodeBuiltinGraph::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGraph::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGraph& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinGraph::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

