#ifndef NODEBUILTINLOADFROMFILE_H
#define NODEBUILTINLOADFROMFILE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinLoadFromFile : public NodeFunction
{
public:
  NodeBuiltinLoadFromFile(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinLoadFromFile(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinLoadFromFile(void);
  NodeBuiltinLoadFromFile(const NodeBuiltinLoadFromFile& object);
  NodeBuiltinLoadFromFile& operator=(const NodeBuiltinLoadFromFile& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinLoadFromFile& node);

#endif /* NODEBUILTINLOADFROMFILE_H */

