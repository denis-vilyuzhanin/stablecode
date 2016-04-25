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
public:
	class Delegate {
	protected:
		Delegate(Controller* controller);
	protected:
		Controller* controller;
	};

	class LogDelegate: public statement::LoggingStatement, private Delegate {
	public:
		LogDelegate(Controller* controller);
	public:
		statement::LogStatement& operator()();
		statement::LogStatement& operator()(Source source);
	};

	class ExpectDelegate: public statement::ExpectingStatement, private Delegate {
	public:
		ExpectDelegate(Controller* controller);
	public:
		virtual ExpectationStatement& operator()(std::string reason);
		virtual ExpectationStatement& operator()(std::string reason, Source source);
	};
public:
	Controller(Runner* runner, TestRunning* running);
	virtual ~Controller();
public:
	statement::LogStatement& newLog();
	statement::LogStatement& newLog(Source source);
	statement::ExpectationStatement& newExpectation(std::string reason);
	statement::ExpectationStatement& newExpectation(std::string reason, Source source);

	statement::LoggingStatement& toLog() {return log;}
	statement::ExpectingStatement& toExpect() {return expect;}
private:
	Runner* runner;
	TestRunning* running;
	LogDelegate log;
	ExpectDelegate expect;
};

} /* namespace stablecode */

#endif /* SRC_CONTROLLER_H_ */
