/*
 * Expectation.stablecode.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: dvily_000
 */
#include "stablecode.h"

TEST(expectedTrue) {
	bool actual = true;
	EXPECT().value(actual).isTrue();
}

TEST(expectedTrue_withReason) {
	bool actual = true;
	EXPECT("Flag must be true").value(actual).isTrue();
}

TEST(expectedTrue_constant) {
	EXPECT().value(true).isTrue();
}

