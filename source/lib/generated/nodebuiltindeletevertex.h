#ifndef NODEBUILTINDELETEVERTEX_H
#define NODEBUILTINDELETEVERTEX_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinDeleteVertex : public NodeFunction
{
public:
	NodeBuiltinDeleteVertex(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinDeleteVertex(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinDeleteVertex(void);
	NodeBuiltinDeleteVertex(const NodeBuiltinDeleteVertex& object);
	NodeBuiltinDeleteVertex& operator=(const NodeBuiltinDeleteVertex& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinDeleteVertex& node);

#endif /* NODEBUILTINDELETEVERTEX_H */

