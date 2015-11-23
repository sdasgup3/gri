#ifndef NODEBUILTINGENERATEVERTEX_H
#define NODEBUILTINGENERATEVERTEX_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGenerateVertex : public NodeFunction
{
public:
	NodeBuiltinGenerateVertex(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGenerateVertex(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGenerateVertex(void);
	NodeBuiltinGenerateVertex(const NodeBuiltinGenerateVertex& object);
	NodeBuiltinGenerateVertex& operator=(const NodeBuiltinGenerateVertex& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGenerateVertex& node);

#endif /* NODEBUILTINGENERATEVERTEX_H */

