#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include "valuegraph.h"
#include "valuebool.h"
#include "valuevertex.h"
#include "valueedge.h"
#include "context.h"
#include "valueint.h"
#include "valuefloat.h"
#include "valuearray.h"
#include "valueset.h"

class heapnode {
  public:
    heapnode(int a, int b): id(a), dist(b) {}
    int id;
    int dist;
};

bool
operator<(const heapnode& a,const  heapnode& b) {
  return a.dist > b.dist;
}

ValueGraph::ValueGraph(bool directed)
  : Value(),
  m_directed(directed),
  m_vertices(),
  m_edges()
{

}

ValueGraph::~ValueGraph(void)
{
  set_container::iterator it;

  for(it = m_vertices.begin(); it != m_vertices.end(); ++it)
    (*it)->toValueVertex()->setGraphToNULL();

  for(it = m_edges.begin(); it != m_edges.end(); ++it)
    (*it)->toValueEdge()->setGraphToNULL();
}

bool 
ValueGraph::loadFromFile(const string& filename)
{
  ifstream is(filename.c_str());

  if(!is.is_open()) {
    std::cerr  << filename.c_str();
    assert(0 && "File was not found or is not readable: ");
    return false;
  }

  m_vertices.clear();
  m_edges.clear();

  int num_vertices = 0;
  int num_edges = 0;
  int num_vertices_props = 0;
  int num_edges_props = 0;
  vector<identifier> vertices_props;
  vector<identifier> edges_props;
  map<int, CountPtr<Value> > vertices;

  // Is directed flag, number of vertices, number of edges
  is >> m_directed;
  is >> num_vertices;
  is >> num_edges;

  // Number of properties for vertices, names of properties for vertices
  is >> num_vertices_props;
  vertices_props.reserve(num_vertices_props);

  for(int i = 0; i < num_vertices_props; i++)
  {
    string name;
    is >> name;
    vertices_props.push_back(STR2ID(name));
  }

  // Number of properties for edges, names of properties for edges
  is >> num_edges_props;
  edges_props.reserve(num_edges_props);

  for(int i = 0; i < num_edges_props; i++) {
    string name;
    is >> name;
    edges_props.push_back(STR2ID(name));
  }

  // Vertices
  for(int j = 0; j < num_vertices; j++) {
    int id = 0;
    is >> id;

    ValueVertex* vertex = new ValueVertex(this);
    CountPtr<Value> valvertex(vertex);
    vertex->setItem(STR2ID("__id"), CountPtr<Value>(new ValueInt(id)));

    for(int i = 0; i < num_vertices_props; i++)
    {
      float value = 0.0f;
      is >> value;
      vertex->setItem(vertices_props[i], CountPtr<Value>(new ValueFloat(value)));
    }

    m_vertices.insert(valvertex);
    vertices.insert(make_pair(id, valvertex));
  }

  // Edges
  for(int j = 0; j < num_edges; j++)
  {
    int id = 0;
    is >> id;

    map<int, CountPtr<Value> >::iterator begin = vertices.find(id);
    if(begin == vertices.end())
    {
      stringstream sstream;
      sstream << "Vertex with ID " << id << " hasn't been defined";
      std::cerr << sstream.str();
      assert(0);
      is.close();
      m_vertices.clear();
      m_edges.clear();
      return false;
    }

    is >> id;

    map<int, CountPtr<Value> >::iterator end = vertices.find(id);
    if(end == vertices.end())
    {
      stringstream sstream;
      sstream << "Vertex with ID " << id << " hasn't been defined";
      std::cerr << sstream.str();
      assert(0);
      is.close();
      m_vertices.clear();
      m_edges.clear();
      return false;
    }

    ValueEdge* edge = new ValueEdge(this, begin->second, end->second);
    CountPtr<Value> valedge(edge);
    (*begin).second->toValueVertex()->addEdge(valedge);
    (*end).second->toValueVertex()->addEdge(valedge);

    for(int i = 0; i < num_edges_props; i++)
    {
      float value = 0.0f;
      is >> value;
      edge->setItem(edges_props[i], CountPtr<Value>(new ValueFloat(value)));
    }

    m_edges.insert(valedge);
  }

  if(!is.good())
  {
    assert(0 && "An error occurred during the graph loading, stream state indicates problem");
    is.close();
    m_vertices.clear();
    m_edges.clear();
    return false;
  }

  is.close();
  return true;
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueGraph::generateVertex(void)
{
  
  CountPtr<Value> vertex(new ValueVertex(this));
  m_vertices.insert(vertex);
  return vertex;
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueGraph::generateEdge(CountPtr<Value> begin, CountPtr<Value> end)
{
  

  ValueVertex* bv = begin->toValueVertex();
  ValueVertex* ev = end->toValueVertex();

  if(bv == NULL || ev == NULL)
  {
    assert(0 && "The parameter is not a vertex");
    return VALUENULL;
  }

  if(!(bv->getGraph() == this && ev->getGraph() == this))
  {
    assert(0 && "The vertices belong to the different graphs");
    return VALUENULL;
  }

  CountPtr<Value> edge(new ValueEdge(this, begin, end));
  m_edges.insert(edge);

  bv->addEdge(edge);
  ev->addEdge(edge);

  return edge;
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueGraph::deleteVertex(CountPtr<Value> vertex)
{
  

  ValueVertex* vv = vertex->toValueVertex();

  if(vv == NULL)
  {
    //WARN_P(_("The parameter is not a vertex"));
    return;
  }

  CountPtr<Value> edges = vv->getEdgesCopy();
  ValueSet* ev = edges->toValueSet();
  assert(ev != NULL);

  set_container::iterator it;
  for(it = ev->begin(); it != ev->end(); ++it)
  {
    (*it)->toValueEdge()->removeVertex(vv);
    deleteEdge(*it);
  }

  vv->clear();
  m_vertices.remove(vertex);
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueGraph::deleteEdge(CountPtr<Value> edge)
{
  

  ValueEdge* ev = edge->toValueEdge();

  if(ev == NULL)
  {
    //WARN_P(_("The parameter is not an edge"));
    return;
  }

  if(ev->getBeginVertex()->toValueVertex() != NULL)
    ev->getBeginVertex()->toValueVertex()->deleteEdge(edge);
  if(ev->getEndVertex()->toValueVertex() != NULL)
    ev->getEndVertex()->toValueVertex()->deleteEdge(edge);

  m_edges.remove(edge);
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueGraph::invertEdgesDirection(void)
{
  

  set_container::iterator it;
  for(it = m_edges.begin(); it != m_edges.end(); ++it)
    (*it)->toValueEdge()->invertDirection();
}


/////////////////////////////////////////////////////////////////////////////
////

bool ValueGraph::toBool(void) const
{
  
  return !m_vertices.empty();
}


/////////////////////////////////////////////////////////////////////////////
////

bool ValueGraph::isDirected(void) const
{
  
  return m_directed;
}


/////////////////////////////////////////////////////////////////////////////
////

bool ValueGraph::setDirected(bool directed)
{
  
  bool ret = m_directed;
  m_directed = directed;
  return ret;
}


/////////////////////////////////////////////////////////////////////////////
////

uint ValueGraph::getNumVertices(void) const
{
  
  return m_vertices.getSize();
}


/////////////////////////////////////////////////////////////////////////////
////

uint ValueGraph::getNumEdges(void) const
{
  
  return m_edges.getSize();
}


/////////////////////////////////////////////////////////////////////////////
////

bool ValueGraph::containsVertex(CountPtr<Value> vertex) const
{
  
  return m_vertices.contains(vertex);
}


/////////////////////////////////////////////////////////////////////////////
////

bool ValueGraph::containsEdge(CountPtr<Value> edge) const
{
  
  return m_edges.contains(edge);
}

CountPtr<Value>
ValueGraph::getShortestPath(const string& wt, 
      ValueVertex* startV, ValueVertex* endV) const
{
  int size = m_vertices.getSize();

  vector< vector<float> > matrix(size, vector<float>(size, 0.0));

  // transition table from vertices to ints
  //setting start and end
  map<ValueVertex*, int> trans_table;
  map<int, ValueVertex*> trans_table_r;
  int pos = 0;
  int start = -1;
  int end = -1;

  set_container::const_iterator it;
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it, pos++) {
    ValueVertex* v = (*it)->toValueVertex();
    if(v == startV) {
      start = pos;
    }
    if(endV && v == endV) {
      end = pos;
    }
    trans_table[v] = pos;
    trans_table_r[pos] = v;
  }

  // Adjacency Matrix
  for(it = m_edges.begin(); it != m_edges.end(); ++it) {
    ValueEdge* edge     = (*it)->toValueEdge();
    ValueVertex* begin  = edge->getBeginVertexPtr();
    ValueVertex* end    = edge->getEndVertexPtr();

    ValueFloat* weight = edge->getItem(STR2ID(wt))->toValueFloat();

    matrix[trans_table[begin]][trans_table[end]] = weight->getVal();
    matrix[trans_table[end]][trans_table[begin]] = weight->getVal();
  }

  /*
  //print the weight matrix   
  std::cout << start << " " << end << "\n ";
  for(int i = 0 ; i < size ; i ++) {
    for(int j = 0 ; j < size ; j ++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n ";
  }
  */

  vector<float> dist(size, INT_MAX);
  vector<int> parent(size, -1);
  dijkstra(matrix, start, end, dist, parent);

  /*
  //print the dist and parent
  for(int v = 0 ; v < size; v++) {
    std::cout << v << " : " << dist[v] << " " << v << "--" << parent[v] << " \n";
  }
  */

  // Convert the parent to the script form
  ValueArray* ret = new ValueArray(2);

  ValueArray* distarray = new ValueArray(size);
  ValueArray* parentarray = new ValueArray(size);

  ret->setItem(0, CountPtr<Value>(parentarray));
  ret->setItem(1, CountPtr<Value>(distarray));

  for(int i = 0; i < size; i++) {
    ValueVertex* v = trans_table_r[parent[i]];
    ValueInt* id = v->getItem(STR2ID("__id"))->toValueInt();
    parentarray->setItem(i, CountPtr<Value>(new ValueInt(id->getVal())));
  }

  for(int i = 0; i < size; i++) {
    distarray->setItem(i, CountPtr<Value>(new ValueFloat(dist[i])));
  }

  return CountPtr<Value>(ret);
}

CountPtr<Value>
ValueGraph::getMST(const string& wt) const
{
  int size = m_vertices.getSize();
  map<ValueVertex*, int> trans_table;
  map<int, ValueVertex*> trans_table_r;

  vector< vector<float> > matrix(size, vector<float>(size, 0.0));

  // transition table from vertices to ints
  int pos = 0;

  set_container::const_iterator it;
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it, pos++) {
    ValueVertex* v = (*it)->toValueVertex();
    trans_table[v] = pos;
    trans_table_r[pos] = v;
  }

  // Adjacency Matrix
  for(it = m_edges.begin(); it != m_edges.end(); ++it) {
    ValueEdge* edge     = (*it)->toValueEdge();
    ValueVertex* begin  = edge->getBeginVertexPtr();
    ValueVertex* end    = edge->getEndVertexPtr();

    ValueFloat* weight = edge->getItem(STR2ID(wt))->toValueFloat();

    matrix[trans_table[begin]][trans_table[end]] = weight->getVal();
    matrix[trans_table[end]][trans_table[begin]] = weight->getVal();
  }

  /*
  //print the weight matrix   
  for(int i = 0 ; i < size ; i ++) {
    for(int j = 0 ; j < size ; j ++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n ";
  }
  */
  vector<float> dist(size, INT_MAX);
  vector<int> parent(size, -1);
  mst(matrix, dist, parent);

  /*
  //print the dist and parent
  for(int v = 0 ; v < size; v++) {
    std::cout << v << " : " << dist[v] << " " << v << "--" << parent[v] << " \n";
  }
  */

  // Convert the dist to the script form
  ValueArray* ret = new ValueArray(2);

  ValueArray* distarray = new ValueArray(size);
  ValueArray* parentarray = new ValueArray(size);

  ret->setItem(0, CountPtr<Value>(parentarray));
  ret->setItem(1, CountPtr<Value>(distarray));

  for(int i = 0; i < size; i++) {
    ValueVertex* v = trans_table_r[parent[i]];
    ValueInt* id = v->getItem(STR2ID("__id"))->toValueInt();
    parentarray->setItem(i, CountPtr<Value>(new ValueInt(id->getVal())));
  }

  for(int i = 0; i < size; i++) {
    distarray->setItem(i, CountPtr<Value>(new ValueFloat(dist[i])));
  }

  return CountPtr<Value>(ret);
}

void
ValueGraph::mst(std::vector<std::vector<float>> &graph, 
    vector<float>& dist, vector<int>& parent) const
{

  int V = dist.size();
  std::priority_queue<heapnode> Q;
  std::vector<bool> visited(V, false);

  Q.push(heapnode(0,0));
  dist[0] = 0.0;
  parent[0] = 0;

  while(false == Q.empty()) {

    heapnode minNode = Q.top();
    Q.pop();
    int minI = minNode.id;


    visited[minI] = true;

    for(int i = 0; i < V; i++) {
      if(i == minI || 0 == graph[minI][i] || true == visited[i]) {
        continue;
      }

      if(graph[minI][i] < dist[i]) {
        dist[i] = graph[minI][i];
        Q.push(heapnode(i, dist[i]));
        parent[i] = minI;
      }
    }
  }
}

void
ValueGraph::dijkstra(std::vector<std::vector<float>> &graph,
      int &start, int &end, vector<float>& dist, 
      vector<int>& parent) const
{

  int V = dist.size();
  std::priority_queue<heapnode> Q;
  std::vector<bool> visited(V, false);

  Q.push(heapnode(0,0));
  dist[start] = start;
  parent[start] = start;

  while(false == Q.empty()) {

    heapnode minNode = Q.top();
    Q.pop();
    int minI = minNode.id;


    visited[minI] = true;
    if(end == minI) {
      break;
    }

    for(int i = 0; i < V; i++) {
      if(i == minI || 0 == graph[minI][i] || true == visited[i]) {
        continue;
      }

      if(dist[minI] + graph[minI][i] < dist[i]) {
        dist[i] = dist[minI] + graph[minI][i];
        Q.push(heapnode(i, dist[i]));
        parent[i] = minI;
      }
    }
  }
}

CountPtr<Value> 
ValueGraph::getTransitiveClosure(void) const
{
  int size = m_vertices.getSize();
  map<ValueVertex*, int> trans_table;
  vector< vector<int> > matrix(size, vector<int>(size, 0));

  // Array of indices
  int pos = 0;
  set_container::const_iterator it;
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it)
    trans_table[(*it)->toValueVertex()] = pos++;

  // Adjacency Matrix
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it) {
    CountPtr<Value> neighbors = (*it)->toValueVertex()->getNeighbors();
    ValueSet* vertices = neighbors->toValueSet();
    assert(vertices != NULL);
    set_container::const_iterator vertex;

    for(vertex = vertices->begin(); vertex != vertices->end(); ++vertex)
    {
      if(!isDirected() && *vertex == *it)
        matrix[trans_table[(*vertex)->toValueVertex()]][trans_table[(*it)->toValueVertex()]] += 2;
      else
        ++matrix[trans_table[(*vertex)->toValueVertex()]][trans_table[(*it)->toValueVertex()]];
    }
  }

  // transitive closure Matrix
  for(int k = 0; k < pos; k++) {
    for(int i = 0; i < pos; i++) {
      for(int j = 0; j < pos; j++) {
        matrix[i][j] = matrix[i][j] | (matrix[i][k] & matrix[k][j]);
      }
    }
  }

  // Convert the matrix to the script form
  ValueArray* ret = new ValueArray(size);
  for(int j = 0; j < size; j++)
  {
    ValueArray* line = new ValueArray(size);
    ret->setItem(j, CountPtr<Value>(line));

    for(int i = 0; i < size; i++)
      line->setItem(i, CountPtr<Value>(new ValueInt(matrix[i][j])));
  }

  return CountPtr<Value>(ret);
}

CountPtr<Value> ValueGraph::getAdjacencyMatrix(void) const
{
  int size = m_vertices.getSize();
  map<ValueVertex*, int> trans_table;
  vector< vector<int> > matrix(size, vector<int>(size, 0));

  // Array of indices
  int pos = 0;
  set_container::const_iterator it;
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it)
    trans_table[(*it)->toValueVertex()] = pos++;

  // Adjacency Matrix
  for(it = m_vertices.begin(); it != m_vertices.end(); ++it)
  {
    CountPtr<Value> neighbors = (*it)->toValueVertex()->getNeighbors();
    ValueSet* vertices = neighbors->toValueSet();
    assert(vertices != NULL);
    set_container::const_iterator vertex;

    for(vertex = vertices->begin(); vertex != vertices->end(); ++vertex)
    {
      if(!isDirected() && *vertex == *it)
        matrix[trans_table[(*vertex)->toValueVertex()]][trans_table[(*it)->toValueVertex()]] += 2;
      else
        ++matrix[trans_table[(*vertex)->toValueVertex()]][trans_table[(*it)->toValueVertex()]];
    }
  }

  // Convert the matrix to the script form
  ValueArray* ret = new ValueArray(size);
  for(int j = 0; j < size; j++)
  {
    ValueArray* line = new ValueArray(size);
    ret->setItem(j, CountPtr<Value>(line));

    for(int i = 0; i < size; i++)
      line->setItem(i, CountPtr<Value>(new ValueInt(matrix[i][j])));
  }

  return CountPtr<Value>(ret);
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueGraph::setPropertyToAllVertices(identifier name, CountPtr<Value> value)
{
  
  m_vertices.setPropertyToAllStructItems(name, value);
}

void ValueGraph::setPropertyToAllEdges(identifier name, CountPtr<Value> value)
{
  
  m_edges.setPropertyToAllStructItems(name, value);
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueGraph::findVertex(ValueVertex* vertex) const
{
  
  return m_vertices.findItem(vertex);
}


/////////////////////////////////////////////////////////////////////////////
////

void ValueGraph::dump(ostream& os, uint indent) const
{
  

  dumpIndent(os, indent);
  os << "<Graph>" << endl;

  dumpIndent(os, indent+1);
  os << "<Vertices>" << endl;

  m_vertices.dump(os, indent+2);

  dumpIndent(os, indent+1);
  os << "</Vertices>" << endl;

  dumpIndent(os, indent+1);
  os << "<Edges>" << endl;

  m_edges.dump(os, indent+2);

  dumpIndent(os, indent+1);
  os << "</Edges>" << endl;

  dumpIndent(os, indent);
  os << "</Graph>" << endl;
}

ostream& operator<<(ostream& os, const ValueGraph& node)
{
  node.dump(os, 0);
  return os;
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> ValueGraph::add(const Value& right)    const { return right.add(*this); } // +
CountPtr<Value> ValueGraph::sub(const Value& right)    const { return right.sub(*this); } // -
CountPtr<Value> ValueGraph::mult(const Value& right)   const { return right.mult(*this); } // *
CountPtr<Value> ValueGraph::div(const Value& right)    const { return right.div(*this); } // /
CountPtr<Value> ValueGraph::mod(const Value& right)    const { return right.mod(*this); } // %
CountPtr<Value> ValueGraph::eq(const Value& right)     const { return right.eq(*this); } // ==
CountPtr<Value> ValueGraph::eq(const ValueGraph& left) const { return (&left == this) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE; }
CountPtr<Value> ValueGraph::ne(const Value& right)     const { return right.ne(*this); } // !=
CountPtr<Value> ValueGraph::ne(const ValueGraph& left) const { return (&left != this) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE; }
CountPtr<Value> ValueGraph::le(const Value& right)     const { return right.le(*this); } // <=
CountPtr<Value> ValueGraph::ge(const Value& right)     const { return right.ge(*this); } // >=
CountPtr<Value> ValueGraph::lt(const Value& right)     const { return right.lt(*this); } // <
CountPtr<Value> ValueGraph::gt(const Value& right)     const { return right.gt(*this); } // >
CountPtr<Value> ValueGraph::member(const Value& right) const { return right.member(*this); } // .
CountPtr<Value> ValueGraph::index(const Value& right)  const { return right.index(*this); } // []
CountPtr<Value> ValueGraph::logNOT(void)               const {  return (m_vertices.empty()) ? VALUEBOOL_TRUE : VALUEBOOL_FALSE; } // !
