#include <cassert>
#include <fstream>
#include <stdexcept>
#include "context.h"

Context::Context()
	: Base(),
	m_stringtable()
{

}


Context::~Context()
{
	clear();
}


void Context::clear(void)
{
	m_stringtable.clear();
}


void Context::dump(ostream& os) const
{
	m_stringtable.dump(os);
}

ostream& operator<<(ostream& os, const Context& node)
{
	node.dump(os);
	return os;
}

Context * Context::s_instance =  0;
