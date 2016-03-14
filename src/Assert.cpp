/*
 * Assert.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "Expectation.h"

#include "stablecode/Assert.h"

namespace stablecode {

Assert::Assert(Assert::Expression expression) {
	Expectation* exp = new Expectation();
	expression(exp->that());

}

Assert::~Assert() {
	// TODO Auto-generated destructor stub
}

} /* namespace stablecode */
