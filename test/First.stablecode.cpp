
#include "stablecode.h"

#include <iostream>
using namespace std;

TEST(firstTest) {

}


TEST(secondTest) {

}

SUITE(mySuite) {

	TEST(firstTest) {

	}

	TEST(secondTest) {

	}

	SUITE(subSuite) {
		TEST(firstTest) {

		}

	}
}


STARTUP {
	cout<<"Startup"<<endl;
}
