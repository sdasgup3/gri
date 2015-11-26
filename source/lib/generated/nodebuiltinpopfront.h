#ifndef NODEBUILTINPOPFRONT_H
#define NODEBUILTINPOPFRONT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPopFront : public NodeFunction
{
public:
  NodeBuiltinPopFront(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinPopFront(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinPopFront(void);
  NodeBuiltinPopFront(const NodeBuiltinPopFront& object);
  NodeBuiltinPopFront& operator=(const NodeBuiltinPopFront& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPopFront& node);

#endif /* NODEBUILTINPOPFRONT_H */

