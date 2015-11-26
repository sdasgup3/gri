#ifndef NODEBUILTINPUSHBACK_H
#define NODEBUILTINPUSHBACK_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPushBack : public NodeFunction
{
public:
  NodeBuiltinPushBack(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinPushBack(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;

private:
  NodeBuiltinPushBack(void);
  NodeBuiltinPushBack(const NodeBuiltinPushBack& object);
  NodeBuiltinPushBack& operator=(const NodeBuiltinPushBack& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPushBack& node);

#endif /* NODEBUILTINPUSHBACK_H */

