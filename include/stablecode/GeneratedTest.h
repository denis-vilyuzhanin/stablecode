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
#include "Module.h"
#include "Registerable.h"

namespace stablecode {

class GeneratedTest: public Test, public Registerable {

public:
	GeneratedTest(const string& declaredTestName, Module* module);
	virtual ~GeneratedTest();
public:
	const string& getDeclaredTestName() const {return declaredTestName;}

private:
	string declaredTestName;

};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_GENERATEDTEST_H_ */
