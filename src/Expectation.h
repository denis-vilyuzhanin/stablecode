/*
 * Expectation.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef SRC_EXPECTATION_H_
#define SRC_EXPECTATION_H_

#include "stablecode/statement.h"

namespace stablecode {
using namespace statement;

class Expectation: public ExpectationStatement,
				   public ThatStatement,
				   private ValueStatement,
				   private BooleanValueStatement{
public:
	Expectation();
	virtual ~Expectation();

	ThatStatement& that();
	LastStatement& fail(std::string reason);

	ValueStatement& valueStatement(const Value&);
	BooleanValueStatement& booleanValueStatement(const Value&);

	LastStatement& isTrue();
	LastStatement& isFalse();
	Void isValue(const Value&);
	Void equalValue(const Value&);
	Void greaterValue(const Value&);

};

} /* namespace stablecode */

#endif /* SRC_EXPECTATION_H_ */
