/*
 * Register.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_REGISTER_H_
#define SRC_REGISTER_H_

#include "stablecode/TestSuite.h"
#include <list>
namespace stablecode {

class TestSuite;

class Register {
	friend TestSuite;
public:
	const std::list<TestSuite*>& getAllSuites() const;
	static Register* getInstance();
private:
	Register();
	void registerTestSuite(TestSuite* newTestSuite);
private:
	static Register INSTANCE;

	std::list<TestSuite*> suites;
};

} /* namespace stablecode */

#endif /* SRC_REGISTER_H_ */
