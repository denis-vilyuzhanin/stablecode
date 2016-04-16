

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

 void print(TestSuite* suite, string intend) {
	 for(auto& entry: suite->getBefores()) {
		 cout<<intend<<"Before: ";
		 entry.second->run();
	 }
	 for(auto& entry: suite->getTests()) {
		 cout<<intend<<"Test["<<entry.second->getName()<<"]: ";
		 entry.second->run();

	 }
	 for(auto& entry: suite->getVerifies()) {
	 	 cout<<intend<<"Verify: ";
	 	 entry.second->run();
	 }
	 for(auto& entry: suite->getSuites()) {
		 TestSuite* subSuite = entry.second;
		 cout<<intend<<(subSuite->getName())<<endl;
		 print(subSuite, intend + "  ");
	 }
	 for(auto& entry: suite->getAfters()) {
	 	 cout<<intend<<"After: ";
	 	 entry.second->run();
	 }
 }

 int main() {

	 Discovery discovery;
	 discovery.discover();

	 TestPlan plan;
	 for(auto& rootSuiteEntry: discovery.getDiscoveredSuites()) {
		 /*cout<<rootSuiteEntry.second->getName()<<endl;
		 print(rootSuiteEntry.second, " ");*/
		 plan.update(rootSuiteEntry.second);
	 }

	 for(TestRunning* runningEntry: plan.getTestRunnings()) {
		 Test* test = runningEntry->getTest();
		 for(auto path : test->getSuite()->getPath()) {
			 cout<<path<<"->";
		 }
		 cout<<test->getName()<<endl;

		 for(Runnable* before : runningEntry->getRunnableBefore()) {
			 before->run();
		 }

		 test->run();

		 for(Runnable* after : runningEntry->getRunnableAfter()) {
		 	 after->run();
		 }
	 }


	 Runner runnner;

	 //runnner.runAll();

	 return 0;
 }
