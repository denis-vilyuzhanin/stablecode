/*
 * TestRunning.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: dvily_000
 */

#include "TestRunning.h"

namespace stablecode {

TestRunning::TestRunning() {
	// TODO Auto-generated constructor stub

}

TestRunning::~TestRunning() {
	// TODO Auto-generated destructor stub
}

void TestRunning::addRunnableAfter(Runnable* runnable) {
	runnableAfter.push_back(runnable);
}

void TestRunning::addRunnableBefore(Runnable* runnable) {
	runnableBefore.push_back(runnable);
}


} /* namespace stablecode */

