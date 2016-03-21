

#include <iostream>
#include <list>
#include <algorithm>

#include <atomic>
#include <typeinfo>

#include "Runner.h"
#include "Discovery.h"



 using namespace std;
 using namespace stablecode;

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

	 Runner runnner;

	 //runnner.runAll();

	 return 0;
 }
