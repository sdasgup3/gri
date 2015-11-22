#ifndef NODEBUILTINSTRUCT_H
#define NODEBUILTINSTRUCT_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinStruct : public NodeFunction
{
public:
	NodeBuiltinStruct(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinStruct(void);

	virtual CountPtr<Value> execute(void);

        virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        virtual bool isBuiltIn(void) const ;

private:
	NodeBuiltinStruct(void);
	NodeBuiltinStruct(const NodeBuiltinStruct& object);
	NodeBuiltinStruct& operator=(const NodeBuiltinStruct& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinStruct& node);

#endif /* NODEBUILTINSTRUCT_H */

