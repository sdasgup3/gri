#ifndef NODE_HPP
#define NODE_HPP

#include "general.h"
#include "base.h"
#include "countptr.h"
#include "value.h"


class Node : public Base
{
public:
	Node(void);
	virtual ~Node(void);

	virtual CountPtr<Value> execute(void) = 0;

private:
	Node(const Node& object);
	Node& operator=(const Node& object);
};

#endif /* NODE_HPP */
