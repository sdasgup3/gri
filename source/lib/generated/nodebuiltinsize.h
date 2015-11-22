#ifndef NODEBUILTINSIZE_H
#define NODEBUILTINSIZE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinSize : public NodeFunction
{
public:
	NodeBuiltinSize(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinSize(void);

	virtual CountPtr<Value> execute(void);

       	virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinSize(void);
	NodeBuiltinSize(const NodeBuiltinSize& object);
	NodeBuiltinSize& operator=(const NodeBuiltinSize& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinSize& node);

#endif /* NODEBUILTINSIZE_H */

