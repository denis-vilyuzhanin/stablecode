

#include "Register.h"
#include "Runner.h"
#include <iostream>
 #include <list>
 #include <algorithm>

#include <atomic>
#include <typeinfo>


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
	 Runner runnner;
	 runnner.discovery();
	 runnner.runAll();

	 return 0;
 }
