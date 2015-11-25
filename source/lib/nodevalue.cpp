#include "nodevalue.h"
#include "value.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeValue::NodeValue(Value* value)
	: Node(),
	m_value(value)
{
	assert(value != NULL);
}

NodeValue::NodeValue(CountPtr<Value> value)
	: Node(),
	m_value(value)
{

}

NodeValue::~NodeValue()
{

}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeValue::execute(void)
{
	return m_value;
}

void NodeValue::dump(ostream& os, uint indent) const
{
//	dumpIndent(os, indent);
//	os << "<NodeValue>" << endl;
	m_value->dump(os, indent);
//	dumpIndent(os, indent);
//	os << "</NodeValue>" << endl;
}

ostream& operator<<(ostream& os, const NodeValue& node)
{
	node.dump(os, 0);
	return os;
}
