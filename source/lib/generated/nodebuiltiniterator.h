#ifndef NODEBUILTINITERATOR_H
#define NODEBUILTINITERATOR_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinIterator : public NodeFunction
{
public:
	NodeBuiltinIterator(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinIterator(void);

	virtual CountPtr<Value> execute(void);
        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;

private:
	NodeBuiltinIterator(void);
	NodeBuiltinIterator(const NodeBuiltinIterator& object);
	NodeBuiltinIterator& operator=(const NodeBuiltinIterator& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinIterator& node);

#endif /* NODEBUILTINITERATOR_H */

