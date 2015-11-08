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

	virtual void dump(ostream& os) const = 0;

#ifdef CHECK_MEMORY_LEAKS
private:
	static set<BaseObject*> m_allocated_objects;

public:
	static uint getNumberOfLeaks(void) { return m_allocated_objects.size(); }
	static void printMemoryLeaks(uint number_of_static_objects);
#endif // CHECK_MEMORY_LEAKS
};

#endif /* BASE_H */
