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

#include <string>

namespace stablecode {

class Test: public Registerable {
public:
	class Expectation {
	public:
		Expectation(): lineNumber(-1){}
		explicit Expectation(int lineNumber): lineNumber(lineNumber){}
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
	Expectation expect();
	Expectation expect(int lineNumber);
	void ok();
	void fail();
	void fail(std::string reason);
	void fail(std::string reason, int lineNumber);

	bool isEqual(Value& first, Value& second);
	bool isGreater(Value& first, Value& second);
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TEST_H_ */
