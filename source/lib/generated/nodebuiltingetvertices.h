#ifndef NODEBUILTINGETVERTICES_H
#define NODEBUILTINGETVERTICES_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetVertices : public NodeFunction
{
public:
	NodeBuiltinGetVertices(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetVertices(void);

	virtual CountPtr<Value> execute(void);
       	virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetVertices(void);
	NodeBuiltinGetVertices(const NodeBuiltinGetVertices& object);
	NodeBuiltinGetVertices& operator=(const NodeBuiltinGetVertices& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetVertices& node);

#endif /* NODEBUILTINGETVERTICES_H */

