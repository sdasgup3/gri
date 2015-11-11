#ifndef BASE_H
#define BASE_H

#include "general.h"

#ifdef CHECK_MEMORY_LEAKS
#include <set>
#endif // CHECK_MEMORY_LEAKS

class Base
{
public:
	Base(void);
	virtual ~Base(void);

	virtual void dump(ostream& os, uint indent) const = 0;
        static void dumpIndent(ostream& os, uint indent);


#ifdef CHECK_MEMORY_LEAKS
private:
	static set<Base*> m_allocated_objects;

public:
	static uint getNumberOfLeaks(void) { return m_allocated_objects.size(); }
	static void printMemoryLeaks(uint number_of_static_objects);
#endif // CHECK_MEMORY_LEAKS
};

#endif /* BASE_H */
