#ifndef NODEBUILTINGETADJACENCYMATRIX_H
#define NODEBUILTINGETADJACENCYMATRIX_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetAdjacencyMatrix : public NodeFunction
{
public:
  NodeBuiltinGetAdjacencyMatrix(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetAdjacencyMatrix(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetAdjacencyMatrix(void);
  NodeBuiltinGetAdjacencyMatrix(const NodeBuiltinGetAdjacencyMatrix& object);
  NodeBuiltinGetAdjacencyMatrix& operator=(const NodeBuiltinGetAdjacencyMatrix& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetAdjacencyMatrix& node);

#endif /* NODEBUILTINGETADJACENCYMATRIX_H */

