#ifndef NODEBUILTINGETMST_H
#define NODEBUILTINGETMST_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetMST : public NodeFunction
{
public:
  NodeBuiltinGetMST(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetMST(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetMST(void);
  NodeBuiltinGetMST(const NodeBuiltinGetMST& object);
  NodeBuiltinGetMST& operator=(const NodeBuiltinGetMST& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetMST& node);

#endif /* NODEBUILTINGETMST_H */

