#include "generated/nodebinaryngbaccess.h"
#include "value.h"
#include "valuenull.h"
#include "context.h"
#include "valuevertex.h"
#include "valueset.h"
#include "valuearray.h"



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
  CountPtr<Value> m_left_value = m_left->execute();
  CountPtr<Value> m_right_value = m_right->execute();

  ValueVertex* start  = m_left_value->toValueVertex();
  ValueVertex* end    = m_right_value->toValueVertex();
  ValueArray* va      = m_right_value->toValueArray();
  ValueSet* vs        = m_right_value->toValueSet();



  if(NULL == start || ( NULL  == end && NULL == va && NULL == vs) ) {
    assert( 0 && "Bad parameters type: getNeighbors(vertex) : set|null");
    return VALUENULL;
  }

  if(end)
    return start->getNeighborEdges(end, type);
  if(vs)
    return start->getNeighborEdges(vs, type);
  if(va)
    return start->getNeighborEdges(va, type);
    
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

