#include "callstackitem.h"
#include "context.h"
#include "valuenull.h"
#include "valuereference.h"


/////////////////////////////////////////////////////////////////////////////
////

CallStackItem::CallStackItem(identifier function_name, const CodePosition* return_address)
	: Base(),
	m_function_name(function_name),
	m_return_address(return_address),
	m_local_variables()
{
	assert(return_address != NULL);
}

CallStackItem::~CallStackItem(void)
{

}


/////////////////////////////////////////////////////////////////////////////
////

void CallStackItem::dump(ostream& os, uint indent) const
{
	
	dumpIndent(os, indent);
	os << "<CallStackItem function=\"" << ID2STR(m_function_name) << "\">" << endl;

	m_return_address->dump(os, indent+1);

	map<identifier, CountPtr<Value> >::const_iterator it;
	for(it = m_local_variables.begin(); it != m_local_variables.end(); ++it) {
                os <<  ID2STR(it->first) << "\n";
		it->second->dump(os, indent+1);
        }

	dumpIndent(os, indent);
	os << "</CallStackItem>" << endl;
}


/////////////////////////////////////////////////////////////////////////////
////

bool CallStackItem::isVariableSet(identifier name)
{
	
	return m_local_variables.count(name);
}

CountPtr<Value> CallStackItem::getVariable(identifier name)
{
	
	map<identifier, CountPtr<Value> >::iterator it = m_local_variables.find(name);

	if(it != m_local_variables.end())
		return it->second;
	else
	{
		// WARN << _("Variable has not been initialized: ") << ID2STR(name) << endl;
		// Variable have to be created because of assigning
		return m_local_variables.insert(pair<identifier, CountPtr<Value> >(name,
				CountPtr<Value>(new ValueReference(VALUENULL)))).first->second;
	}
}


CountPtr<Value> CallStackItem::setVariable(identifier name, CountPtr<Value> val)
{
	
	map<identifier, CountPtr<Value> >::iterator it = m_local_variables.find(name);
	if(it != m_local_variables.end())
	{
		assert((*it).second->toValueReference() != NULL);

		if(val->isLValue())
			(*it).second->toValueReference()->assign(val->getReferredValue());
		else
			(*it).second->toValueReference()->assign(val);
	}
	else
	{
		if(val->isLValue())
			m_local_variables.insert(pair<identifier, CountPtr<Value> >(name,
					CountPtr<Value>(new ValueReference(val->getReferredValue()))));
		else
			m_local_variables.insert(pair<identifier, CountPtr<Value> >(name,
					CountPtr<Value>(new ValueReference(val))));
	}

	return val;
}

CountPtr<Value> CallStackItem::setVariableAllowRef(identifier name, CountPtr<Value> val)
{
	
	deleteVariable(name);

	if(val->isLValue())
		m_local_variables.insert(pair<identifier, CountPtr<Value> >(name, val));
	else
		m_local_variables.insert(pair<identifier, CountPtr<Value> >(name,
				CountPtr<Value>(new ValueReference(val))));

	return val;
}

void CallStackItem::deleteVariable(identifier name)
{
	
	m_local_variables.erase(name);
}
