/*
 * Report.h
 *
 *  Created on: Apr 16, 2016
 *      Author: dvily_000
 */

#ifndef SRC_REPORT_H_
#define SRC_REPORT_H_

#include "Test.h"
#include "TestSuite.h"

namespace stablecode {

class Report {
public:
	Report();
	virtual ~Report();
public:
	virtual void beginTest(const Test* test);
	virtual void endTest(const Test* test);
private:
	void printSuite(const TestSuite* suite);
	void printTest(const Test* test);
private:
	const TestSuite* currentSuite = nullptr;
};

} /* namespace stablecode */

#endif /* SRC_REPORT_H_ */
