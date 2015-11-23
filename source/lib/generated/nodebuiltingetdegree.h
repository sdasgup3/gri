#ifndef NODEBUILTINGETDEGREE_H
#define NODEBUILTINGETDEGREE_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGetDegree : public NodeFunction
{
public:
	NodeBuiltinGetDegree(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGetDegree(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinGetDegree(void);
	NodeBuiltinGetDegree(const NodeBuiltinGetDegree& object);
	NodeBuiltinGetDegree& operator=(const NodeBuiltinGetDegree& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGetDegree& node);

#endif /* NODEBUILTINGETDEGREE_H */

