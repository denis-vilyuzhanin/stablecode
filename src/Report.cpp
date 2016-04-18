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

namespace stablecode {
using namespace std;

Report::Report() {
	// TODO Auto-generated constructor stub

}

Report::~Report() {
	// TODO Auto-generated destructor stub
}

void Report::beginTest(const Test* test) {
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

void Report::printSuite(const TestSuite* suite) {
}
void Report::message(const MessageType type, const std::string& text) {
	message(type, text, Source());
}

void Report::message(const MessageType type, const std::string& text, Source source) {
	cout<<endl;
	switch(type) {
	case MessageType::INFO:
		cout<<"[ INFO ]";
		break;
	case TEST_BEGIN:
		cout<<"[ TEST ]";
		break;
	case TEST_PASSED:
		cout<<"[  OK  ]";
		break;
	default:
		cout<<"[      ]";
	}
	cout<<" "<<text;
	if (!source.isUndefined()) {
		cout<<" <at "<<source.fileName()<<":"<<source.getLineNumber()<<">";
	}
}

void Report::printTest(const Test* test) {
}

} /* namespace stablecode */

