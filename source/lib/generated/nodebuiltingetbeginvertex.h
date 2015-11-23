#ifndef NODEBUILTINGETBEGINVERTEX_H
#define NODEBUILTINGETBEGINVERTEX_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetBeginVertex : public NodeFunction
{
public:
	NodeBuiltinGetBeginVertex(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetBeginVertex(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetBeginVertex(void);
	NodeBuiltinGetBeginVertex(const NodeBuiltinGetBeginVertex& object);
	NodeBuiltinGetBeginVertex& operator=(const NodeBuiltinGetBeginVertex& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetBeginVertex& node);

#endif /* NODEBUILTINGETBEGINVERTEX_H */

