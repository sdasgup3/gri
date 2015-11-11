/*
 * Copyright 2008 Michal Turek
 *
 * This file is part of Graphal library.
 * http://graphal.sourceforge.net/
 *
 * Graphal library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Graphal library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Graphal library.  If not, see <http://www.gnu.org/licenses/>.
 */


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