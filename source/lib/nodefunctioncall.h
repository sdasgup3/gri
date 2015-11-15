#ifndef NODEFUNCTIONCALL_HPP
#define NODEFUNCTIONCALL_HPP

#include "general.h"
#include "node.h"
#include "codeposition.h"

class NodeBlock;

class NodeFunctionCall : public Node
{
public:
	NodeFunctionCall(identifier name, NodeBlock* parameters, const CodePosition* pos);
	virtual ~NodeFunctionCall();

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	identifier m_name;
	NodeBlock* m_parameters;
	const CodePosition* m_position;// Position of the caller
};

ostream& operator<<(ostream& os, const NodeFunctionCall& node);

#endif // NODEFUNCTIONCALL_HPP
