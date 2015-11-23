#ifndef NODEBUILTINGETEDGES_H
#define NODEBUILTINGETEDGES_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetEdges : public NodeFunction
{
public:
	NodeBuiltinGetEdges(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetEdges(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetEdges(void);
	NodeBuiltinGetEdges(const NodeBuiltinGetEdges& object);
	NodeBuiltinGetEdges& operator=(const NodeBuiltinGetEdges& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetEdges& node);

#endif /* NODEBUILTINGETEDGES_H */

