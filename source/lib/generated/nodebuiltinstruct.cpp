#include <cassert>
#include "generated/nodebuiltinstruct.h"
#include "valuenull.h"
#include "context.h"
//#include "logger.h"
#include "valuestruct.h"


NodeBuiltinStruct::NodeBuiltinStruct(identifier name, list<identifier>* parameters)
	: NodeFunction(name, parameters)
{

}

NodeBuiltinStruct::~NodeBuiltinStruct(void)
{

}

CountPtr<Value> NodeBuiltinStruct::execute(void)
{
  return CountPtr<Value>(new ValueStruct);

}

const CodePosition* 
NodeBuiltinStruct::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinStruct::isBuiltIn(void) const 
{
  return true;
}



ostream& operator<<(ostream& os, const NodeBuiltinStruct& node)
{
	node.dump(os, 0);
	return os;
}

void 
NodeBuiltinStruct::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;


}

