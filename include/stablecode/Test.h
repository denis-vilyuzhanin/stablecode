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
#include <string>
#include <functional>
namespace stablecode {
using namespace statement;

class Test: public Registerable {
public:


	class Expectation1 {
	public:
		Expectation1(): lineNumber(-1){}
		explicit Expectation1(int lineNumber): lineNumber(lineNumber){}
	public:
		void fail();
		void fail(std::string reason);
	private:
		int lineNumber;
	};
public:
	Test();
	virtual ~Test();
	virtual void run();
protected:
	Expectation1 expect1();
	Expectation1 expect1(int lineNumber);
	ExpectationStatement& expect();

	void ok();
	void fail();
	void fail(std::string reason);
	void fail(std::string reason, int lineNumber);

	bool isEqual(Value& first, Value& second);
	bool isGreater(Value& first, Value& second);
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
