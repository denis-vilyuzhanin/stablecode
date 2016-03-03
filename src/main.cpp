
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
	 for(Registerable* test : Register::getInstance()->getAllRegisteredObjects()) {
		 cout<<typeid(*test).name()<<endl;
	 }
	 return 0;
 }
