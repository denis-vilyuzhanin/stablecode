/*
 * Controller.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: dvily_000
 */

#include "Controller.h"
#include "Expectation.h"
#include "Log.h"

namespace stablecode {

Controller::Controller(Runner* runner, TestRunning* running):
		runner(runner), running(running), log(this), expect(this) {
}

Controller::~Controller() {
	for(auto log : logs) {
		delete log;
	}

	for(auto expectation : expectations) {
		delete expectation;
	}
}

LogStatement& Controller::newLog() {
	Log* log = new Log(runner->getReport());
	logs.push_back(log);
	return *log;
}

LogStatement& Controller::newLog(Source source) {
	Log* log = new Log(runner->getReport(), source);
	logs.push_back(log);
	return *log;
}

statement::ExpectationStatement& Controller::newExpectation(std::string reason) {
	Expectation* expectation = new Expectation(reason);
	expectations.push_back(expectation);
	return *expectation;
}

statement::ExpectationStatement& Controller::newExpectation(std::string reason, Source source) {
	Expectation* expectation = new Expectation(reason, source);
	expectations.push_back(expectation);
	return *expectation;
}


Controller::Delegate::Delegate(Controller* controller): controller(controller) {
}

Controller::LogDelegate::LogDelegate(Controller* controller): Delegate(controller) {
}

LogStatement& stablecode::Controller::LogDelegate::operator ()() {
	return controller->newLog();
}

LogStatement& stablecode::Controller::LogDelegate::operator ()(Source source) {
	return controller->newLog(source);
}


Controller::ExpectDelegate::ExpectDelegate(Controller* controller): Delegate(controller) {
}

ExpectationStatement& Controller::ExpectDelegate::operator ()(std::string reason) {
	return controller->newExpectation(reason);
}

ExpectationStatement& Controller::ExpectDelegate::operator ()(std::string reason, Source source) {
	return controller->newExpectation(reason, source);
}


} /* namespace stablecode */

