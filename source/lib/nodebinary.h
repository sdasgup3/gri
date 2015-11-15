#ifndef NODEBINARY_HPP
#define NODEBINARY_HPP

#include "general.h"
#include "node.h"

class NodeBinary : public Node
{
public:
	NodeBinary(Node* left, Node* right);
	virtual ~NodeBinary(void);

	Node* getLeft(void) { return m_left; }
	Node* getRight(void) { return m_right; }

private:
	NodeBinary(void);
	NodeBinary(const NodeBinary& object);
	NodeBinary& operator=(const NodeBinary& object);

protected:
	Node* m_left;
	Node* m_right;
};

#endif /* NODEUNARY_HPP */
