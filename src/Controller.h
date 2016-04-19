/*
m * Controller.h
 *
 *  Created on: Apr 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include "stablecode/statement.h"

#include "Logger.h"
#include "Runner.h"
#include "TestRunning.h"

namespace stablecode {

class Controller {
private:
	class Delegate {
	protected:
		Delegate(Controller* controller);
	protected:
		Controller* controller;
	};

	class LogDelegate: public statement::Log, private Delegate {
	public:
		LogDelegate(Controller* controller);
	public:
		statement::LogStatement& operator()();
		statement::LogStatement& operator()(Source source);
	};
public:
	Controller(Runner* runner, TestRunning* running);
	virtual ~Controller();
public:
	statement::LogStatement& newLog();
	statement::LogStatement& newLog(Source source);
private:
	Runner* runner;
	TestRunning* running;
};

} /* namespace stablecode */

#endif /* SRC_CONTROLLER_H_ */
