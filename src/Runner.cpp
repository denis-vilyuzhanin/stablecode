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

static thread_local Runner* currentRunner = nullptr;

Runner::Runner(Report* report, const TestPlan* testPlan): report(report), testPlan(testPlan) {
}

Runner::~Runner() {
}

void Runner::run() {
	currentRunner = this;
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
		report->testPassed(test);
	}
}

void Runner::executeAction(Runner::Action action) {
	action(currentRunner);
}

} /* namespace stablecode */
