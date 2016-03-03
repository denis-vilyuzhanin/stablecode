/*
 * TestSuite.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TESTSUITE_H_
#define INCLUDE_STABLECODE_TESTSUITE_H_

#include "Registerable.h"

namespace stablecode {

class TestSuite: public Registerable {
public:
	TestSuite();
	virtual ~TestSuite();
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TESTSUITE_H_ */
