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

#include "Controller.h"

namespace stablecode {
using namespace statement;

class Controller;

class Expectation: public ExpectationStatement,
				   private ValueStatement,
				   private BooleanValueStatement{
public:
	Expectation(Controller* controller, std::string reason);
	Expectation(Controller* controller, std::string reason, Source source);
	virtual ~Expectation();

public:

	void fail(std::string reason);

	ValueStatement& valueStatement(const Value&);
	BooleanValueStatement& booleanValueStatement(const Value*);

	void isTrue();
	void isFalse();
	void isValue(const Value&);
	void equalValue(const Value&);
	void greaterValue(const Value&);

	bool isFailed() const {return failed;}
	const Source& getSource() const {return source;}
	const std::string& getReason() const {return reason;}
	const std::string& getDescription() const {return description;}
private:

	void compareWithExpected(const Value*, std::string);
private:
	Controller* controller;
	std::string reason;
	Source source;
	const Value* actualValue = nullptr;
	const Value* expectedValue = nullptr;
	bool failed = false;
	std::string description;
};

} /* namespace stablecode */

#endif /* SRC_EXPECTATION_H_ */
