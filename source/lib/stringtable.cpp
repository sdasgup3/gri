#include <cassert>
#include <algorithm>
#include "stringtable.h"


/////////////////////////////////////////////////////////////////////////////
////

StringTable::StringTable(uint expectedsize)
	: Base(),
	m_data()
{
	m_data.reserve(expectedsize);
}

StringTable::~StringTable()
{

}


identifier StringTable::getID(const string& str)
{
	vector<string>::const_iterator pos = find(m_data.begin(), m_data.end(), str);

	if(pos == m_data.end())
		m_data.push_back(str);

	return pos - m_data.begin();
}

string& StringTable::getString(identifier id)
{
	assert(id < m_data.size());
	return m_data[id];
}


void StringTable::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<StringTable>" << endl;

	vector<string>::const_iterator it;
	for(it = m_data.begin(); it != m_data.end(); it++)
	{
	        dumpIndent(os, indent+1);
		os << "<string id=\"" << (it - m_data.begin()) << "\">" << (*it) << "</string>" << endl;
	}
	dumpIndent(os, indent);
	os << "</StringTable>" << endl;
}

ostream& operator<<(ostream& os, const StringTable& node)
{
	node.dump(os,0);
	return os;
}

uint StringTable::getNumStrings(void) const
{
	return m_data.size();
}

void StringTable::clear(void)
{
	m_data.clear();
}
