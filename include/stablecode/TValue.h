/*
 * TValue.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_TVALUE_H_
#define INCLUDE_STABLECODE_TVALUE_H_

#include "Value.h"

namespace stablecode {

template<class T>
class TValue: public Value {
public:
	TValue(const T& value):Value(typeid(value)), value(value){};
	TValue(const T&& value):Value(typeid(value)), value(value){};

	const T& get() const {return value;}

	bool isEqual(const Value& other) const {
		return compare([](const Value& first, const Value& second){
			TValue<T>* firstValue = (TValue<T>*)&first;
			TValue<T>* secondValue = (TValue<T>*)&second;
			return firstValue->value == secondValue->value;
		}, other);
	}

	bool isGreater(const Value& other) const {
		return compare([](const Value& first, const Value& second){
			TValue<T>* firstValue = (TValue<T>*)&first;
			TValue<T>* secondValue = (TValue<T>*)&second;
			return firstValue->value > secondValue->value;
		}, other);
	}

private:
	const T value;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TVALUE_H_ */
