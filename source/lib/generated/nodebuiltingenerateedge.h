#ifndef NODEBUILTINGENERATEEDGE_H
#define NODEBUILTINGENERATEEDGE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGenerateEdge : public NodeFunction
{
public:
	NodeBuiltinGenerateEdge(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGenerateEdge(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGenerateEdge(void);
	NodeBuiltinGenerateEdge(const NodeBuiltinGenerateEdge& object);
	NodeBuiltinGenerateEdge& operator=(const NodeBuiltinGenerateEdge& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGenerateEdge& node);

#endif /* NODEBUILTINGENERATEEDGE_H */

