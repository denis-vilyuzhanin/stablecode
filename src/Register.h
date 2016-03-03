/*
 * Register.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_REGISTER_H_
#define SRC_REGISTER_H_

#include "stablecode/TestSuite.h"
#include "stablecode/Test.h"

#include <list>
namespace stablecode {

class TestSuite;
class Test;

class Register {
	friend TestSuite;
	friend Test;
public:
	static Register* getInstance();

	const std::list<TestSuite*>& getAllSuites() const;
	const std::list<Test*>& getAllTests() const;

private:
	Register();
	void registerTestSuite(TestSuite* newTestSuite);
	void registerTest(Test* newTest);
private:
	static Register INSTANCE;

	std::list<TestSuite*> suites;
	std::list<Test*> tests;
};

} /* namespace stablecode */

#endif /* SRC_REGISTER_H_ */
