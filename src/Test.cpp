/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */


#include <iostream>


#include "Test.h"

#include "Expectation.h"

namespace stablecode {
using namespace std;

Test::Test(const string& name): name(name) {
}

Test::~Test() {

}

void Test::run() {
}

/*ExpectationStatement& Test::expect(std::string reason) {
	Expectation* expectation = new Expectation(reason);
	return *expectation;
}

ExpectationStatement& Test::expect(std::string reason, Source source) {
	Expectation* expectation = new Expectation(reason, source);
	return *expectation;
}*/


} /* namespace stablecode */

