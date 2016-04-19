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

#include "Runnable.h"

namespace stablecode {
using namespace statement;
class TestSuite;

class Test: public Runnable {
friend TestSuite;
public:
	Test(const std::string& name);
	virtual ~Test();
public:

	const std::string& getName() const {return name;}
	const TestSuite* getSuite() const {return suite;}
protected:
	/*ExpectationStatement& expect(std::string reason);
	ExpectationStatement& expect(std::string reason, Source source);*/
private:
	void setSuite(TestSuite* suite) {this->suite = suite;}
private:
	TestSuite* suite = nullptr;
	std::string name;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
