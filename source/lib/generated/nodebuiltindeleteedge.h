#ifndef NODEBUILTINDELETEEDGE_H
#define NODEBUILTINDELETEEDGE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinDeleteEdge : public NodeFunction
{
public:
	NodeBuiltinDeleteEdge(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinDeleteEdge(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinDeleteEdge(void);
	NodeBuiltinDeleteEdge(const NodeBuiltinDeleteEdge& object);
	NodeBuiltinDeleteEdge& operator=(const NodeBuiltinDeleteEdge& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinDeleteEdge& node);

#endif /* NODEBUILTINDELETEEDGE_H */

