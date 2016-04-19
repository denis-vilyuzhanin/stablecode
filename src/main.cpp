

#include <iostream>
#include <list>
#include <algorithm>

#include <atomic>
#include <typeinfo>

#include "Runner.h"
#include "Discovery.h"
#include "TestPlan.h"


 using namespace std;
 using namespace stablecode;


 int main() {

	 Discovery discovery;
	 discovery.discover();

	 TestPlan testPlan;
	 for(auto& rootSuiteEntry: discovery.getDiscoveredSuites()) {
		 testPlan.update(rootSuiteEntry.second);
	 }

	 Report report;

	 Runner runnner(&report, &testPlan);
	 runnner.run();
	 //runnner.runAll();

	 return 0;
 }
