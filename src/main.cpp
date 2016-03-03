
#include "stablecode.h"
#include "Register.h"
#include <iostream>
 #include <list>
 #include <algorithm>

#include <atomic>
#include <typeinfo>


 using namespace std;
 using namespace stablecode;

 int main() {
	 for(TestSuite* suite : Register::getInstance()->getAllSuites()) {
		 cout<<typeid(*suite).name()<<endl;
	 }
	 for(Test* test : Register::getInstance()->getAllTests()) {
		 cout<<typeid(*test).name()<<endl;
	 }
	 return 0;
 }
