


#include <iostream>
using namespace std;

#include "stablecode.h"

TEST(firstTest) {
	cout<<"Test Run 2"<<endl;
}

TEST(firstTest) {

}

TEST(secondTest) {
	int a = 10;
	bool b = true;
	/*EXPECT().that().value(a).is(10);
	EXPECT().that().value(a).is(a);
	EXPECT().that().value(10).is(a);
	EXPECT().that().value(10 + 20).is(a); */
	EXPECT().value(b).isTrue();
	EXPECT("b is true").value(b).isTrue();
	EXPECT().value(b).isFalse();
	EXPECT().value(a).greater(5);
	EXPECT().value(a).equal(b);
	EXPECT("checking b flag").value(b).isFalse();
	EXPECT().value(a).equal(b);
	expect("test1").value(b).isTrue();


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


