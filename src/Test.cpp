/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/Test.h"

#include "Register.h"
#include "Expectation.h"
#include <iostream>

namespace stablecode {

Test::Test(): Registerable(Registerable::TEST){
}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::run() {
}

void Test::fail(std::string reason) {
	std::cout<<"Fail: "<<reason<<std::endl;
}

Test::Expectation1 Test::expect1() {
	return Test::Expectation1();
}

Test::Expectation1 Test::expect1(int lineNumber) {
	return Test::Expectation1(lineNumber);
}

void Test::ok() {
}

void Test::fail() {
}

void Test::fail(std::string reason, int lineNumber) {
	std::cout<<"Fail: "<<reason<<"(file.cpp:"<<lineNumber<<")"<<std::endl;
}

void Test::Expectation1::fail() {
}

void Test::Expectation1::fail(std::string reason) {
	if (lineNumber < 0) {
		std::cout<<"Fail: "<<reason<<std::endl;
	} else {
		std::cout<<"Fail: "<<reason<<"(at file.cpp:"<<lineNumber<<")"<<std::endl;
	}

}

bool Test::isEqual(Value& first, Value& second) {
	return first.isEqual(second);
}

ExpectationStatement& Test::expect() {
	Expectation* expectation = new Expectation();
	return *expectation;
}

bool Test::isGreater(Value& first, Value& second) {
	return first.isGreater(second);
}

} /* namespace stablecode */

