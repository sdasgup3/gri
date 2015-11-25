#ifndef NODEBINARYMEMBER_H
#define NODEBINARYMEMBER_H

#include "general.h"
#include "nodebinary.h"

class NodeBinaryMember : public NodeBinary
{
public:
	NodeBinaryMember(Node* left, Node* right);
	virtual ~NodeBinaryMember(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeBinaryMember(void);
	NodeBinaryMember(const NodeBinaryMember& object);
	NodeBinaryMember& operator=(const NodeBinaryMember& object);
};

ostream& operator<<(ostream& os, const NodeBinaryMember& node);

#endif /* NODEBINARYMEMBER_H */

