/*
 * Expectation.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include "Expectation.h"

namespace stablecode {

Expectation::Expectation() {
	// TODO Auto-generated constructor stub

}

Expectation::~Expectation() {
	// TODO Auto-generated destructor stub
}

ThatStatement& Expectation::that() {
	return *this;
}

ValueStatement& Expectation::valueStatement(const Value&) {
	return *this;
}

BooleanValueStatement& Expectation::booleanValueStatement(const Value&) {
	return *this;
}


LastStatement& Expectation::isTrue() {
	return *(BooleanValueStatement*)this;
}

LastStatement& Expectation::isFalse() {
	return *(BooleanValueStatement*)this;
}

Void Expectation::isValue(const Value&) {
	return nullptr;
}

Void Expectation::equalValue(const Value&) {
	return nullptr;
}

LastStatement& Expectation::fail(std::string reason) {
	return *(BooleanValueStatement*)this;
}


Void Expectation::greaterValue(const Value&) {
	return nullptr;
}

} /* namespace stablecode */
