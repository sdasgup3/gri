#include <cassert>
#include <fstream>
#include <stdexcept>
#include "context.h"
#include "valuenull.h"
#include "nodefunction.h"
#include "nodefunctioncall.h"
#include "valuearray.h"
#include "valuestring.h"
#include "valuereference.h"
#include "nodevalue.h"
#include "nodeblock.h"
//#include "logger.h"
//#include "exitvalue.h"

Context::Context()
	: Base(),
       	m_functions(),
	m_global_variables(),
	m_call_stack(),
	m_position(NULL),
	m_stringtable()
	//m_include_dirs(),
	//m_breakpointsEnabled(true),
	//m_builtin_declaration_pos(new CodePosition(m_stringtable.getID(_("built-in function")), 0))

{

}


Context::~Context()
{
	clear();
}


void Context::setPosition(const CodePosition* pos)
{
	m_position = pos;
}

void Context::setPositionEnterToFunction(const CodePosition* pos)
{
	m_position = pos;
}

void Context::setPositionReturnFromFunction(const CodePosition* pos)
{
	m_position = pos;
}

bool Context::isVariableSet(identifier name)
{
	if(m_call_stack.empty())
		return false;

	return m_call_stack.back().isVariableSet(name);
}

CountPtr<Value> Context::getLocalVariable(identifier name)
{
	assert(!m_call_stack.empty());
	return m_call_stack.back().getVariable(name);
}


CountPtr<Value> Context::setLocalVariable(identifier name, CountPtr<Value> val)
{
	assert(!m_call_stack.empty());
	return m_call_stack.back().setVariable(name, val);
}

CountPtr<Value> Context::setLocalVariableAllowRef(identifier name, CountPtr<Value> val)
{
	assert(!m_call_stack.empty());
	return m_call_stack.back().setVariableAllowRef(name, val);
}

void Context::deleteLocalVariable(identifier name)
{
	assert(!m_call_stack.empty());
	m_call_stack.back().deleteVariable(name);
}



void Context::clear(void)
{

  m_global_variables.clear();
  m_call_stack.clear();

  map<identifier, NodeFunction*>::iterator it;
  for(it = m_functions.begin(); it != m_functions.end(); it++) {
    delete it->second;
    it->second = NULL;
  }

  m_stringtable.clear();
  m_functions.clear();

  //if(m_builtin_declaration_pos != NULL) {
  //  delete m_builtin_declaration_pos;
  //  m_builtin_declaration_pos = new CodePosition(m_stringtable.getID(_("built-in function")), 0);
  //}

}

NodeFunction* Context::getFunction(identifier name)
{
	
	map<identifier, NodeFunction*>::iterator it = m_functions.find(name);

	if(it != m_functions.end())
		return it->second;
	else
		return NULL;
}


void Context::addFunction(NodeFunction* function)
{
  assert(function != NULL);

  pair< map<identifier, NodeFunction*>::iterator, bool> ret
	= m_functions.insert(pair<identifier, NodeFunction*>(function->getName(), function));

  if(!ret.second) {
    /*
	WARN_PP(function->declarationPos()->toString(),
		_("Function ") + ID2STR(function->getName())
		+ _("() has been already defined, redefinition ignored"));
	WARN_PP(ret.first->second->declarationPos()->toString(),
		ID2STR(function->getName()) + _("()"));
                */

    delete function;
    function = NULL;
  }
}


void Context::dump(ostream& os, uint indent) const
{
        dumpIndent(os, indent);
	os << "<Context>" << endl;

	map<identifier, NodeFunction*>::const_iterator it;
	for(it = m_functions.begin(); it != m_functions.end(); it++)
		it->second->dump(os, indent+1);

	m_stringtable.dump(os, indent+1);

	dumpIndent(os, indent);
	os << "</Context>" << endl;

}

ostream& operator<<(ostream& os, const Context& node)
{
	node.dump(os,0);
	return os;
}

Context * Context::s_instance =  0;
