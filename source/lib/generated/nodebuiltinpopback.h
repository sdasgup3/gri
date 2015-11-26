#ifndef NODEBUILTINPOPBACK_H
#define NODEBUILTINPOPBACK_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPopBack : public NodeFunction
{
public:
  NodeBuiltinPopBack(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinPopBack(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinPopBack(void);
  NodeBuiltinPopBack(const NodeBuiltinPopBack& object);
  NodeBuiltinPopBack& operator=(const NodeBuiltinPopBack& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPopBack& node);

#endif /* NODEBUILTINPOPBACK_H */

