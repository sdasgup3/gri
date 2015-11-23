#ifndef NODEBUILTINGETNUMEDGES_H
#define NODEBUILTINGETNUMEDGES_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetNumEdges : public NodeFunction
{
public:
	NodeBuiltinGetNumEdges(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetNumEdges(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetNumEdges(void);
	NodeBuiltinGetNumEdges(const NodeBuiltinGetNumEdges& object);
	NodeBuiltinGetNumEdges& operator=(const NodeBuiltinGetNumEdges& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetNumEdges& node);

#endif /* NODEBUILTINGETNUMEDGES_H */

