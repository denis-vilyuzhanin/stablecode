


#include <iostream>
using namespace std;

#include "stablecode.h"

TEST(firstTest) {
	expect().fail("because");
	EXPECT.fail("because");
}
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

SUITE(mySuite) {
	TEST(firstTest) {

	}
}

STARTUP {
	cout<<"Startup"<<endl;
}
