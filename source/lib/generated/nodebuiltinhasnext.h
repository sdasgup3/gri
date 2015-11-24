#ifndef NODEBUILTINHASNEXT_H
#define NODEBUILTINHASNEXT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinHasNext : public NodeFunction
{
public:
  NodeBuiltinHasNext(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinHasNext(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinHasNext(void);
  NodeBuiltinHasNext(const NodeBuiltinHasNext& object);
  NodeBuiltinHasNext& operator=(const NodeBuiltinHasNext& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinHasNext& node);

#endif /* NODEBUILTINHASNEXT_H */

