#include "generated/nodebinaryand.h"
#include "value.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryAnd::NodeBinaryAnd(Node* left, Node* right)
	: NodeBinary(left, right)
{

}

NodeBinaryAnd::~NodeBinaryAnd(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryAnd::execute(void)
{
	return m_left->execute()->logAND(*(m_right->execute()));
}

void NodeBinaryAnd::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryAnd>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryAnd>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryAnd& node)
{
	node.dump(os, 0);
	return os;
}

