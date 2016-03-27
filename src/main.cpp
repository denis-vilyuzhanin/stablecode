

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
	 for(auto& entry: suite->getTests()) {
		 cout<<intend<<entry.second->getName()<<endl;
		 entry.second->run();

	 }
	 for(auto& entry: suite->getSuites()) {
		 TestSuite* subSuite = suite->findByName(entry.second);
		 cout<<intend<<entry.second<<endl;
		 print(subSuite, intend + "  ");
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
