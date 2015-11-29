#include <cassert>
#include "valuevertex.h"
#include "valuebool.h"
#include "valuegraph.h"
#include "valueedge.h"
#include "valuefloat.h"
#include "valueint.h"
#include "context.h"
#include "valueset.h"
//#include "logger.h"


/////////////////////////////////////////////////////////////////////////////
////

ValueVertex::ValueVertex(ValueGraph* graph)
  : Value(),
  m_graph(graph),
  m_edges(new ValueSet),
  m_properties(new ValueStruct)
{
  assert(graph != NULL);
}

ValueVertex::~ValueVertex(void)
{
  

  set_container::iterator it;
  for(it = m_edges->begin(); it != m_edges->end(); ++it)
    (*it)->toValueEdge()->removeVertex(this);

  delete m_edges;
  m_edges = NULL;
  delete m_properties;
  m_properties = NULL;
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueVertex::clear(void)
{
  
  m_edges->clear();
  m_properties->clear();
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueVertex::addEdge(CountPtr<Value> edge)
{
  
  assert(edge->toValueEdge() != NULL);
  m_edges->insert(edge);
}

void ValueVertex::deleteEdge(CountPtr<Value> edge)
{
  
  assert(edge->toValueEdge() != NULL);
  m_edges->remove(edge);
}


/////////////////////////////////////////////////////////////////////////////
////
CountPtr<Value> 
ValueVertex::getNeighborEdges(Value* end, int type)
{

  ValueSet* vs = end->toValueSet();
  ValueVertex* vv = end->toValueVertex();
  ValueSet* V;

  if(NULL == vs) {
    V = new ValueSet();
    V->insert(CountPtr<Value>(end));
  } else {
      V = vs;
  }

  
  ValueSet* ret = new ValueSet;
  CountPtr<Value> retval(ret);
  set_container::iterator it;
  set_container::iterator jt;

  if(m_graph == NULL) {
    assert(0 && "The graph is null");
    return VALUENULL;
  }

  assert((type == 1 || 2 == type || 3 == type) && "only possible operators are ->/<-/<->");

  if(false == m_graph->isDirected() && ( 1 == type || 2 == type)) {
    assert(0 && "->/<- are the wrong operators to be used for an undirected graph. Use <-> instead.");
    return VALUENULL;
  }

  if(m_graph->isDirected()) {
    for(it = m_edges->begin(); it != m_edges->end(); ++it) {
      ValueEdge* edge = (*it)->toValueEdge();
      assert(edge != NULL);

      ValueVertex* beginV = edge->getBeginVertex()->toValueVertex();
      ValueVertex* endV = edge->getEndVertex()->toValueVertex();

      for(jt = V->begin(); jt != V->end(); jt++) {
        ValueVertex* e = (*jt)->toValueVertex();
        if(1 == type) {
          if(this == beginV && e == endV) {
            ret->insert(*it);
          }
        } else if(2 == type) {
          if(this == endV && e == beginV) {
            ret->insert(*it);
          }
        } else  {
          if((this == beginV && e == endV) || 
              (e == beginV && this == endV)) {
            ret->insert(*it);
          }
        }
      }
    }
  } else {
    for(it = m_edges->begin(); it != m_edges->end(); ++it) {
      ValueEdge* edge = (*it)->toValueEdge();
      assert(edge != NULL);

      ValueVertex* beginV = edge->getBeginVertex()->toValueVertex();
      ValueVertex* endV = edge->getEndVertex()->toValueVertex();
      assert(beginV != NULL);
      assert(endV != NULL);

      /*
      ValueInt* endID = end->getItem(STR2ID("__id"))->toValueInt();
      ValueInt* beginVID = beginV->getItem(STR2ID("__id"))->toValueInt();
      ValueInt* endVID = endV->getItem(STR2ID("__id"))->toValueInt();

      cout << " end :    "   << endID->getVal() << 
              " beginV : "   << beginVID->getVal()  <<
              " endV :   "   << endVID->getVal()  << "\n";
      */

      for(jt = V->begin(); jt != V->end(); jt++) {
        ValueVertex* e = (*jt)->toValueVertex();
        if((e == beginV && this == endV) || 
            (e == endV && this == beginV)) {
          ret->insert(*it);
        }
      }
    }
  }

  return retval;
}

CountPtr<Value> ValueVertex::getNeighbors(void)
{
  
  ValueSet* ret = new ValueSet;
  CountPtr<Value> retval(ret);
  set_container::iterator it;

  if(m_graph == NULL)
  {
    assert(0 && "The graph is invalid (deleted?)");
    return VALUENULL;
  }

  if(m_graph->isDirected())
  {
    for(it = m_edges->begin(); it != m_edges->end(); ++it)
    {
      ValueEdge* edge = (*it)->toValueEdge();
      assert(edge != NULL);

      if(edge->getBeginVertex()->toValueVertex() == this)
        ret->insert((*it)->toValueEdge()->getEndVertex());
    }
  }
  else
  {
    for(it = m_edges->begin(); it != m_edges->end(); ++it)
    {
      ValueEdge* edge = (*it)->toValueEdge();
      assert(edge != NULL);

      if(edge->getBeginVertex()->toValueVertex() == this)
        ret->insert(edge->getEndVertex());
      else
        ret->insert(edge->getBeginVertex());
    }
  }

  return retval;
}


/////////////////////////////////////////////////////////////////////////////
////

uint ValueVertex::getDegree(void) const
{
  
  return m_edges->getSize();
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueVertex::getEdgesCopy(void)
{
  
  return m_edges->clone();
}

/////////////////////////////////////////////////////////////////////////////
////

void ValueVertex::dump(ostream& os, uint indent) const
{
  

  dumpIndent(os, indent);
  os << "<ValueVertex>" << endl;
  m_properties->dump(os, indent+1);
  dumpIndent(os, indent);
  os << "</ValueVertex>" << endl;
}

ostream& operator<<(ostream& os, const ValueVertex& node)
{
  node.dump(os, 0);
  return os;
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueVertex::add(const Value& right)     const { return right.add(*this); } // +
CountPtr<Value> ValueVertex::sub(const Value& right)     const { return right.sub(*this); } // -
CountPtr<Value> ValueVertex::mult(const Value& right)    const { return right.mult(*this); } // *
CountPtr<Value> ValueVertex::div(const Value& right)     const { return right.div(*this); } // /
CountPtr<Value> ValueVertex::mod(const Value& right)     const { return right.mod(*this); } // %
CountPtr<Value> ValueVertex::eq(const Value& right)      const { return right.eq(*this); } // ==
CountPtr<Value> ValueVertex::eq(const ValueVertex& left) const { return (&left == this) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE; }
CountPtr<Value> ValueVertex::ne(const Value& right)      const { return right.ne(*this); } // !=
CountPtr<Value> ValueVertex::ne(const ValueVertex& left) const { return (&left != this) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE; }
CountPtr<Value> ValueVertex::le(const Value& right)      const { return right.le(*this); } // <=
CountPtr<Value> ValueVertex::ge(const Value& right)      const { return right.ge(*this); } // >=
CountPtr<Value> ValueVertex::lt(const Value& right)      const { return right.lt(*this); } // <
CountPtr<Value> ValueVertex::gt(const Value& right)      const { return right.gt(*this); } // >
CountPtr<Value> ValueVertex::member(const Value& right)  const { return right.member(*this); } // .
CountPtr<Value> ValueVertex::index(const Value& right)   const { return right.index(*this); } // []
CountPtr<Value> ValueVertex::logNOT(void)                const { return VALUEBOOL_FALSE; } // !
