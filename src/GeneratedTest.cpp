/*
 * GeneratedTest.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: Denys_Viliuzhanin
 */

#include <typeinfo>

#include "stablecode/GeneratedTest.h"

namespace stablecode {

GeneratedTest::GeneratedTest(const string& declaredTestName, Module* module):
		Registerable(module), declaredTestName(declaredTestName) {

}

GeneratedTest::~GeneratedTest() {

}

} /* namespace stablecode */
