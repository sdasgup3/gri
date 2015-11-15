#include <list>
#include "nodefunctioncall.h"
#include "nodefunction.h"
#include "nodeblock.h"
#include "valuenull.h"
#include "context.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeFunctionCall::NodeFunctionCall(identifier name, NodeBlock* parameters, const CodePosition* pos)
	: Node(),
	m_name(name),
	m_parameters((parameters != NULL) ? parameters : new NodeBlock),
	m_position(pos)
{

}

NodeFunctionCall::~NodeFunctionCall()
{
	delete m_parameters;
	m_parameters = NULL;

	if(m_position != NULL)
	{
		delete m_position;
		m_position = NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
////

CountPtr<Value> 
NodeFunctionCall::execute(void)
{
  NodeFunction* function = CONTEXT->getFunction(m_name);
  assert(NULL != function && "Called function not available");

  const list<identifier>& formalparams =  function->getParameterNames();
  assert(formalparams.size() == m_parameters->m_commands.size() &&
      "Numer of formals and actuals parameters not matching");

  CONTEXT->pushLocal(m_name, CONTEXT->getPosition());

  list<identifier>::const_iterator fIB = formalparams.begin(), fIE = formalparams.end();
  std::list<Node*>:: iterator aIB = m_parameters->m_commands.begin(), aIE = m_parameters->m_commands.end(); 

  for(;aIB != aIE; aIB++, fIB++) {
    CountPtr<Value> value = (*aIB)->execute();
    CONTEXT->setLocalVariable((*fIB), value);
  }
  CountPtr<Value> ret = function->execute();

  CONTEXT->popLocal();


  if(false == function->isBuiltIn() && NULL != 
        m_position) {
    CONTEXT->setPositionReturnFromFunction(m_position);
  }


  return ret;
}

void NodeFunctionCall::dump(ostream& os, uint indent) const
{
	dumpIndent(os, indent);
	os << "<FunctionCall name=\"" << ID2STR(m_name)
		<< "\" id=\"" << m_name << "\">" << endl;

	m_parameters->dump(os, indent + 1);

	dumpIndent(os, indent);
	os << "</FunctionCall>" << endl;
}

ostream& operator<<(ostream& os, const NodeFunctionCall& node)
{
	node.dump(os, 0);
	return os;
}
