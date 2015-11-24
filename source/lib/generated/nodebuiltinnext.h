#ifndef NODEBUILTINNEXT_H
#define NODEBUILTINNEXT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinNext : public NodeFunction
{
public:
  NodeBuiltinNext(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinNext(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinNext(void);
  NodeBuiltinNext(const NodeBuiltinNext& object);
  NodeBuiltinNext& operator=(const NodeBuiltinNext& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinNext& node);

#endif /* NODEBUILTINNEXT_H */

