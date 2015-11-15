#ifndef NODECONDITION_HPP
#define NODECONDITION_HPP

#include "general.h"
#include "node.h"


class NodeCondition : public Node
{
public:
	NodeCondition(Node* condition, Node* if_section, Node* else_section);
	virtual ~NodeCondition(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeCondition(const NodeCondition& object);
	NodeCondition& operator=(const NodeCondition& object);

private:
	Node* m_condition;
	Node* m_if_section;
	Node* m_else_section;
};

#endif // NODECONDITION_HPP
