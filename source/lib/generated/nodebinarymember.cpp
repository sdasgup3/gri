#include "generated/nodebinarymember.h"
#include "value.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryMember::NodeBinaryMember(Node* left, Node* right)
	: NodeBinary(left, right)
{

}

NodeBinaryMember::~NodeBinaryMember(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryMember::execute(void)
{
	return m_left->execute()->member(*(m_right->execute()));
}

void NodeBinaryMember::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryMember>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryMember>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryMember& node)
{
	node.dump(os, 0);
	return os;
}

