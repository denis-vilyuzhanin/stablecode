/*
 * Expectation.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include "Expectation.h"

namespace stablecode {

Expectation::Expectation(std::string reason):reason(reason) {
}

Expectation::Expectation(std::string reason, Source source): reason(reason), source(source) {
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


void Expectation::isTrue() {

}

void Expectation::isFalse() {

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
