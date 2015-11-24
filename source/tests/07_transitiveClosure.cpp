function displayAdjacencyMatrix(matrix, vertices)
{
  foreach(vertex; vertices.iterator()) {
    print(" " + vertex.__id + " ");
  }

  println("");

  it = vertices.iterator();
  foreach(line; matrix.iterator()) {
        if(it.hasNext())
            vertex = it.next();

        print("" + vertex.__id + " |");
        
    foreach(item; line.iterator())
            print("" + item + " ");

        println("");
    }
}


function main(argv) 
{
  g = graph();
  g.loadFromFile("graphs/01_transClosure.txt");
  matrix = g.getAdjacencyMatrix();
  displayAdjacencyMatrix(g.getAdjacencyMatrix(), g.getVertices());
  matrix = g.getTransitiveClosure();
  displayAdjacencyMatrix(matrix, g.getVertices());
}
