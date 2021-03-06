/*
 * statements.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_STATEMENT_H_
#define INCLUDE_STABLECODE_STATEMENT_H_

#include <string>
#include <iostream>
#include <functional>

#include "Value.h"
#include "TValue.h"
#include "Source.h"


namespace stablecode {
namespace statement {



struct ExpectationStatement;
struct ValueStatement;
struct BooleanValueStatement;
struct StringValueStatement;
struct LogStatement;


struct ExpectingStatement {
	virtual ExpectationStatement& operator()(std::string reason) = 0;
	virtual ExpectationStatement& operator()(std::string reason, Source source) = 0;
};

struct LoggingStatement {
	virtual LogStatement& operator()() = 0;
	virtual LogStatement& operator()(Source source) = 0;
};

struct ExpectationStatement {

	BooleanValueStatement& value(const bool first) {
		return booleanValueStatement(new TValue<bool>(first));
	}

	template<class T>
	ValueStatement& value(const T first) {
		TValue<T> firstValue(first);
		return valueStatement(firstValue);
	}

	virtual void fail(std::string reason) = 0;

	//string
	// StringStatment string(std::string str)

	//array
	//tamplate<class T>
	// ArrayStatment string(T[] str, int count)

protected:
	virtual ValueStatement& valueStatement(const Value&) = 0;
	virtual BooleanValueStatement& booleanValueStatement(const Value*) = 0;
};

struct BooleanValueStatement {
	virtual void isTrue() = 0;
 	virtual void isFalse() = 0;
};

struct ValueStatement {


 	template<class T>
 	void equal(const T& second) {
 		TValue<const T> secondValue(second);
 		equalValue(secondValue);
 	}

 	// To support EXPECT().that(var1).equal(20).or().equal(30)
 	// To support EXPECT().that(var1).greater(var2).and().equal(var3)
 	// 	template<class T>
 	//  LogicalStatement equal(const T& constValue) {

 	template<class T>
 	void greater(const T& second) {
 		TValue<const T> secondValue(second);
 		greaterValue(secondValue);
 	}

 	// EXPECT().value(a).is(int);

protected:
	virtual void isValue(const Value&) = 0;
	virtual void equalValue(const Value&) = 0;
	virtual void greaterValue(const Value&) = 0;

};


struct LogStatement {
	typedef std::function<void(std::ostream&)> Expression;
	virtual void info(Expression logExpression) = 0;
};

} /* namespace statement */
} /* namespace stablecode */




#endif /* INCLUDE_STABLECODE_STATEMENT_H_ */
