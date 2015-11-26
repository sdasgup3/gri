#ifndef NODEBINARYINDEX_H
#define NODEBINARYINDEX_H

#include "general.h"
#include "nodebinary.h"

class NodeBinaryIndex : public NodeBinary
{
public:
	NodeBinaryIndex(Node* left, Node* right);
	virtual ~NodeBinaryIndex(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeBinaryIndex(void);
	NodeBinaryIndex(const NodeBinaryIndex& object);
	NodeBinaryIndex& operator=(const NodeBinaryIndex& object);
};

ostream& operator<<(ostream& os, const NodeBinaryIndex& node);

#endif /* NODEBINARYINDEX_H */

