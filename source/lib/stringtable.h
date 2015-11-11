#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <vector>
#include "general.h"
#include "base.h"


class StringTable : public Base
{
public:
	StringTable(uint expectedsize = 100);
	virtual ~StringTable();

	virtual void dump(ostream& os,  uint indent) const;

	identifier getID(const string& str);
	string& getString(identifier id);

	uint getNumStrings(void) const;

	void clear(void);

private:
	vector<string> m_data;
};

ostream& operator<<(ostream& os, const StringTable& node);

#endif // STRINGTABLE_H
