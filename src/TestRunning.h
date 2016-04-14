/*
 * TestRunning.h
 *
 *  Created on: Mar 30, 2016
 *      Author: dvily_000
 */

#ifndef SRC_TESTRUNNING_H_
#define SRC_TESTRUNNING_H_

#include <list>

#include "Runnable.h"
#include "Test.h"

namespace stablecode {

class TestRunning {
public:
	TestRunning();
	virtual ~TestRunning();
public:
	void addRunnableAfter(Runnable*);
	void addRunnableBefore(Runnable*);

	const std::list<Runnable*>& getRunnableBefore() const {return runnableBefore;}
	const std::list<Runnable*>& getRunnableAfter() const {return runnableAfter;}

	Test* getTest() const {return test;}
	void setTest(Test* test) { this->test = test;}

private:
	std::list<Runnable*> runnableBefore;
	std::list<Runnable*> runnableAfter;
	Test* test = nullptr;
};

} /* namespace stablecode */

#endif /* SRC_TESTRUNNING_H_ */
