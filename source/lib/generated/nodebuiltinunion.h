#ifndef NODEBUILTINUNION_H
#define NODEBUILTINUNION_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinUnion : public NodeFunction
{
public:
  NodeBuiltinUnion(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinUnion(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinUnion(void);
  NodeBuiltinUnion(const NodeBuiltinUnion& object);
  NodeBuiltinUnion& operator=(const NodeBuiltinUnion& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinUnion& node);

#endif /* NODEBUILTINUNION_H */

