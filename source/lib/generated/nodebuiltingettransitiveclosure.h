#ifndef NODEBUILTINGETTRANSITIVECLOSURE_H
#define NODEBUILTINGETTRANSITIVECLOSURE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetTransitiveClosure : public NodeFunction
{
public:
  NodeBuiltinGetTransitiveClosure(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetTransitiveClosure(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetTransitiveClosure(void);
  NodeBuiltinGetTransitiveClosure(const NodeBuiltinGetTransitiveClosure& object);
  NodeBuiltinGetTransitiveClosure& operator=(const NodeBuiltinGetTransitiveClosure& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetTransitiveClosure& node);

#endif /* NODEBUILTINGETTRANSITIVECLOSURE_H */

