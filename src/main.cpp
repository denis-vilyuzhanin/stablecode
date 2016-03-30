

#include <iostream>
#include <list>
#include <algorithm>

#include <atomic>
#include <typeinfo>

#include "Runner.h"
#include "Discovery.h"



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
	 /*for(Registerable* object : Register::getInstance()->getAllRegisteredObjects()) {
		 cout<<typeid(*object).name()<<endl;
		 Test* test = dynamic_cast<Test*>(object);
		 if (test != nullptr) {
			 test->run();
		 }
	 }*/
	 Discovery discovery;
	 discovery.discover();

	 for(auto& rootSuiteEntry: discovery.getDiscoveredSuites()) {
		 cout<<rootSuiteEntry.second->getName()<<endl;
		 print(rootSuiteEntry.second, " ");
	 }

	 Runner runnner;

	 //runnner.runAll();

	 return 0;
 }
