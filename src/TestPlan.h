/*
 * TestPlan.h
 *
 *  Created on: Mar 30, 2016
 *      Author: dvily_000
 */

#ifndef SRC_TESTPLAN_H_
#define SRC_TESTPLAN_H_

#include <list>

#include "TestSuite.h"
#include "Test.h"
#include "TestRunning.h"

namespace stablecode {

class TestPlan {
public:
	TestPlan();
	virtual ~TestPlan();

public:
	void update(TestSuite* suite);

	const std::list<TestRunning*>& getTestRunnings() const {return runnings;}

private:
	void createTestRunings(TestSuite* suite);
	void createTestRunning(Test* test);

private:
	std::list<TestRunning*> runnings;

};

} /* namespace stablecode */

#endif /* SRC_TESTPLAN_H_ */
