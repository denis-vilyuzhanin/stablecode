/*
 * Value.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_VALUE_H_
#define INCLUDE_STABLECODE_VALUE_H_

#include <typeinfo>
#include <functional>

namespace stablecode {

class Value {
public:
	typedef std::function<bool(const Value&, const Value&)> Comparator;
public:
	Value(const std::type_info& valueType);
	virtual ~Value();
public:

	virtual bool isEqual(const Value& other) const = 0;
	virtual bool isGreater(const Value& other) const = 0;
protected:
	bool compare(Comparator comparator, const Value& other) const;

private:
	const std::type_info& valueType;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_VALUE_H_ */
