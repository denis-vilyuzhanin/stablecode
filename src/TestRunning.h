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

namespace stablecode {

class TestRunning {
public:
	TestRunning();
	virtual ~TestRunning();
public:
	void addRunnableAfter(Runnable* runnable) {
		runnableAfter.push_back(runnable);
	}

	const std::list<Runnable*>& getRunnableBefore() const {return runnableBefore;}
	const std::list<Runnable*>& getRunnableAfter() const {return runnableAfter;}
private:
	std::list<Runnable*> runnableBefore;
	std::list<Runnable*> runnableAfter;
};

} /* namespace stablecode */

#endif /* SRC_TESTRUNNING_H_ */
