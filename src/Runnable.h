/*
 * Runnable.h
 *
 *  Created on: Mar 28, 2016
 *      Author: dvily_000
 */

#ifndef SRC_RUNNABLE_H_
#define SRC_RUNNABLE_H_

#include "stablecode/statement.h"

namespace stablecode {

class Runnable {
public:
	~Runnable(){};
public:
	virtual void run(statement::LoggingStatement& log, statement::ExpectingStatement& expect) = 0;
};

} /* namespace stablecode */


#endif /* SRC_RUNNABLE_H_ */
