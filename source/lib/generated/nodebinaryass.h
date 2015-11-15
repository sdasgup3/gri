#ifndef NODEBINARYASS_H
#define NODEBINARYASS_H

#include "general.h"
#include "nodebinary.h"

class NodeBinaryAss : public NodeBinary
{
public:
	NodeBinaryAss(Node* left, Node* right);
	virtual ~NodeBinaryAss(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeBinaryAss(void);
	NodeBinaryAss(const NodeBinaryAss& object);
	NodeBinaryAss& operator=(const NodeBinaryAss& object);
};

ostream& operator<<(ostream& os, const NodeBinaryAss& node);

#endif /* NODEBINARYASS_H */

