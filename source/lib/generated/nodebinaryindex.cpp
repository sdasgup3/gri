#include "generated/nodebinaryindex.h"
#include "value.h"
#include <typeinfo>


/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryIndex::NodeBinaryIndex(Node* left, Node* right)
	: NodeBinary(left, right)
{

}

NodeBinaryIndex::~NodeBinaryIndex(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryIndex::execute(void)
{
  //std::cout<< "NodeBinaryIndex::execute||" << typeid(*(m_left->execute())).name() << " " <<typeid(*(m_right->execute())).name() << "||\n";
  return m_left->execute()->index(*(m_right->execute()));
}

void NodeBinaryIndex::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryIndex>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryIndex>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryIndex& node)
{
	node.dump(os, 0);
	return os;
}

