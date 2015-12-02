#ifndef NODEBUILTINSAVETOFILE_H
#define NODEBUILTINSAVETOFILE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinSaveToFile : public NodeFunction
{
public:
  NodeBuiltinSaveToFile(identifier name, list<identifier>* parameters);
  virtual ~NodeBuiltinSaveToFile(void);

  virtual CountPtr<Value> execute(void);
  virtual void dump(ostream& os, uint indent) const;
  virtual const CodePosition* declarationPos(void) const ;
  vector<CountPtr<Value> > getParametersValues() const;
  virtual bool isBuiltIn(void) const ;


private:
  NodeBuiltinSaveToFile(void);
  NodeBuiltinSaveToFile(const NodeBuiltinSaveToFile& object);
  NodeBuiltinSaveToFile& operator=(const NodeBuiltinSaveToFile& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinSaveToFile& node);

#endif /* NodeBuiltinSaveToFile_H */

