#ifndef NODELOOP_HPP
#define NODELOOP_HPP

#include "general.h"
#include "node.h"


class NodeLoop : public Node
{
public:
	NodeLoop(Node* init, Node* condition, Node* inc, Node* body);
	virtual ~NodeLoop();

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeLoop(const NodeLoop& object);
	NodeLoop& operator=(const NodeLoop& object);

private:
	Node* m_init;
	Node* m_condition;
	Node* m_inc;
	Node* m_body;
};

ostream& operator<<(ostream& os, const NodeLoop& node);

#endif // NODELOOP_HPP
