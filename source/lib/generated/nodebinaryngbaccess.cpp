#include "generated/nodebinaryngbaccess.h"
#include "value.h"
#include "valuenull.h"
#include "context.h"
#include "valuevertex.h"



/////////////////////////////////////////////////////////////////////////////
////

NodeBinaryNgbAccess::NodeBinaryNgbAccess(Node* left, Node* right, int t)
	: NodeBinary(left, right), type(t)
{

}

NodeBinaryNgbAccess::~NodeBinaryNgbAccess(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBinaryNgbAccess::execute(void)
{
	//return m_left->execute()->add(*(m_right->execute()));
  ValueVertex* start  = m_left->execute()->toValueVertex();
  ValueVertex* end    = m_right->execute()->toValueVertex();

  if(NULL == start || NULL  == end) {
    assert( 0 && "Bad parameters type: getNeighbors(vertex) : set|null");
    return VALUENULL;
  }

  return start->getNeighborEdges(end, type);
    
}

void NodeBinaryNgbAccess::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<NodeBinaryNgbAccess>" << endl;

	m_left->dump(os, indent+1);
	m_right->dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</NodeBinaryNgbAccess>" << endl;
}

ostream& operator<<(ostream& os, const NodeBinaryNgbAccess& node)
{
	node.dump(os, 0);
	return os;
}

