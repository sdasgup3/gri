#ifndef NODEBUILTINGRAPH_H
#define NODEBUILTINGRAPH_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinGraph : public NodeFunction
{
public:
	NodeBuiltinGraph(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinGraph(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        //vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;

private:
	NodeBuiltinGraph(void);
	NodeBuiltinGraph(const NodeBuiltinGraph& object);
	NodeBuiltinGraph& operator=(const NodeBuiltinGraph& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinGraph& node);

#endif /* NODEBUILTINGRAPH_H */

