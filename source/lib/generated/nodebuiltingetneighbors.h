#ifndef NODEBUILTINGETNEIGHBORS_H
#define NODEBUILTINGETNEIGHBORS_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetNeighbors : public NodeFunction
{
public:
  NodeBuiltinGetNeighbors(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetNeighbors(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetNeighbors(void);
  NodeBuiltinGetNeighbors(const NodeBuiltinGetNeighbors& object);
  NodeBuiltinGetNeighbors& operator=(const NodeBuiltinGetNeighbors& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetNeighbors& node);

#endif /* NODEBUILTINGETNEIGHBORS_H */

