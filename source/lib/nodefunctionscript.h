#ifndef NODEFUNCTIONSCRIPT_HPP
#define NODEFUNCTIONSCRIPT_HPP

#include "general.h"
#include "nodefunction.h"
#include "codeposition.h"


class NodeFunctionScript : public NodeFunction
{
public:
	NodeFunctionScript(identifier name, list<identifier>* parameters, Node* block, const CodePosition* pos);
	virtual ~NodeFunctionScript();

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

	virtual const CodePosition* declarationPos(void) const { return m_position; }
	virtual bool isBuiltIn(void) const { return false; }

private:
	Node* m_block;
	const CodePosition* m_position;
};

ostream& operator<<(ostream& os, const NodeFunctionScript& node);

#endif // NODEFUNCTIONSCRIPT_HPP
