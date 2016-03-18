/*
 * GeneratedTest.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/GeneratedTest.h"

namespace stablecode {

GeneratedTest::GeneratedTest(const std::string& declaredTestName, Source* module):
		Test(), declaredTestName(declaredTestName), module(module) {
}

GeneratedTest::~GeneratedTest() {

}

} /* namespace stablecode */
