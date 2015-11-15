#include "generated/nodebinaryass.h"
#include "value.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryAss::NodeBinaryAss(Node* left, Node* right)
	: NodeBinary(left, right)
{

}

NodeBinaryAss::~NodeBinaryAss(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryAss::execute(void)
{
	return m_left->execute()->assign(m_right->execute());
}

void NodeBinaryAss::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryAss>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryAss>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryAss& node)
{
	node.dump(os, 0);
	return os;
}

