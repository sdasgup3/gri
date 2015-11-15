#include <algorithm>
#include "nodeblock.h"
#include "valuenull.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBlock::NodeBlock()
	: Node(),
	m_commands()
{

}

NodeBlock::NodeBlock(Node* node)
	: Node(),
	m_commands()
{
	pushCommandToFront(node);
}

NodeBlock::~NodeBlock()
{
	//for_each(m_commands.begin(), m_commands.end(), DeleteObject());
	m_commands.clear();
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> NodeBlock::execute(void)
{
	list<Node*>::iterator it;

	for(it = m_commands.begin(); it != m_commands.end(); it++)
		(*it)->execute();

	return VALUENULL;
}

void NodeBlock::dump(ostream& os, uint indent) const
{
	list<Node*>::const_iterator it;

	for(it = m_commands.begin(); it != m_commands.end(); it++)
		(*it)->dump(os, indent);
}

ostream& operator<<(ostream& os, const NodeBlock& node)
{
	node.dump(os, 0);
	return os;
}

