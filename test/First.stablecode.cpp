


#include <iostream>
using namespace std;

#include "stablecode.h"

TEST(firstTest) {
	//expect().fail("because");


	stablecode::TValue<const int> a1(10);
	stablecode::TValue<const int> a2(10);
	stablecode::TValue<const int> a3(30);
	int b = 10;
	stablecode::TValue<const int> bb1(b);
	stablecode::TValue<const int> bb2(b);
	if (!isEqual(a1, bb1)) {
		EXPECT().fail("because");
	}

	if (isEqual(a3, bb1)) {
		EXPECT().fail("isEqual");
	}

	if (!isGreater(a3, bb1)) {
		EXPECT().fail("isGreater");
	}

	int* array1 = new int[100];

	stablecode::TValue<int*> array1_1(array1);
	stablecode::TValue<int*> array1_2(array1);
	if (!isEqual(array1_1, array1_2)) {
		EXPECT().fail("array1 isEqual");
	}

	if (isGreater(array1_1, array1_2)) {
		EXPECT().fail("array1 isGreater");
	}
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
