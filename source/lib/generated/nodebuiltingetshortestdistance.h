#ifndef NODEBUILTINGETSHORTESTdISTANCE_H
#define NODEBUILTINGETSHORTESTdISTANCE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetShortestDistance : public NodeFunction
{
public:
  NodeBuiltinGetShortestDistance(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetShortestDistance(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetShortestDistance(void);
  NodeBuiltinGetShortestDistance(const NodeBuiltinGetShortestDistance& object);
  NodeBuiltinGetShortestDistance& operator=(const NodeBuiltinGetShortestDistance& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetShortestDistance& node);

#endif /* NODEBUILTINGETsHORTESTdISTANCE_H */

