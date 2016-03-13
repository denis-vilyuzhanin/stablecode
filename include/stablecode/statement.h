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

struct ThatStatement;
struct ValueStatement;

struct ExpectationStatement {
	virtual ThatStatement& that() = 0;
	virtual void fail(std::string reason) = 0;

	//Async statement.
	//virtual LaterStatement later() = 0;
};

struct ThatStatement {
	template<class T>
	ValueStatement& value(const T variable) {
		TValue<T> variableValue(variable);
		return valueStatement(variableValue);
	}

	//string
	// StringStatment string(std::string str)

	//array
	//tamplate<class T>
	// ArrayStatment string(T[] str, int count)

	//bool
	// BooleanStatement value(bool)



protected:
	virtual ValueStatement& valueStatement(const Value&) = 0;
};

struct ValueStatement {

	virtual void isTrue() = 0;
 	virtual void isFalse() = 0;

 	template<class T>
 	void equal(const T& constValue) {
 		TValue<const T> value(constValue);
 		equalValue(value);
 	}

 	// To support EXPECT().that(var1).equal(20).or().equal(30)
 	// To support EXPECT().that(var1).greater(var2).and().equal(var3)
 	// 	template<class T>
 	//  LogicalStatement equal(const T& constValue) {

 	template<class T>
 	void greater(const T& constValue) {
 		TValue<const T> value(constValue);
 		greaterValue(value);
 	}

	template<class T>
	void is(const T constValue) {
		TValue<const T> value(constValue);

	}
protected:
	virtual void isValue(const Value&) = 0;
	virtual void equalValue(const Value&) = 0;
	virtual void greaterValue(const Value&) = 0;

};

} /* namespace statement */
} /* namespace stablecode */




#endif /* INCLUDE_STABLECODE_STATEMENT_H_ */
