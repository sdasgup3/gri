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

  // Number of properties for edges, names of properties for edges
  is >> num_edges_props;

  std::vector<std::vector<int>> 
    graph(num_vertices, std::vector<int>(num_vertices, 0));
  for(int j = 0; j < num_vertices; j++) {
    int id = 0;
    is >> id;
    vertices.insert(make_pair(id, j));
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
    graph[(*end).second][(*begin).second] = 1;
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
}


bool
isColor(std::vector<std::vector<int>> graph, int k) 
{
  int V = graph.size();
  vector<bool> deleted(V, false);
  vector<int> stack;

  while(stack.size() != V) {
    //FInd the vextex to be deleted
    bool normalD = false;
    for(int i = 0 ; i < V; i++) {
      if(deleted[i]) {
        continue;
      }

      int count = 0;
      for(int j = 0 ; j < V; j++) {
        if(deleted[j]) {
          continue;
        }
        if(1 == graph[i][j]) {
          count++;
        }
      }
      if(count < k) {
        stack.push_back(i);
        deleted[i] = true;
        //cout<< "Normal: " << i << "\n";
        normalD = true;
        break;
      }
    }

    if(false == normalD) {
      //Cannot delete any because degree of all undeleted vertices >=k
      //Delete any
      for(int i = 0 ; i < V; i++) {
        if(deleted[i]) {
          continue;
        }
        //cout<< "Force: " << i << "\n";
        stack.push_back(i);
        deleted[i] = true;
        break;
      }
    }
  }

  int numcolor =0;
  vector<int> finalColor(V, -1);

  while(0 != stack.size()) {
    int vertexToColor = stack.back();
    stack.pop_back();
    deleted[vertexToColor] = false;

    vector<bool> possibleColors(k, true);

    //FInd the colors already occupied by ngbrs
    for(int i = 0 ; i < V ; i++) {

      if(deleted[i] || 0 == graph[vertexToColor][i] || -1 == finalColor[i]) {
        continue;
      }

      //undeleted ngbr
      int ngbrColor = finalColor[i];
      possibleColors[ngbrColor] = false;
    }

    //Find free colors
    for(int  i = 0;  i < k; i++) {
      if(possibleColors[i]) {
        finalColor[vertexToColor] = i;
        break;
      }
    }

    if(-1 == finalColor[vertexToColor]) {
      return false;
    }
  }

  //print coloring
  for(int i = 0 ; i < V; i++) {
    cout << i << " :" << finalColor[i] << "\n"; 
  }
  return true;

}

int main(int argc, char** argv)
{

  string filename(argv[1]);
  std::vector<std::vector<int>> graph = 
    loadFromFile(filename);

  displayADJMatrix(graph);
  
  for(int k = graph.size(); k>=1 ; k--) {
    if(isColor(graph, k)) {
      std::cout << k << " colorable\n";
    } else {
      std::cout << k << " non - colorable\n";
      break;
    }
  }

}

