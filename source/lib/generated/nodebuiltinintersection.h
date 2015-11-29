#ifndef NODEBUILTININTERSECTION_H
#define NODEBUILTININTERSECTION_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinIntersection : public NodeFunction
{
public:
  NodeBuiltinIntersection(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinIntersection(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinIntersection(void);
  NodeBuiltinIntersection(const NodeBuiltinIntersection& object);
  NodeBuiltinIntersection& operator=(const NodeBuiltinIntersection& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinIntersection& node);

#endif /* NODEBUILTININTERSECTION_H */

