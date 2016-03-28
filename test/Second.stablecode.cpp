


#include <iostream>
#include <functional>
using namespace std;

#include "stablecode.h"

VERIFY {
	cout<<"First Verify Test 2"<<endl;
}

BEFORE {
	cout<<"First Before Test 2"<<endl;
}

AFTER {
	cout<<"First After Test 2"<<endl;
}

TEST(firstTest) {
	cout<<"Test Run 1"<<endl;
}

TEST(firstTest) {
	cout<<endl;
}

AFTER {
	cout<<"Second After Test 2"<<endl;
}

BEFORE {
	cout<<"Second Before Test 2"<<endl;
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
	cout<<endl;

}

VERIFY {
	cout<<"Second Verify Test 2"<<endl;
}

SUITE(mySuite) {

	VERIFY {
		cout<<"First Verify Test in mySuite 1"<<endl;
	}

	AFTER {
		cout<<"First After Test in mySuite 1"<<endl;
	}

	BEFORE {
		cout<<"First Before Test in mySuite 1"<<endl;
	}

	TEST(firstTest) {
		cout<<endl;
	}

	VERIFY {
		cout<<"Second Verify Test in mySuite 1"<<endl;
	}

	BEFORE {
		cout<<"Second Before Test in mySuite 1"<<endl;
	}

	TEST(secondTest) {
		cout<<endl;
	}

	SUITE(subSuite) {

		AFTER {
			cout<<"First After Test in subSuite 1"<<endl;
		}

		BEFORE {
			cout<<"First Before Test in subSuite 1"<<endl;
		}
		TEST(firstTest) {
			cout<<endl;
		}

		VERIFY {
			cout<<"First Verify Test in subSuite 1"<<endl;
		}


	}
}

SUITE(mySuite) {
	TEST(firstTest) {
		cout<<endl;
	}
}
