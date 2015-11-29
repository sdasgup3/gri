#ifndef NODEBUILTINDIFFERENCE_H
#define NODEBUILTINDIFFERENCE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinDifference : public NodeFunction
{
public:
  NodeBuiltinDifference(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinDifference(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinDifference(void);
  NodeBuiltinDifference(const NodeBuiltinDifference& object);
  NodeBuiltinDifference& operator=(const NodeBuiltinDifference& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinDifference& node);

#endif /* NODEBUILTINDIFFERENCE_H */

