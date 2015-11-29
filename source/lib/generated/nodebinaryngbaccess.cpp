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

  ValueVertex* start_vv   = m_left_value->toValueVertex();
  ValueSet* start_vs      = m_left_value->toValueSet();
  

  ValueVertex* end_vv     = m_right_value->toValueVertex();
  ValueSet* end_vs        = m_right_value->toValueSet();



  if((NULL == start_vv && NULL == start_vs) || ( NULL  == end_vv && NULL == end_vs) ) {
    assert( 0 && "Bad parameters type: getNeighbors(vertex) : set|null");
    return VALUENULL;
  }



  if(end_vv) {
    if(start_vv) {
      return start_vv->getNeighborEdges(end_vv, type);  
    } else {
      ValueSet* ret = new ValueSet;
      CountPtr<Value> retval(ret);
      for(set_container::iterator it = start_vs->begin();
          it != start_vs->end(); it++) {
        ValueVertex* v = (*it)->toValueVertex();
        CountPtr<Value> edges = v->getNeighborEdges(end_vv, type);  
        ValueSet* edges_vs  = edges->toValueSet();

        for(set_container::iterator jt = edges_vs->begin();
            jt != edges_vs->end(); jt++) {
          ret->insert(*jt);
        }
      }
      return retval;
    }
  } else if(end_vs){
    if(start_vv) {
      return start_vv->getNeighborEdges(end_vs, type);  
    } else {
      ValueSet* ret = new ValueSet;
      CountPtr<Value> retval(ret);
      for(set_container::iterator it = start_vs->begin();
          it != start_vs->end(); it++) {
        ValueVertex* v = (*it)->toValueVertex();
        CountPtr<Value> edges = v->getNeighborEdges(end_vs, type);  
        ValueSet* edges_vs  = edges->toValueSet();

        for(set_container::iterator jt = edges_vs->begin();
            jt != edges_vs->end(); jt++) {
          ret->insert(*jt);
        }
      }
      return retval;
    }
  }
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

