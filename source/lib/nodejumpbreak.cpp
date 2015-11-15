#include "nodejumpbreak.h"
#include "valuenull.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeJumpBreak::NodeJumpBreak()
	: Node()
{

}

NodeJumpBreak::~NodeJumpBreak()
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeJumpBreak::execute(void)
{
	throw this;

	// It will never be called
	return VALUENULL;
}

void NodeJumpBreak::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeJumpBreak />" << endl;
}

ostream& operator<<(ostream& os, const NodeJumpBreak& node)
{
	node.dump(os, 0);
	return os;
}
