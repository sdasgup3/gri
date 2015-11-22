#ifndef NODEBUILTINARRAY_H
#define NODEBUILTINARRAY_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinArray : public NodeFunction
{
public:
	NodeBuiltinArray(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinArray(void);

	virtual CountPtr<Value> execute(void);
       	virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;



private:
	NodeBuiltinArray(void);
	NodeBuiltinArray(const NodeBuiltinArray& object);
	NodeBuiltinArray& operator=(const NodeBuiltinArray& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinArray& node);

#endif /* NODEBUILTINARRAY_H */

