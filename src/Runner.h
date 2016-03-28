/*
 * Runner.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_RUNNER_H_
#define SRC_RUNNER_H_

#include "Test.h"

#include <list>

namespace stablecode {

class Runner {
public:
	Runner();
	virtual ~Runner();
	void discovery();
	void runAll();
private:
	std::list<Test*> tests;
};

} /* namespace stablecode */

#endif /* SRC_RUNNER_H_ */
