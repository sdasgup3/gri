#ifndef NODEBUILTINBACK_H
#define NODEBUILTINBACK_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinBack : public NodeFunction
{
public:
  NodeBuiltinBack(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinBack(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;

private:
  NodeBuiltinBack(void);
  NodeBuiltinBack(const NodeBuiltinBack& object);
  NodeBuiltinBack& operator=(const NodeBuiltinBack& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinBack& node);

#endif /* NODEBUILTINBACK_H */

