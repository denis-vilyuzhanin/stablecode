/*
 * GeneratedRunnable.h
 *
 *  Created on: Mar 28, 2016
 *      Author: dvily_000
 */

#ifndef SRC_GENERATEDRUNNABLE_H_
#define SRC_GENERATEDRUNNABLE_H_

#include "stablecode/GeneratedClass.h"

#include "Runnable.h"

namespace stablecode {

class GeneratedRunnable: public Runnable {
public:
	GeneratedRunnable(GeneratedClass::Code code);
	virtual ~GeneratedRunnable();
public:
	void run(statement::Log& log, statement::Expect& expect);
private:
	GeneratedClass::Code code;
};

} /* namespace stablecode */

#endif /* SRC_GENERATEDRUNNABLE_H_ */
