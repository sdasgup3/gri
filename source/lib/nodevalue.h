#ifndef NODEVALUE_HPP
#define NODEVALUE_HPP

#include "general.h"
#include "node.h"


class NodeValue : public Node
{
public:
	NodeValue(Value* value);
	NodeValue(CountPtr<Value> value);
	virtual ~NodeValue();

	virtual CountPtr<Value> execute(void);
	virtual void dump(ostream& os, uint indent) const;

private:
	CountPtr<Value> m_value;
};

ostream& operator<<(ostream& os, const NodeValue& node);

#endif // NODEVALUE_HPP
