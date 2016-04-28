/*
 * Expectation.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include<string>

#include "Expectation.h"

namespace stablecode {
using namespace std;

Expectation::Expectation(Controller* controller, std::string reason):
		controller(controller), reason(reason) {
}

Expectation::Expectation(Controller* controller, std::string reason, Source source):
		controller(controller), reason(reason), source(source) {
}

Expectation::~Expectation() {
	// TODO Auto-generated destructor stub
}



void Expectation::compareWithExpected(const Value* expected, string expectationDescription) {
		expectedValue = expected;
		description = expectationDescription;
		failed = !actualValue->isEqual(*expectedValue);
		if (failed) {
			controller->addFailed(this);
		} else {
			controller->addPassed(this);
		}
}

void Expectation::isTrue() {
	compareWithExpected(new TValue<bool>(true), "'true' value is expected but was 'false'");

}

void Expectation::isFalse() {
	compareWithExpected(new TValue<bool>(true), "'false' value is expected but was 'true'");
}


ValueStatement& Expectation::valueStatement(const Value&) {
	return *this;
}

BooleanValueStatement& Expectation::booleanValueStatement(const Value* booleanValue) {
	actualValue = booleanValue;
	return *this;
}


void Expectation::isValue(const Value&) {

}

void Expectation::equalValue(const Value&) {

}

void Expectation::fail(std::string reason) {

}

void Expectation::greaterValue(const Value&) {

}



} /* namespace stablecode */
