/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/Test.h"

#include "Register.h"

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

Test::Expectation Test::expect() {
	return Test::Expectation();
}

Test::Expectation Test::expect(int lineNumber) {
	return Test::Expectation(lineNumber);
}

void Test::ok() {
}

void Test::fail() {
}

void Test::fail(std::string reason, int lineNumber) {
	std::cout<<"Fail: "<<reason<<"(file.cpp:"<<lineNumber<<")"<<std::endl;
}

void Test::Expectation::fail() {
}

void Test::Expectation::fail(std::string reason) {
	if (lineNumber < 0) {
		std::cout<<"Fail: "<<reason<<std::endl;
	} else {
		std::cout<<"Fail: "<<reason<<"(at file.cpp:"<<lineNumber<<")"<<std::endl;
	}

}

bool Test::isEqual(Value& first, Value& second) {
	return first.isEqual(second);
}

bool Test::isGreater(Value& first, Value& second) {
	return first.isGreater(second);
}

} /* namespace stablecode */

