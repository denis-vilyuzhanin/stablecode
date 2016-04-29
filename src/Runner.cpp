/*
 * Runner.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#include <iostream>

#include "stablecode/statement.h"

#include "Runner.h"
#include "Controller.h"

namespace stablecode {
using namespace std;

Runner::Runner(Report* report, const TestPlan* testPlan): report(report), testPlan(testPlan) {
}

Runner::~Runner() {
}

void Runner::run() {
	for(TestRunning* runningEntry: testPlan->getTestRunnings()) {
		Controller controller(this, runningEntry);
		Test* test = runningEntry->getTest();
		report->testBegin(test);

		for(Runnable* before : runningEntry->getRunnableBefore()) {
			 before->run(controller.toLog(), controller.toExpect());
		}

		test->run(controller.toLog(), controller.toExpect());

		for(Runnable* after : runningEntry->getRunnableAfter()) {
			after->run(controller.toLog(), controller.toExpect());
		}
		controller.handleTestResult();
		if (controller.isTestPassed()) {
			passedTestsCount++;
		} else {
			failedTestsCount++;
		}
	}
	report->result(failedTestsCount == 0);
	report->statistic(testPlan->getTestRunnings().size(), passedTestsCount, failedTestsCount);
}


} /* namespace stablecode */
