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
				   private ThatStatement,
				   private ValueStatement {
public:
	Expectation();
	virtual ~Expectation();

	ThatStatement& that();
	void fail(std::string reason);

	ValueStatement& valueStatement(const Value&);
	void isTrue();
 	void isFalse();
	void isValue(const Value&);
	void equalValue(const Value&);
	void greaterValue(const Value&);

};

} /* namespace stablecode */

#endif /* SRC_EXPECTATION_H_ */
