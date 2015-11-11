#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <deque>
#include <map>
#include <set>
#include "general.h"
#include "base.h"
#include "stringtable.h"
#include "countptr.h"
#include "callstackitem.h"
#include "value.h"
#include "codeposition.h"

#define CONTEXT Context::getInstance()
#define STR2ID(str) CONTEXT->getStringTable()->getID(str)
#define ID2STR(id) CONTEXT->getStringTable()->getString(id)

class NodeFunction;

class Context : public Base
{
public:

  
  virtual void clear(void);
  void dump(ostream& os, uint indent) const;

  StringTable* getStringTable(void) { return &m_stringtable; }
  ~Context();
	Context(void);

  static Context *getInstance() {
    if (!s_instance)
      s_instance = new Context();
    return s_instance;
  }
  void addFunction(NodeFunction* function);
  NodeFunction* getFunction(identifier name);
  void setPosition(const CodePosition* pos);
  void setPositionEnterToFunction(const CodePosition* pos);
  void setPositionReturnFromFunction(const CodePosition* pos);
  bool isVariableSet(identifier name);
  CountPtr<Value> getLocalVariable(identifier name);
  CountPtr<Value> setLocalVariable(identifier name, CountPtr<Value> val);
  CountPtr<Value> setLocalVariableAllowRef(identifier name, CountPtr<Value> val);
  void deleteLocalVariable(identifier name);


private:
        static Context *s_instance;
	Context(const Context& object);
	Context& operator=(const Context& object);

private:
  map<identifier, NodeFunction*> m_functions;
  map<identifier, CountPtr<Value> > m_global_variables;
  deque<CallStackItem> m_call_stack;
  const CodePosition* m_position;
  StringTable m_stringtable;
};

ostream& operator<<(ostream& os, const Context& node);


#endif /* CONTEXT_HPP */
