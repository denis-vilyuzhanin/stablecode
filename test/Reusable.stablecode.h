#include "stablecode.h"

VERIFY {
	INFO("First Verify Test "<<testNumber);
}

BEFORE {
	INFO("First Before Test "<<testNumber);
}

AFTER {
	INFO("First After Test "<<testNumber);
}

TEST(firstTest) {
	INFO("First 1 Test Run "<<testNumber);
}

TEST(firstTest) {
	INFO("First 2 Test Run "<<testNumber);
}

AFTER {
	INFO("Second After Test "<<testNumber);
}

BEFORE {
	INFO("Second Before Test "<<testNumber);
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

VERIFY {
	INFO("Second Verify Test "<<testNumber);
}

SUITE(mySuite) {

	VERIFY {
		INFO("First Verify Test in mySuite "<<testNumber);
	}

	AFTER {
		INFO("First After Test in mySuite "<<testNumber);
	}

	BEFORE {
		INFO("First Before Test in mySuite "<<testNumber);
	}

	TEST(firstTest) {

	}

	VERIFY {
		INFO("Second Verify Test in mySuite "<<testNumber);
	}

	BEFORE {
		INFO("Second Before Test in mySuite "<<testNumber);
	}

	TEST(secondTest) {

	}

	SUITE(subSuite) {

		AFTER {
			INFO("First After Test in subSuite "<<testNumber);
		}

		BEFORE {
			INFO("First Before Test in subSuite "<<testNumber);
		}
		TEST(firstTest) {
			INFO("First Test in SubSuite "<<testNumber);
		}

		VERIFY {
			INFO("First Verify Test in subSuite "<<testNumber);
		}


	}
}

SUITE(mySuite) {
	TEST(firstTest) {
		INFO("The last test "<<testNumber);
	}
}
