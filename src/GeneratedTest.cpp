/*
 * GeneratedTest.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: dvily_000
 */

#include "GeneratedTest.h"

namespace stablecode {
using namespace std;

GeneratedTest::GeneratedTest(const string& name, GeneratedClass::Code code):
		Test(name), code(code) {
}

GeneratedTest::~GeneratedTest() {

}

void GeneratedTest::run(statement::LoggingStatement& log, statement::ExpectingStatement& expect) {
	code(log, expect);
}

} /* namespace stablecode */
