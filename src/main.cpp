

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
	 TestPlan testPlan = discovery.discoverTestPlan();

	 Report report;

	 Runner runnner(&report, &testPlan);
	 runnner.run();
	 //runnner.runAll();

	 return 0;
 }
