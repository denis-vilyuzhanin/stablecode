/*
 * Expectation.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef SRC_EXPECTATION_H_
#define SRC_EXPECTATION_H_

#include <string>
#include "stablecode/Source.h"
#include "stablecode/statement.h"


namespace stablecode {
using namespace statement;

class Expectation: public ExpectationStatement,
				   private ValueStatement,
				   private BooleanValueStatement{
public:
	Expectation(std::string reason);
	Expectation(std::string reason, Source source);
	virtual ~Expectation();

	void fail(std::string reason);

	ValueStatement& valueStatement(const Value&);
	BooleanValueStatement& booleanValueStatement(const Value&);

	void isTrue();
	void isFalse();
	void isValue(const Value&);
	void equalValue(const Value&);
	void greaterValue(const Value&);

private:
	std::string reason;
	Source source;
};

} /* namespace stablecode */

#endif /* SRC_EXPECTATION_H_ */
