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

static Runner* currentRunner = nullptr;

Runner::Runner(Report* report, const TestPlan* testPlan): report(report), testPlan(testPlan) {
}

Runner::~Runner() {
}

void Runner::run() {
	currentRunner = this;
	for(TestRunning* runningEntry: testPlan->getTestRunnings()) {
		Controller controller(this, runningEntry);
		Test* test = runningEntry->getTest();
		report->beginTest(test);

		for(Runnable* before : runningEntry->getRunnableBefore()) {
			 before->run(controller.toLog(), controller.toExpect());
		}

		test->run(controller.toLog(), controller.toExpect());

		for(Runnable* after : runningEntry->getRunnableAfter()) {
			after->run(controller.toLog(), controller.toExpect());
		}
		report->testPassed(test);
	}
}

void Runner::executeAction(Runner::Action action) {
	action(currentRunner);
}

} /* namespace stablecode */
