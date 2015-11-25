#ifndef NODEBUILTINGETSHORTESTPATH_H
#define NODEBUILTINGETSHORTESTPATH_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetShortestPath : public NodeFunction
{
public:
  NodeBuiltinGetShortestPath(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetShortestPath(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetShortestPath(void);
  NodeBuiltinGetShortestPath(const NodeBuiltinGetShortestPath& object);
  NodeBuiltinGetShortestPath& operator=(const NodeBuiltinGetShortestPath& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetShortestPath& node);

#endif /* NODEBUILTINGETSHORTESTPATH_H */

