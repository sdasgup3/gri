#include <cassert>
#include "nodebinary.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBinary::NodeBinary(Node* left, Node* right)
	: Node(),
	m_left(left),
	m_right(right)
{
	assert(left != NULL);
	assert(right != NULL);
}


NodeBinary::~NodeBinary()
{
	delete m_left;
	m_left = NULL;

	delete m_right;
	m_right = NULL;
}


/////////////////////////////////////////////////////////////////////////////
////
