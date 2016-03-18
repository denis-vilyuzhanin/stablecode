/*
 * GeneratedTest.h
 *
 *  Created on: Mar 18, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_GENERATEDTEST_H_
#define INCLUDE_STABLECODE_GENERATEDTEST_H_

#include <string>

#include "Test.h"
#include "Source.h"

namespace stablecode {

class GeneratedTest: public Test {
public:
	GeneratedTest(const std::string& declaredTestName, Source* module);
	virtual ~GeneratedTest();
public:
	Source* getModule() const {return module;}
	const std::string& getDeclaredTestName() const {return declaredTestName;}
private:
	std::string declaredTestName;
	Source* module;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_GENERATEDTEST_H_ */
