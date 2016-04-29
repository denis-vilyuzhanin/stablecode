/*
 * Expectation.stablecode.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: dvily_000
 */
#include "stablecode.h"

TEST(expectedTrue_butFalse) {
	bool actual = false;
	EXPECT().value(actual).isTrue();
}

TEST(expectedTrue_butFalse_withReason) {
	bool actual = false;
	EXPECT("Flag must be true").value(actual).isTrue();
}

TEST(expectedTrue_butFalse_constant) {
	EXPECT().value(false).isTrue();
}

TEST(expectedTrue_butFalse_withReason_constant) {
	EXPECT("True must be true").value(false).isTrue();
}

TEST(expectedFalse_butTrue_constant) {
	EXPECT().value(true).isFalse();
}

TEST(expectedFalse_butTrue_withReason_constant) {
	EXPECT("False must be false").value(true).isFalse();
}

