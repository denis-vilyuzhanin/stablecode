/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */


#include <iostream>


#include "stablecode/Test.h"

#include "Register.h"
#include "Expectation.h"

namespace stablecode {

Test::Test(const std::string& name):name(name) {
}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::run() {
}

ExpectationStatement& Test::expect(std::string reason) {
	Expectation* expectation = new Expectation(reason);
	return *expectation;
}

ExpectationStatement& Test::expect(std::string reason, Source source) {
	Expectation* expectation = new Expectation(reason, source);
	return *expectation;
}


} /* namespace stablecode */

