#ifndef NODEBINARYADD_H
#define NODEBINARYADD_H

#include "general.h"
#include "nodebinary.h"

class NodeBinaryAdd : public NodeBinary
{
public:
	NodeBinaryAdd(Node* left, Node* right);
	virtual ~NodeBinaryAdd(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeBinaryAdd(void);
	NodeBinaryAdd(const NodeBinaryAdd& object);
	NodeBinaryAdd& operator=(const NodeBinaryAdd& object);
};

ostream& operator<<(ostream& os, const NodeBinaryAdd& node);

#endif /* NODEBINARYADD_H */

