/*
 * Test.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TEST_H_
#define INCLUDE_STABLECODE_TEST_H_

#include "Registerable.h"

namespace stablecode {

class Test: public Registerable {
public:
	Test();
	virtual ~Test();
	virtual void run();
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
