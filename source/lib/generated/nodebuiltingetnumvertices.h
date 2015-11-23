#ifndef NODEBUILTINGETNUMVERTICES_H
#define NODEBUILTINGETNUMVERTICES_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetNumVertices : public NodeFunction
{
public:
	NodeBuiltinGetNumVertices(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetNumVertices(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;
      

private:
	NodeBuiltinGetNumVertices(void);
	NodeBuiltinGetNumVertices(const NodeBuiltinGetNumVertices& object);
	NodeBuiltinGetNumVertices& operator=(const NodeBuiltinGetNumVertices& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetNumVertices& node);

#endif /* NODEBUILTINGETNUMVERTICES_H */

