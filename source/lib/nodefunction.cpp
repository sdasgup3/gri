#include "nodefunction.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeFunction::NodeFunction(identifier name, list<identifier>* parameters)
	: Node(),
	m_parameters((parameters != NULL) ? parameters : new list<identifier>),
	m_name(name)
{

}

NodeFunction::~NodeFunction(void)
{
	delete m_parameters;
	m_parameters = NULL;
}


/////////////////////////////////////////////////////////////////////////////
////

ostream& operator<<(ostream& os, const list<identifier>& node)
{
	uint num = node.size();
	if(num == 0)
		return os;

	list<identifier>::const_iterator it = node.begin();

	for(uint i = 0; i < num-1; i++, it++)
		os << ID2STR(*it) << ", ";

	if(num > 0)
		os << ID2STR(*it);

	return os;
}
