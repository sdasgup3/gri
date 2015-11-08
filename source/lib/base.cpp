#include "base.h"

#ifdef CHECK_MEMORY_LEAKS
#include <typeinfo>
#include "logger.h"
#endif // CHECK_MEMORY_LEAKS


/////////////////////////////////////////////////////////////////////////////
////

Base::Base(void)
{
//#ifdef CHECK_MEMORY_LEAKS
//	m_allocated_objects.insert(this);
//#endif 
}

Base::~Base(void)
{
//#ifdef CHECK_MEMORY_LEAKS
//	m_allocated_objects.erase(this);
//#endif 
}


#ifdef CHECK_MEMORY_LEAKS
void Base::printMemoryLeaks(uint number_of_static_objects)
{
  /*
	uint num_of_leaks = m_allocated_objects.size() - number_of_static_objects;
	stringstream ss;
	ss << "Number of memory leaks: " << num_of_leaks;
	INFO(ss.str());

	if(num_of_leaks == 0)
		return;

	// Display all allocated objects, also including static objects
	set<BaseObject*>::const_iterator it;
	for(it = m_allocated_objects.begin(); it != m_allocated_objects.end(); it++)
	{
		ss.str(string());
		ss << *it << ", " << typeid(**it).name();
		ERR(ss.str());
	}
        */
}
#endif // CHECK_MEMORY_LEAKS
