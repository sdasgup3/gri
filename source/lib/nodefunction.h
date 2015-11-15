#ifndef NODEFUNCTION_HPP
#define NODEFUNCTION_HPP

#include <list>
#include "general.h"
#include "node.h"

class CodePosition;

class NodeFunction : public Node
{
public:
	NodeFunction(identifier name, list<identifier>* parameters);
	virtual ~NodeFunction(void);

	identifier getName(void) const { return m_name; }
	const list<identifier>& getParameterNames(void) const { return *m_parameters; }
	uint getNumberOfParameters(void) const { return m_parameters->size(); }

	virtual const CodePosition* declarationPos(void) const = 0;
	virtual bool isBuiltIn(void) const = 0;

private:
	list<identifier>* m_parameters;
	identifier m_name;// Actually not needed, for dump() only
};

ostream& operator<<(ostream& os, const list<identifier>& node);

#endif // NODEFUNCTION_HPP
