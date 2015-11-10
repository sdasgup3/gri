#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <deque>
#include <map>
#include <set>
#include "general.h"
#include "base.h"
#include "stringtable.h"

#define CONTEXT Context::getInstance()
#define STR2ID(str) CONTEXT->getStringTable()->getID(str)
#define ID2STR(id) CONTEXT.getStringTable()->getString(id)

class NodeFunction;

class Context : public Base
{
public:

  
  virtual void clear(void);
  void dump(ostream& os) const;
  StringTable* getStringTable(void) { return &m_stringtable; }
  ~Context();
	Context(void);

  static Context *getInstance() {
    if (!s_instance)
      s_instance = new Context();
    return s_instance;
}

private:
        static Context *s_instance;
	Context(const Context& object);
	Context& operator=(const Context& object);

private:
	StringTable m_stringtable;
};

ostream& operator<<(ostream& os, const Context& node);


#endif /* CONTEXT_HPP */
