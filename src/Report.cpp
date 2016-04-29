/*
 * Report.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: dvily_000
 */

#include <iostream>
#include <sstream>
#include <iomanip>

#include "TestSuite.h"
#include "Report.h"

#include "Expectation.h"

namespace stablecode {
using namespace std;

Report::Report() {
	// TODO Auto-generated constructor stub

}

Report::~Report() {
	// TODO Auto-generated destructor stub
}

void Report::testBegin(const Test* test) {
	const TestSuite* suite = test->getSuite();
	if (currentSuite != suite) {
		cout<<endl;
		for(auto path : test->getSuite()->getPath()) {
			cout<<path<<"=>";
		}
		currentSuite = suite;
	}
	message(TEST_BEGIN, test->getName());
}

void Report::testPassed(const Test* test) {
	message(TEST_PASSED, test->getName());
}

void Report::testFailed(const Test* test, std::string reason) {
	printType(TEST_FAILED);
	cout<<" "<<test->getName()<<": "<< reason;
}


void Report::printSuite(const TestSuite* suite) {
}
void Report::message(const MessageType type, const std::string& text) {
	message(type, text, Source());
}

void Report::message(const MessageType type, const std::string& text, Source source) {
	printType(type);
	cout<<" "<<text;
	printSource(source);
}

void Report::reportExpectation(const Expectation& expectation) {
	if (expectation.isDefined()) {
		printType(expectation.isFailed() ? EXPECTATION_FAILED : EXPECTATION_PASSED);
	} else{
		printType(UNDEFINED);
	}

	if (!expectation.getReason().empty()) {
		cout<<" "<<expectation.getReason()<<":";
	}
	if (expectation.isFailed()) {
		cout<<" "<<expectation.getDescription();
	}
	printSource(expectation.getSource());
}

void Report::info(const std::string& text, Source source) {
	message(INFO, text, source);
}

void Report::printTest(const Test* test) {
}

void Report::printType(const MessageType type) {
	cout<<endl;
	switch(type) {
	case MessageType::UNDEFINED:
		cout<<"[ ???? ]";
		break;
	case MessageType::INFO:
		cout<<"[ INFO ]";
		break;
	case TEST_BEGIN:
		cout<<"[ TEST ]";
		break;
	case TEST_PASSED:
		cout<<"[PASSED]";
		break;
	case TEST_FAILED:
		cout<<"[FAILED]";
		break;
	case EXPECTATION_PASSED:
		cout<<"[  OK  ]";
		break;
	case EXPECTATION_FAILED:
		cout<<"[ FAIL ]";
		break;
	default:
		cout<<"[      ]";
	}
}


void Report::printSource(Source source) {
	if (!source.isUndefined()) {
		cout<<" <at "<<source.fileName()<<":"<<source.getLineNumber()<<">";
	}
}

} /* namespace stablecode */

