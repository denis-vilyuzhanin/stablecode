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
	for(auto path : test->getSuite()->getPath()) {
		cout<<path<<"=>";
	}
	cout<<test->getName()<<endl;
}


} /* namespace stablecode */

