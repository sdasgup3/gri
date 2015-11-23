#ifndef NODEBUILTINISDIRECTED_H
#define NODEBUILTINISDIRECTED_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinIsDirected : public NodeFunction
{
public:
	NodeBuiltinIsDirected(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinIsDirected(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;

private:
	NodeBuiltinIsDirected(void);
	NodeBuiltinIsDirected(const NodeBuiltinIsDirected& object);
	NodeBuiltinIsDirected& operator=(const NodeBuiltinIsDirected& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinIsDirected& node);

#endif /* NODEBUILTINISDIRECTED_H */

