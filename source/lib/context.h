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
  ~Context();
  Context(void);

  //methods on m_functions
  void addFunction(NodeFunction* function);
  NodeFunction* getFunction(identifier name);
  //methods on m_position
  void setPosition(const CodePosition* pos);
  void setPositionEnterToFunction(const CodePosition* pos);
  void setPositionReturnFromFunction(const CodePosition* pos);
  //methods on m_call_stack
  void pushLocal(identifier function_name, const CodePosition* return_address);
  void popLocal(void);
  identifier getExecutedFunctionName(void) const;
  int getStackSize(void) const;
  void printStackTrace() const;
  //methods on variable on m_call_stack.top
  bool isVariableSet(identifier name);
  CountPtr<Value> getLocalVariable(identifier name);
  CountPtr<Value> setLocalVariable(identifier name, CountPtr<Value> val);
  CountPtr<Value> setLocalVariableAllowRef(identifier name, CountPtr<Value> val);
  void deleteLocalVariable(identifier name);
  //Script entry point
  void executeMain(int , char**);
  //Getters
  static Context *getInstance() {
    if (!s_instance)
      s_instance = new Context();
    return s_instance;
  }
  StringTable* getStringTable(void) { return &m_stringtable; }
  const deque<CallStackItem>& getCallStack(void) const { return m_call_stack; }
  const CodePosition* getPosition(void) const { return m_position; }
  const CodePosition* getBuiltinDeclarationPos(void) const { return m_builtin_declaration_pos; }


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
  const CodePosition* m_builtin_declaration_pos;
};

ostream& operator<<(ostream& os, const Context& node);


#endif /* CONTEXT_HPP */
