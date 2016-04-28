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
	EXPECT("Flag").value(actual).isTrue();
}



