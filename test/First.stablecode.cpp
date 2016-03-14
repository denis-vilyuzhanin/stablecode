


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
		EXPECT1().fail("because");
	}

	if (isEqual(a3, bb1)) {
		EXPECT1().fail("isEqual");
	}

	if (!isGreater(a3, bb1)) {
		EXPECT1().fail("isGreater");
	}

	int* array1 = new int[100];

	stablecode::TValue<int*> array1_1(array1);
	stablecode::TValue<int*> array1_2(array1);
	if (!isEqual(array1_1, array1_2)) {
		EXPECT1().fail("array1 isEqual");
	}

	if (isGreater(array1_1, array1_2)) {
		EXPECT1().fail("array1 isGreater");
	}
}
TEST(firstTest) {

}

TEST(secondTest) {
	int a = 10;
	bool b = true;
	EXPECT().that().value(a).is(10);
	EXPECT().that().value(a).is(a);
	EXPECT().that().value(10).is(a);
	EXPECT().that().value(10 + 20).is(a);
	EXPECT().that().value(b).isTrue();
	EXPECT().that().value(b).isFalse();
	EXPECT().that().value(a).greater(5);
	EXPECT().that().value(a).equal(b);
	EXPECT().value(a).equal(b);
	ASSERT(that.value(a).equal(b));
	ASSERT(that.value(b).isTrue());

	ASSERT(that.value(b));


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
