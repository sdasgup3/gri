#ifndef NODEBUILTINGETENDVERTEX_H
#define NODEBUILTINGETENDVERTEX_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetEndVertex : public NodeFunction
{
public:
	NodeBuiltinGetEndVertex(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetEndVertex(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetEndVertex(void);
	NodeBuiltinGetEndVertex(const NodeBuiltinGetEndVertex& object);
	NodeBuiltinGetEndVertex& operator=(const NodeBuiltinGetEndVertex& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetEndVertex& node);

#endif /* NODEBUILTINGETENDVERTEX_H */

