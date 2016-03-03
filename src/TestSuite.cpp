/*
 * TestSuite.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include <stablecode/TestSuite.h>
#include "Register.h"
#include <vector>
namespace stablecode {

static std::vector<TestSuite*> suites;

TestSuite::TestSuite():Registerable(Registerable::SUITE) {
}

TestSuite::~TestSuite() {
	// TODO Auto-generated constructor stub

}


} /* namespace stablecode */
