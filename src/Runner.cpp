/*
 * Runner.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#include <iostream>

#include "Runner.h"


namespace stablecode {
using namespace std;

Runner::Runner(Report* report, const TestPlan* testPlan): report(report), testPlan(testPlan) {
}

Runner::~Runner() {
}

void Runner::run() {
	for(TestRunning* runningEntry: testPlan->getTestRunnings()) {
		Test* test = runningEntry->getTest();
		report->beginTest(test);

		for(Runnable* before : runningEntry->getRunnableBefore()) {
			 before->run();
		}

		test->run();

		for(Runnable* after : runningEntry->getRunnableAfter()) {
			after->run();
		}
		report->endTest(test);
	}
}

} /* namespace stablecode */
