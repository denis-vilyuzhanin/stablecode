/*
 * Report.h
 *
 *  Created on: Apr 16, 2016
 *      Author: dvily_000
 */

#ifndef SRC_REPORT_H_
#define SRC_REPORT_H_

#include <string>

#include "stablecode/statement.h"

#include "Test.h"
#include "TestSuite.h"


namespace stablecode {
class Expectation;

class Report {
public:
	enum MessageType {
		INFO,
		TEST_BEGIN,
		TEST_PASSED,
		TEST_FAILED,
		UNDEFINED,
		EXPECTATION_FAILED,
		EXPECTATION_PASSED,
	};
public:
	Report();
	virtual ~Report();
public:
	virtual void info(const std::string& text, Source source);
	virtual void beginTest(const Test* test);
	virtual void testPassed(const Test* test);
	virtual void testFailed(const Test* test);
	virtual void reportExpectation(const Expectation& expectation);

protected:
	virtual void message(const MessageType type, const std::string& text);
	virtual void message(const MessageType type, const std::string& text, Source source);
private:
	void printSuite(const TestSuite* suite);
	void printTest(const Test* test);
	void printType(const MessageType type);
	void printSource(Source source);
private:
	const TestSuite* currentSuite = nullptr;
};

} /* namespace stablecode */

#endif /* SRC_REPORT_H_ */
