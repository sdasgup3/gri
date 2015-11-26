#ifndef NODEBUILTINFRONT_H
#define NODEBUILTINFRONT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinFront : public NodeFunction
{
public:
  NodeBuiltinFront(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinFront(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;

private:
  NodeBuiltinFront(void);
  NodeBuiltinFront(const NodeBuiltinFront& object);
  NodeBuiltinFront& operator=(const NodeBuiltinFront& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinFront& node);

#endif /* NODEBUILTINFRONT_H */

