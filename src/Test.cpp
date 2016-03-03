/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/Test.h"

#include "Register.h"

namespace stablecode {

Test::Test() {
	Register::getInstance()->registerTest(this);
}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::run() {
}

} /* namespace stablecode */
