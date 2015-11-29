#ifndef NODEBINARYNGBACCESS_H
#define NODEBINARYNGBACCESS_H

#include "general.h"
#include "nodebinary.h"

class NodeBinaryNgbAccess : public NodeBinary
{
public:
	NodeBinaryNgbAccess(Node* left, Node* right, int t);
	virtual ~NodeBinaryNgbAccess(void);

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	NodeBinaryNgbAccess(void);
	NodeBinaryNgbAccess(const NodeBinaryNgbAccess& object);
	NodeBinaryNgbAccess& operator=(const NodeBinaryNgbAccess& object);
private:
        int type;
};

ostream& operator<<(ostream& os, const NodeBinaryNgbAccess& node);

#endif /* NODEBINARYNGBACCESS_H */

