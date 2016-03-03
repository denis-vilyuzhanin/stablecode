/*
 * Register.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "Register.h"

namespace stablecode {

Register Register::INSTANCE;

Register::Register() {
	// TODO Auto-generated constructor stub

}

Register* Register::getInstance() {
	return &INSTANCE;
}

const std::list<TestSuite*>& Register::getAllSuites() const {
	return suites;
}

void Register::registerTestSuite(TestSuite* newTestSuite) {
	suites.push_back(newTestSuite);
}

void Register::registerTest(Test* newTest) {
	tests.push_back(newTest);
}

const std::list<Test*>& Register::getAllTests() const {
	return tests;
}


} /* namespace stablecode */

