#ifndef COUNTPTR_HPP
#define COUNTPTR_HPP

#include <cassert>
#include "general.h"


template<class TYPE> class CountPtr
{
/////////////////////////////////////////////////////////////////////////////
////

public:
	// Don't use this constructor, Qt qRegisterMetaType() in visualization.cpp requires it
	CountPtr(void)
		: m_ptr(NULL),
		m_num(new uint(1)),
		m_delete_automatically(new bool(false))
	{
		assert(false);
	}

	explicit CountPtr(TYPE* simpleptr)
		: m_ptr(simpleptr),
		m_num(new uint(1)),
		m_delete_automatically(new bool(true))
	{
		assert(simpleptr != NULL);
	}

	CountPtr(const CountPtr<TYPE>& cntptr)
	{
		m_ptr = cntptr.m_ptr;
		m_num = cntptr.m_num;
		m_delete_automatically = cntptr.m_delete_automatically;
		++*m_num;
	}

	~CountPtr()
	{
		free();
	}

	CountPtr<TYPE>& operator= (const CountPtr<TYPE>& cntptr)
	{

		if(this != &cntptr)
		{
			free();
			m_ptr = cntptr.m_ptr;
			m_num = cntptr.m_num;
			m_delete_automatically = cntptr.m_delete_automatically;
			++*m_num;
		}

		return *this;
	}

	bool operator== (const CountPtr<TYPE>& cntptr) const
	{
		return m_ptr->eq(*(cntptr.m_ptr))->toBool();
	}


/////////////////////////////////////////////////////////////////////////////
////

	TYPE& operator*() const
	{
		return *m_ptr;
	}

	TYPE* operator->() const
	{
		return m_ptr;
	}

	const TYPE* getPtr(void) const
	{
		return m_ptr;
	}


/////////////////////////////////////////////////////////////////////////////
////

	uint getNumRefs(void) const
	{
		return *m_num;
	}

	// Vertices and Edges in ValueGraph
	void dontDeleteAutomatically(void)
	{
		*m_delete_automatically = false;
	}


/////////////////////////////////////////////////////////////////////////////
////

private:
	void free()
	{
		if(--*m_num == 0)
		{
			delete m_num;
			m_num = NULL;

			if(*m_delete_automatically == true && m_ptr != NULL)
				delete m_ptr;

			m_ptr = NULL;

			delete m_delete_automatically;
			m_delete_automatically = NULL;
		}
	}

private:
	TYPE* m_ptr;
	uint* m_num;
	bool* m_delete_automatically;
};

#endif // COUNTPTR_HPP
