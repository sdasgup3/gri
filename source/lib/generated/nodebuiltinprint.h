#ifndef NODEBUILTINPRINT_H
#define NODEBUILTINPRINT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPrint : public NodeFunction
{
public:
  NodeBuiltinPrint(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinPrint(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;

private:
  NodeBuiltinPrint(void);
  NodeBuiltinPrint(const NodeBuiltinPrint& object);
  NodeBuiltinPrint& operator=(const NodeBuiltinPrint& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPrint& node);

#endif /* NODEBUILTINPRINTLN_H */

