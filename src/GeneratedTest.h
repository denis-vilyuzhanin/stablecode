/*
 * GeneratedTest.h
 *
 *  Created on: Mar 27, 2016
 *      Author: dvily_000
 */

#ifndef SRC_GENERATEDTEST_H_
#define SRC_GENERATEDTEST_H_

#include <string>
#include "stablecode/GeneratedClass.h"

#include "Test.h"


namespace stablecode {

class GeneratedTest: public Test {
public:
	GeneratedTest(const std::string& name, GeneratedClass::Code code);
	virtual ~GeneratedTest();
public:
	void run(statement::LoggingStatement& log, statement::ExpectingStatement& expect);
private:
	GeneratedClass::Code code;
};

} /* namespace stablecode */

#endif /* SRC_GENERATEDTEST_H_ */
