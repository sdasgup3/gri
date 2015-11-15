#ifndef NODEBUILTINPRINTLN_H
#define NODEBUILTINPRINTLN_H

#include "general.h"
#include "nodefunction.h"

class NodeBuiltinPrintln : public NodeFunction
{
public:
	NodeBuiltinPrintln(identifier name, list<identifier>* parameters);
	virtual ~NodeBuiltinPrintln(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;
	virtual const CodePosition* declarationPos(void) const ;
        vector<CountPtr<Value> > getParametersValues() const;
        virtual bool isBuiltIn(void) const ;

private:
	NodeBuiltinPrintln(void);
	NodeBuiltinPrintln(const NodeBuiltinPrintln& object);
	NodeBuiltinPrintln& operator=(const NodeBuiltinPrintln& object);
};

ostream& operator<<(ostream& os, const NodeBuiltinPrintln& node);

#endif /* NODEBUILTINPRINTLN_H */

