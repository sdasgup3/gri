#include<iostream> 
#include<vector> 
#include<climits> 
#include<cassert> 
#include<fstream> 
#include<map> 

using namespace std;

std::vector<std::vector<int>> 
loadFromFile(std::string& filename) {

  ifstream is(filename.c_str());

  if(!is.is_open()) {
    std::cerr  << filename.c_str();
    assert(0 && "File was not found or is not readable: ");
  }

  int m_directed;
  int num_vertices = 0;
  int num_edges = 0;
  int num_vertices_props = 0;
  int num_edges_props = 0;

  map<int, int > vertices;

  // Is directed flag, number of vertices, number of edges
  is >> m_directed;
  is >> num_vertices;
  is >> num_edges;

  // Number of properties for vertices, names of properties for vertices
  is >> num_vertices_props;
  for(int i = 0; i < num_vertices_props; i++) {
    string name;
    is >> name;
  }

  // Number of properties for edges, names of properties for edges
  is >> num_edges_props;
  for(int i = 0; i < num_edges_props; i++) { 
    string name;
    is >> name;
  }
  
   // Vertices
  std::vector<std::vector<int>> 
    graph(num_vertices, std::vector<int>(num_vertices, 0));
  for(int j = 0; j < num_vertices; j++) {
    int id = 0;
    is >> id;
    vertices.insert(make_pair(id, j));
    
    for(int i = 0; i < num_vertices_props; i++) {
      float value = 0.0f;
      is >> value;
    }
  }

  // Edges
  for(int j = 0; j < num_edges; j++) {
    int id = 0;
    is >> id;

    map<int, int >::iterator begin = vertices.find(id);
    if(begin == vertices.end()) {
      assert(0 && "edge id does not belong to a vertex");
    }

    is >> id;

    map<int, int >::iterator end = vertices.find(id);
    if(end == vertices.end()) {
      assert(0 && "edge id does not belong to a vertex");
    }

    graph[(*begin).second][(*end).second] = 1;
    if(0 == m_directed) {
      graph[(*end).second][(*begin).second] = 1;
    }

    for(int i = 0; i < num_edges_props; i++) {
      float value = 0.0f;
      is >> value;
    }

  }

  is.close();
  return graph;
}

void
displayADJMatrix(std::vector<std::vector<int>> &graph) 
{
  int size = graph.size();
  std::cout << "  ";
  for(int i = 0 ; i < size; i++) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  for(int i = 0 ; i < size; i++) {
    std::cout << i << "|";
    for(int j  = 0 ; j <  size; j++) {
      std::cout << graph[i][j] << " "; 
    }
    std::cout << "\n"; 
  }
    std::cout << "\n"; 
}


int main(int argc, char** argv)
{

  string filename(argv[1]);
  std::vector<std::vector<int>> graph = 
    loadFromFile(filename);

  displayADJMatrix(graph);
  int size =  graph.size();
  
  for(int k = 0; k < size;  k++) {
    for(int i = 0; i < size;  i++) {
      for(int j = 0; j < size;  j++) {
        graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
      }
    }
  }
  displayADJMatrix(graph);

}

