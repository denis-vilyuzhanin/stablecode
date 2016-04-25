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

}

LogStatement& Controller::newLog() {
	LogStatement* log = new Log(runner->getReport());
	return *log;
}

LogStatement& Controller::newLog(Source source) {
	LogStatement* log = new Log(runner->getReport(), source);
	return *log;
}

statement::ExpectationStatement& Controller::newExpectation(std::string reason) {
	ExpectationStatement* expectation = new Expectation(reason);
	return *expectation;
}

statement::ExpectationStatement& Controller::newExpectation(std::string reason, Source source) {
	ExpectationStatement* expectation = new Expectation(reason, source);
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

