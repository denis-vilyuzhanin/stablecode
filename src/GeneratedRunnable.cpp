/*
 * GeneratedRunnable.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: dvily_000
 */

#include "GeneratedRunnable.h"

namespace stablecode {


GeneratedRunnable::GeneratedRunnable(GeneratedClass::Code code): code(code) {
}

GeneratedRunnable::~GeneratedRunnable() {

}

void GeneratedRunnable::run(statement::Log& log, statement::Expect& expect) {
	code(log, expect);
}

} /* namespace stablecode */
