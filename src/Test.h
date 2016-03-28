/*
 * Test.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TEST_H_
#define INCLUDE_STABLECODE_TEST_H_

#include <string>

#include "stablecode/Value.h"
#include "stablecode/Source.h"
#include "stablecode/statement.h"

namespace stablecode {
using namespace statement;

class Test{

public:
	Test(const std::string& name);
	virtual ~Test();
protected:

public:
	virtual void run();

	const std::string& getName() const {return name;}
protected:
	/*ExpectationStatement& expect(std::string reason);
	ExpectationStatement& expect(std::string reason, Source source);*/
private:
	std::string name;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */