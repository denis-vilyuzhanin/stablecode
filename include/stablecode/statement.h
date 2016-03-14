/*
 * statements.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_STATEMENT_H_
#define INCLUDE_STABLECODE_STATEMENT_H_

#include "Value.h"
#include "TValue.h"

#include <string>

namespace stablecode {
namespace statement {

typedef void* Void;

struct ThatStatement;
struct ValueStatement;
struct BooleanValueStatement;

struct LastStatement {
	virtual ~LastStatement() {}
};

struct ThatStatement {

	BooleanValueStatement& value(const bool variable) {
		TValue<bool> variableValue(variable);
		return booleanValueStatement(variableValue);
	}

	template<class T>
	ValueStatement& value(const T variable) {
		TValue<T> variableValue(variable);
		return valueStatement(variableValue);
	}

	virtual LastStatement& fail(std::string reason) = 0;

	//string
	// StringStatment string(std::string str)

	//array
	//tamplate<class T>
	// ArrayStatment string(T[] str, int count)

	//bool
	// BooleanStatement value(bool)



protected:
	virtual ValueStatement& valueStatement(const Value&) = 0;
	virtual BooleanValueStatement& booleanValueStatement(const Value&) = 0;
};

struct BooleanValueStatement: public LastStatement{
	virtual LastStatement& isTrue() = 0;
 	virtual LastStatement& isFalse() = 0;
};

struct ValueStatement: public LastStatement {


 	template<class T>
 	LastStatement& equal(const T& constValue) {
 		TValue<const T> value(constValue);
 		equalValue(value);
 		return *this;
 	}

 	// To support EXPECT().that(var1).equal(20).or().equal(30)
 	// To support EXPECT().that(var1).greater(var2).and().equal(var3)
 	// 	template<class T>
 	//  LogicalStatement equal(const T& constValue) {

 	template<class T>
 	LastStatement& greater(const T& constValue) {
 		TValue<const T> value(constValue);
 		greaterValue(value);
 		return *this;
 	}

	template<class T>
	LastStatement& is(const T constValue) {
		TValue<const T> value(constValue);
		return *this;
	}
protected:
	virtual Void isValue(const Value&) = 0;
	virtual Void equalValue(const Value&) = 0;
	virtual Void greaterValue(const Value&) = 0;

};

struct ExpectationStatement {
	virtual ThatStatement& that() = 0;

	template<class T>
	ValueStatement& value(const T& variable) {
		return that().value(variable);
	}

	//Async statement.
	//virtual LaterStatement later() = 0;
};


} /* namespace statement */
} /* namespace stablecode */




#endif /* INCLUDE_STABLECODE_STATEMENT_H_ */
