#ifndef NODEBUILTINSETDIRECTED_H
#define NODEBUILTINSETDIRECTED_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinSetDirected : public NodeFunction
{
public:
	NodeBuiltinSetDirected(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinSetDirected(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;


private:
	NodeBuiltinSetDirected(void);
	NodeBuiltinSetDirected(const NodeBuiltinSetDirected& object);
	NodeBuiltinSetDirected& operator=(const NodeBuiltinSetDirected& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinSetDirected& node);

#endif /* NODEBUILTINSETDIRECTED_H */

