/*
 * TestSuite.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "TestSuite.h"

#include <vector>
namespace stablecode {

static std::vector<TestSuite*> suites;

TestSuite::TestSuite() {
}

TestSuite::~TestSuite() {
	// TODO Auto-generated constructor stub

}

void TestSuite::addTest(Test* newTest) {
	tests.push_back(newTest);
}

void TestSuite::addSuite(TestSuite* suite) {
	suites.push_back(suite);
}

} /* namespace stablecode */
