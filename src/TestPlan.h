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
#include "TestRunning.h"

namespace stablecode {

class TestPlan {
public:
	TestPlan();
	virtual ~TestPlan();

public:
	void update(TestSuite* suite);

private:
	std::list<TestRunning> runnings;
};

} /* namespace stablecode */

#endif /* SRC_TESTPLAN_H_ */
