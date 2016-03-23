/*
 * statement.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: dvily_000
 */


#include "stablecode/statement.h"
#include "Expectation.h"

namespace stablecode {
namespace statement {

ExpectationStatement& expect(std::string reason) {
	Expectation* expectation = new Expectation(reason);
	return *expectation;
}

ExpectationStatement& expect(std::string reason, Source source) {
	Expectation* expectation = new Expectation(reason, source);
	return *expectation;
}


} /* namespace statement */
} /* namespace stablecode */
