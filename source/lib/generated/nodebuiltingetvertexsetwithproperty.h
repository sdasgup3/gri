#ifndef NODEBUILTINGETVERTEXSETWITHPROPERTY_H
#define NODEBUILTINGETVERTEXSETWITHPROPERTY_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetVertexSetWithProperty : public NodeFunction
{
public:
  NodeBuiltinGetVertexSetWithProperty(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinGetVertexSetWithProperty(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinGetVertexSetWithProperty(void);
  NodeBuiltinGetVertexSetWithProperty(const NodeBuiltinGetVertexSetWithProperty& object);
  NodeBuiltinGetVertexSetWithProperty& operator=(const NodeBuiltinGetVertexSetWithProperty& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetVertexSetWithProperty& node);

#endif 

