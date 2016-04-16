/*
 * Runner.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_RUNNER_H_
#define SRC_RUNNER_H_

#include <list>

#include "Test.h"
#include "TestPlan.h"
#include "Report.h"

namespace stablecode {

class Runner {
public:
	Runner(Report* report, const TestPlan* testPlan);
	virtual ~Runner();
public:
	void run();
private:
	Report* report;
	const TestPlan* testPlan;
};

} /* namespace stablecode */

#endif /* SRC_RUNNER_H_ */
