#include <sstream>
#include "codeposition.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

CodePosition::CodePosition(identifier file, uint line)
	: Base(),
	m_file(file),
	m_line(line)
{

}

CodePosition::~CodePosition()
{

}


/////////////////////////////////////////////////////////////////////////////
////

string CodePosition::toString(void) const
{
	stringstream ss;
	ss << ID2STR(m_file) << ":" << m_line;
	return ss.str();
}

void CodePosition::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<CodePosition file=\"" << ID2STR(m_file) << "\" line=\"" << m_line << "\" />" << endl;
}

