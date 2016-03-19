/*
 * GeneratedTest.h
 *
 *  Created on: Mar 18, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_GENERATEDTEST_H_
#define INCLUDE_STABLECODE_GENERATEDTEST_H_

#include <string>
using namespace std;

#include "Test.h"
#include "Source.h"

namespace stablecode {

class GeneratedTest: public Test {

public:
	GeneratedTest(const string& declaredTestName, Source* module);
	virtual ~GeneratedTest();
public:
	Source* getModule() const {return module;}
	const string& getDeclaredTestName() const {return declaredTestName;}

private:
	string declaredTestName;
	Source* module;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_GENERATEDTEST_H_ */
