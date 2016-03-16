/*
 * Test.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TEST_H_
#define INCLUDE_STABLECODE_TEST_H_

#include "Registerable.h"
#include "Value.h"
#include "statement.h"
#include "Source.h"
#include <string>
#include <functional>
namespace stablecode {
using namespace statement;

class Test: public Registerable {
public:



public:
	Test();
	virtual ~Test();
	virtual void run();
protected:

	ThatStatement& expect(std::string reason);
	ThatStatement& expect(std::string reason, Source source);

};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
