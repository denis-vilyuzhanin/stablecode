
#include "stablecode.h"
#include "Register.h"
#include <iostream>
 #include <list>
 #include <algorithm>

#include <atomic>
#include <typeinfo>


 using namespace std;
 using namespace stablecode;

 int main()
 {
	 const list<TestSuite*> suites = Register::getInstance()->getAllSuites();
	 for(TestSuite* suite : suites) {
		 cout<<typeid(*suite).name()<<endl;
	 }
	 return 0;
 }
