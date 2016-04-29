/*
 * Expectation.stablecode.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: dvily_000
 */
#include "stablecode.h"

TEST(undefinedExpectation_beforePassed_noValue) {
	EXPECT();
	EXPECT().value(true).isTrue();
}

TEST(undefinedExpectation_beforeFailed_noValue) {
	EXPECT();
	EXPECT().value(true).isFalse();
}

TEST(undefinedExpectation_noValue) {
	EXPECT();
}

TEST(undefinedExpectation_noValue_reason) {
	EXPECT("Some reason");
}

TEST(undefinedExpectation_booleanValue) {
	bool flag = true;
	EXPECT("Some reason").value(flag);
}




