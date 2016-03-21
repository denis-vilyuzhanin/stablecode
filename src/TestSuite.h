/*
 * TestSuite.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TESTSUITE_H_
#define INCLUDE_STABLECODE_TESTSUITE_H_

#include <list>
#include <string>
#include "stablecode/Test.h"

namespace stablecode {

class TestSuite {
public:
	TestSuite(std::string name);
	virtual ~TestSuite();
public:
	void addTest(Test*);
	void addSuite(TestSuite*);

	const std::string& getName() const {return name;}
private:
	std::string name;
	std::list<Test*> tests;
	std::list<TestSuite*> suites;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TESTSUITE_H_ */
