/*
 * Report.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: dvily_000
 */

#include <iostream>

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
	cout<<endl<<"[ TEST ]"<<test->getName()<<endl;
}

void Report::endTest(const Test* test) {
	cout<<endl<<"[  OK  ]"<<test->getName();
}

void Report::printSuite(const TestSuite* suite) {
}

void Report::printTest(const Test* test) {
}

} /* namespace stablecode */

