/*
 * Test.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TEST_H_
#define INCLUDE_STABLECODE_TEST_H_

#include "Value.h"
#include "statement.h"
#include "Source.h"
#include <string>
#include <functional>
namespace stablecode {
using namespace statement;

class Test{

public:
	Test();
	virtual ~Test();
protected:

public:
	virtual void run();

protected:
	ExpectationStatement& expect(std::string reason);
	ExpectationStatement& expect(std::string reason, Source source);
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
