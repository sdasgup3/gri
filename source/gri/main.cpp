#include <typeinfo>
#include <stdexcept>
#include "general.h"
#include "context.h"
#include "generated/nodebuiltinprintln.h"
#include "generated/nodebuiltinprint.h"
#include "generated/nodebuiltinstruct.h"
#include "generated/nodebuiltinsize.h"
#include "generated/nodebuiltinarray.h"
#include "generated/nodebuiltingraph.h"
#include "generated/nodebuiltingeneratevertex.h"
#include "generated/nodebuiltingenerateedge.h"
#include "generated/nodebuiltindeleteedge.h"
#include "generated/nodebuiltindeletevertex.h"
#include "generated/nodebuiltinisdirected.h"
#include "generated/nodebuiltinsetdirected.h"
#include "generated/nodebuiltingetnumvertices.h"
#include "generated/nodebuiltingetnumedges.h"
#include "generated/nodebuiltingetdegree.h"
#include "generated/nodebuiltingetbeginvertex.h"
#include "generated/nodebuiltingetendvertex.h"
#include "generated/nodebuiltingetvertices.h"
#include "generated/nodebuiltingetedges.h"
#include "generated/nodebuiltiniterator.h"
#include "generated/nodebuiltinhasnext.h"
#include "generated/nodebuiltinnext.h"
#include "generated/nodebuiltingetneighbors.h"
#include "generated/nodebuiltinloadfromfile.h"
#include "generated/nodebuiltinsavetofile.h"
#include "generated/nodebuiltingetadjacencymatrix.h"
#include "generated/nodebuiltingettransitiveclosure.h"
#include "generated/nodebuiltingetshortestpath.h"
#include "generated/nodebuiltingetmst.h"
#include "generated/nodebuiltinpushfront.h"
#include "generated/nodebuiltinpushback.h"
#include "generated/nodebuiltinpopfront.h"
#include "generated/nodebuiltinpopback.h"
#include "generated/nodebuiltinback.h"
#include "generated/nodebuiltinfront.h"
#include "generated/nodebuiltinintersection.h"
#include "generated/nodebuiltindifference.h"
#include "generated/nodebuiltinunion.h"
#include "generated/nodebuiltingetvertexsetwithproperty.h"

extern int 
parseCode(char*);

int
_debugflag_ = 1;

void
addExternalFunctions(void) {
  std::list<identifier> *fparameters = new std::list<identifier>;
  fparameters->push_back(STR2ID("__a__"));
  fparameters->push_back(STR2ID("__b__"));
  fparameters->push_back(STR2ID("__c__"));
  fparameters->push_back(STR2ID("__d__"));
  fparameters->push_back(STR2ID("__e__"));

  std::list<identifier>::iterator p0 = fparameters->begin();
  std::list<identifier>::iterator p1 = ++p0;
  std::list<identifier>::iterator p2 = ++p0;
  std::list<identifier>::iterator p3 = ++p0;
  std::list<identifier>::iterator p4 = ++p0;
  p0 = fparameters->begin();

  CONTEXT->addFunction(
      new NodeBuiltinPrintln(STR2ID("println"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinPrint(STR2ID("print"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinStruct(STR2ID("struct"), new std::list<identifier>(p0,p0) ));
  CONTEXT->addFunction(
      new NodeBuiltinSize(STR2ID("size"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinArray(STR2ID("array"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGraph(STR2ID("graph"), new std::list<identifier>(p0,p0) ));
  CONTEXT->addFunction(
      new NodeBuiltinGenerateVertex(STR2ID("generateVertex"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGenerateEdge(STR2ID("generateEdge"), new std::list<identifier>(p0,p3) ));
  CONTEXT->addFunction(
      new NodeBuiltinDeleteVertex(STR2ID("deleteVertex"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinDeleteEdge(STR2ID("deleteEdge"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinIsDirected(STR2ID("isDirected"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinSetDirected(STR2ID("setDirected"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetNumVertices(STR2ID("getNumVertices"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetNumEdges(STR2ID("getNumEdges"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetDegree(STR2ID("getDegree"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetBeginVertex(STR2ID("getBeginVertex"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetEndVertex(STR2ID("getEndVertex"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetVertices(STR2ID("getVertices"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetEdges(STR2ID("getEdges"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinIterator(STR2ID("iterator"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinHasNext(STR2ID("hasNext"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinNext(STR2ID("next"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetNeighbors(STR2ID("getNeighbors"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinLoadFromFile(STR2ID("loadFromFile"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinSaveToFile(STR2ID("saveToFile"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetAdjacencyMatrix(STR2ID("getAdjacencyMatrix"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetTransitiveClosure(STR2ID("getTransitiveClosure"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetShortestPath(STR2ID("getShortestPath"), new std::list<identifier>(p0,p4) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetMST(STR2ID("getMST"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinPushFront(STR2ID("pushFront"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinPushBack(STR2ID("pushBack"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinPopFront(STR2ID("popFront"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinPopBack(STR2ID("popBack"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinBack(STR2ID("back"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinFront(STR2ID("front"), new std::list<identifier>(p0,p1) ));
  CONTEXT->addFunction(
      new NodeBuiltinIntersection(STR2ID("intersection"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinDifference(STR2ID("difference"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinUnion(STR2ID("union"), new std::list<identifier>(p0,p2) ));
  CONTEXT->addFunction(
      new NodeBuiltinGetVertexSetWithProperty(STR2ID("getVertexSetWithProperty"), new std::list<identifier>(p0,p3) ));

  delete fparameters;
}


int main(int argc, char** argv)
{

  bool ast_dump = false;

  for(int i = 1 ; i < argc; i++) {

    if(0 == strcmp(argv[i], "-d") || 0 == strcmp(argv[i], "-dump-ast")) {
      ast_dump = true;
    } else if(0 == strcmp(argv[i], "-f") || 0 == strcmp(argv[i], "-file")) {
      i++;
      if(-1 != parseCode(argv[i])) {
        addExternalFunctions();
        if(true == ast_dump) {
          CONTEXT->dump(cout, 0);
        }
        CONTEXT->executeMain(argc - (i+1), &argv[i+1]);
      } else {
        cerr << "file not parsed. Pass a existing file name using -file|-f " << std::endl;
        return 1;
      }
      break;
    } else {
      cerr << "Unrecognized options. (-dump-ast|-d; )" << std::endl;
      return 1;
    }
  }

  return 0;
}
