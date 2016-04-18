/*
 * Report.h
 *
 *  Created on: Apr 16, 2016
 *      Author: dvily_000
 */

#ifndef SRC_REPORT_H_
#define SRC_REPORT_H_

#include <string>

#include "Test.h"
#include "TestSuite.h"
#include "stablecode/statement.h"

namespace stablecode {

class Report {
public:
	enum MessageType {
		INFO,
		TEST_BEGIN,
		TEST_PASSED
	};
public:
	Report();
	virtual ~Report();
public:
	virtual void beginTest(const Test* test);
	virtual void testPassed(const Test* test);
	virtual void message(const MessageType type, const std::string& text);
	virtual void message(const MessageType type, const std::string& text, Source source);
private:
	void printSuite(const TestSuite* suite);
	void printTest(const Test* test);
private:
	const TestSuite* currentSuite = nullptr;
};

} /* namespace stablecode */

#endif /* SRC_REPORT_H_ */
