#ifndef NODEBUILTINPUSHFRONT_H
#define NODEBUILTINPUSHFRONT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPushFront : public NodeFunction
{
public:
  NodeBuiltinPushFront(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinPushFront(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinPushFront(void);
  NodeBuiltinPushFront(const NodeBuiltinPushFront& object);
  NodeBuiltinPushFront& operator=(const NodeBuiltinPushFront& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPushFront& node);

#endif /* NODEBUILTINPUSHFRONT_H */

