/*
 * TestPlan.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: dvily_000
 */

#include <list>

#include "TestPlan.h"
#include "Runnable.h"

namespace stablecode {
using namespace std;

TestPlan::TestPlan() {

}

TestPlan::~TestPlan() {

}

void TestPlan::update(TestSuite* suite) {
	list<TestSuite*> stack;
	stack.push_front(suite);
	while(!stack.empty()) {
		TestSuite* current = stack.front();
		stack.pop_front();

		createTestRunings(current);

		for(auto subSuites : current->getSuites()) {
			stack.push_back(subSuites.second);
		}
	}
}

void TestPlan::createTestRunings(TestSuite* suite) {
	for(auto testEntry : suite->getTests()) {
		createTestRunning(testEntry.second);
	}
}

void TestPlan::createTestRunning(Test* test) {
	const TestSuite* current = test->getSuite();
	TestRunning* running = new TestRunning();
	running->setTest(test);
	list<const TestSuite*> stack;
	while(current != nullptr) {
		for(auto afterEntry : current->getAfters()) {
			running->addRunnableAfter(afterEntry.second);
		}
		stack.push_back(current);
		current = current->getParent();
	}
	while(!stack.empty()) {
		current = stack.back();
		stack.pop_back();

		for(auto beforeEntry: current->getBefores()) {
			running->addRunnableBefore(beforeEntry.second);
		}
	}
	runnings.push_back(running);
}

} /* namespace stablecode */
