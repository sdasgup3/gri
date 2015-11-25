#ifndef VARIABLEFLOAT_HPP
#define VARIABLEFLOAT_HPP

#include <sstream>
#include "general.h"
#include "value.h"

class ValueFloat: public Value
{
public:
	ValueFloat(float val);
	virtual ~ValueFloat();

public:
	float            getVal(void) const { return m_val; }
	virtual bool     toBool(void) const { return m_val; }
	virtual string toString(void) const { ostringstream os; os << m_val; return os.str(); }
	virtual bool  isNumeric(void) const { return true; }
	virtual int       toInt(void) const { return (int)m_val; }
	virtual float   toFloat(void) const { return m_val; }

	virtual ValueFloat*         toValueFloat(void) { return this; }

	virtual void dump(ostream& os, uint) const;

	// +
	virtual CountPtr<Value> add(const Value&      right) const;
	virtual CountPtr<Value> add(const ValueBool&   left) const;
	virtual CountPtr<Value> add(const ValueInt&    left) const;
	virtual CountPtr<Value> add(const ValueFloat&  left) const;

	// -
	virtual CountPtr<Value> sub(const Value&      right) const;
	virtual CountPtr<Value> sub(const ValueBool&   left) const;
	virtual CountPtr<Value> sub(const ValueInt&    left) const;
	virtual CountPtr<Value> sub(const ValueFloat&  left) const;

	// *
	virtual CountPtr<Value> mult(const Value&      right) const;
	virtual CountPtr<Value> mult(const ValueBool&   left) const;
	virtual CountPtr<Value> mult(const ValueInt&    left) const;
	virtual CountPtr<Value> mult(const ValueFloat&  left) const;

	// /
	virtual CountPtr<Value> div(const Value&      right) const;
	virtual CountPtr<Value> div(const ValueBool&   left) const;
	virtual CountPtr<Value> div(const ValueInt&    left) const;
	virtual CountPtr<Value> div(const ValueFloat&  left) const;

	// %
	virtual CountPtr<Value> mod(const Value&      right) const;
	virtual CountPtr<Value> mod(const ValueBool&   left) const;
	virtual CountPtr<Value> mod(const ValueInt&    left) const;
	virtual CountPtr<Value> mod(const ValueFloat&  left) const;

	// ==
	virtual CountPtr<Value> eq(const Value&      right) const;
	virtual CountPtr<Value> eq(const ValueBool&   left) const;
	virtual CountPtr<Value> eq(const ValueInt&    left) const;
	virtual CountPtr<Value> eq(const ValueFloat&  left) const;

	// !=
	virtual CountPtr<Value> ne(const Value&      right) const;
	virtual CountPtr<Value> ne(const ValueBool&   left) const;
	virtual CountPtr<Value> ne(const ValueInt&    left) const;
	virtual CountPtr<Value> ne(const ValueFloat&  left) const;

	// <=
	virtual CountPtr<Value> le(const Value&      right) const;
	virtual CountPtr<Value> le(const ValueBool&   left) const;
	virtual CountPtr<Value> le(const ValueInt&    left) const;
	virtual CountPtr<Value> le(const ValueFloat&  left) const;

	// >=
	virtual CountPtr<Value> ge(const Value&      right) const;
	virtual CountPtr<Value> ge(const ValueBool&   left) const;
	virtual CountPtr<Value> ge(const ValueInt&    left) const;
	virtual CountPtr<Value> ge(const ValueFloat&  left) const;

	// <
	virtual CountPtr<Value> lt(const Value&      right) const;
	virtual CountPtr<Value> lt(const ValueBool&   left) const;
	virtual CountPtr<Value> lt(const ValueInt&    left) const;
	virtual CountPtr<Value> lt(const ValueFloat&  left) const;

	// >
	virtual CountPtr<Value> gt(const Value&      right) const;
	virtual CountPtr<Value> gt(const ValueBool&   left) const;
	virtual CountPtr<Value> gt(const ValueInt&    left) const;
	virtual CountPtr<Value> gt(const ValueFloat&  left) const;

	// !
	virtual CountPtr<Value> logNOT(void) const;

	// - (unary)
	virtual CountPtr<Value> subUn(void) const;

	// .
	virtual CountPtr<Value> member(const Value& right) const;

	// []
	virtual CountPtr<Value> index(const Value&  right) const;
	virtual CountPtr<Value> index(const ValueString& left) const;
	virtual CountPtr<Value> index(const ValueArray& left) const;

private:
	const float m_val;
};

ostream& operator<<(ostream& os, const ValueFloat& node);

#endif /* VARIABLEFLOAT_HPP */
