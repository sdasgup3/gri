#ifndef VALUEARRAY_HPP
#define VALUEARRAY_HPP

#include <deque>
#include "general.h"
#include "value.h"
#include "valuenull.h"

class ValueReference;

class ValueArray : public Value
{
public:
	ValueArray();
	ValueArray(uint size);
	virtual ~ValueArray();

public:
	deque< CountPtr<Value> > getVal(void) const;
	virtual bool toBool(void) const;
	virtual string toString(void) const { return "#Array"; }

	virtual ValueArray*         toValueArray(void) { return this; }

	virtual void dump(ostream& os, uint indent) const;

	uint getSize(void) const;
	void resize(uint newsize);
	CountPtr<Value> getItem(uint pos) const;
	CountPtr<Value> setItem(uint pos, CountPtr<Value> val);

	void pushFront(CountPtr<Value>& val);
	void pushBack(CountPtr<Value>& val);
	void popFront(void);
	void popBack(void);
	CountPtr<Value> front(void);
	CountPtr<Value> back(void);

	virtual CountPtr<Value> iterator(void) const;
	virtual CountPtr<Value> hasNext(void) const;
	virtual CountPtr<Value> next(void);
	virtual void resetIterator(void);

	void setPropertyToAllStructItems(identifier name, CountPtr<Value> value);

	virtual CountPtr<Value> add(const Value&     right) const; // +
	virtual CountPtr<Value> sub(const Value&     right) const; // -
	virtual CountPtr<Value> mult(const Value&    right) const; // *
	virtual CountPtr<Value> div(const Value&     right) const; // /
	virtual CountPtr<Value> mod(const Value&     right) const; // %
	virtual CountPtr<Value> eq(const Value&      right) const; // ==
	virtual CountPtr<Value> eq(const ValueArray&  left) const;
	virtual CountPtr<Value> ne(const Value&      right) const; // !=
	virtual CountPtr<Value> ne(const ValueArray&  left) const;
	virtual CountPtr<Value> le(const Value&      right) const; // <=
	virtual CountPtr<Value> ge(const Value&      right) const; // >=
	virtual CountPtr<Value> lt(const Value&      right) const; // <
	virtual CountPtr<Value> gt(const Value&      right) const; // >
	virtual CountPtr<Value> member(const Value&  right) const; // .
	virtual CountPtr<Value> index(const Value&   right) const; // []
	virtual CountPtr<Value> logNOT(void)                const; // !

private:
	deque< CountPtr<Value> > m_val;
	deque< CountPtr<Value> >::iterator m_it;
};

ostream& operator<<(ostream& os, const ValueArray& node);

#endif // VALUEARRAY_HPP
