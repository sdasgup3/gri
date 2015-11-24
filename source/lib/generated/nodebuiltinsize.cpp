#include <cassert>
#include "generated/nodebuiltinsize.h"
#include "valuenull.h"
#include "context.h"
#include "logger.h"
#include "valuearray.h"
#include "valuestruct.h"
#include "valueset.h"
#include "valuestring.h"
#include "valueint.h"


/////////////////////////////////////////////////////////////////////////////
////

NodeBuiltinSize::NodeBuiltinSize(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinSize::~NodeBuiltinSize(void)
{

}

vector< CountPtr<Value> > 
NodeBuiltinSize::getParametersValues(void) const
{
  const list<identifier>& pnames = getParameterNames();
  vector< CountPtr<Value> > pvalues;
  pvalues.reserve(pnames.size());

  list<identifier>::const_iterator it;
  for(it = pnames.begin(); it != pnames.end(); it++) {
    pvalues.push_back(CONTEXT->getLocalVariable(*it));
  }
  return pvalues;
}


CountPtr<Value> NodeBuiltinSize::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 1);

  ValueArray* a = NULL;
  ValueStruct* st = NULL;
  ValueSet* se = NULL;
  ValueString* s = NULL;

  if((a = par[0]->toValueArray()) != NULL) {
    return CountPtr<Value>(new ValueInt(a->getSize()));
  } else if((st = par[0]->toValueStruct()) != NULL) {
    return CountPtr<Value>(new ValueInt(st->getSize()));
  } else if((se = par[0]->toValueSet()) != NULL) {
    return CountPtr<Value>(new ValueInt(se->getSize()));
  } else if((s = par[0]->toValueString()) != NULL) {
    return CountPtr<Value>(new ValueInt(s->getSize()));
  } else {
    assert(0 && "Bad parameters type: size(array|struct|set|string) : int|null");
    return VALUENULL;
  }
}

const CodePosition* 
NodeBuiltinSize::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinSize::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinSize& node)
{
  node.dump(os, 0);
  return os;
}
void 
NodeBuiltinSize::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}

