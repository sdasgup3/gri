#include <cassert>
#include "generated/nodebuiltingetvertexsetwithproperty.h"
#include "valuenull.h"
#include "context.h"
#include "valuegraph.h"
#include "valuestring.h"
#include "valuefloat.h"


NodeBuiltinGetVertexSetWithProperty::NodeBuiltinGetVertexSetWithProperty(identifier name, list<identifier>* parameters)
  : NodeFunction(name, parameters)
{

}

NodeBuiltinGetVertexSetWithProperty::~NodeBuiltinGetVertexSetWithProperty(void)
{

}


vector< CountPtr<Value> > 
NodeBuiltinGetVertexSetWithProperty::getParametersValues(void) const
{
  const list<identifier>& pnames = getParameterNames();
  //std::cout <<  pnames.size() << "\n" ;
  vector< CountPtr<Value> > pvalues;
  pvalues.reserve(pnames.size());

  list<identifier>::const_iterator it;
  for(it = pnames.begin(); it != pnames.end(); it++) {
    pvalues.push_back(CONTEXT->getLocalVariable(*it));
  }
  return pvalues;
}



CountPtr<Value> 
NodeBuiltinGetVertexSetWithProperty::execute(void)
{
  vector< CountPtr<Value> > par = getParametersValues();
  assert(par.size() == 3);

  ValueGraph* g     = par[0]->toValueGraph();
  ValueString* str  = par[1]->toValueString();
  ValueFloat* val   = par[2]->toValueFloat();

  if(NULL == g  || NULL == str || NULL  == val) {
    assert(0 && "Bad parameters type: getVertices(graph) : set|null");
    return VALUENULL;
  }

  return g->getVertexSetWithProperty(str->getVal(), val->getVal());

}

const CodePosition* 
NodeBuiltinGetVertexSetWithProperty::declarationPos(void) const { 
  return CONTEXT->getBuiltinDeclarationPos(); 
}

bool 
NodeBuiltinGetVertexSetWithProperty::isBuiltIn(void) const 
{
  return true;
}


ostream& operator<<(ostream& os, const NodeBuiltinGetVertexSetWithProperty& node)
{
  node.dump(os, 0);
  return os;
}

void 
NodeBuiltinGetVertexSetWithProperty::dump(ostream& os, uint indent) const 
{
  dumpIndent(os, indent);
  os << "<BuiltinFunction name=\"" << ID2STR(getName()) << "\" id=\"" << getName() << "\" />" << endl;
}


