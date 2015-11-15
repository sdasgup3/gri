#include "generated/nodebinaryadd.h"
#include "value.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryAdd::NodeBinaryAdd(Node* left, Node* right)
	: NodeBinary(left, right)
{

}

NodeBinaryAdd::~NodeBinaryAdd(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryAdd::execute(void)
{
	return m_left->execute()->add(*(m_right->execute()));
}

void NodeBinaryAdd::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryAdd>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryAdd>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryAdd& node)
{
	node.dump(os, 0);
	return os;
}

