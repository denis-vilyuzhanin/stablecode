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
	releastLastLog();
	releaseLastExpectation();
}

void Controller::handleTestResult() {
	checkAndReleaseLastExpectation();
	if (hasUndefinedExpectations){
		runner->getReport()->testFailed(running->getTest(), "Test has uncompleted expectations");
	} else if (hasFailedExpectations) {
		runner->getReport()->testFailed(running->getTest(), "Test has failed expectations");
	} else {
		runner->getReport()->testPassed(running->getTest());
	}
}

void Controller::handleExpectation(Expectation* expectation) {
	runner->getReport()->reportExpectation(*expectation);
	hasFailedExpectations = hasFailedExpectations || expectation->isFailed();
	releaseLastExpectation();
}

LogStatement& Controller::newLog() {
	releastLastLog();
	lastLog = new Log(runner->getReport());
	return *lastLog;
}

LogStatement& Controller::newLog(Source source) {
	releastLastLog();
	lastLog = new Log(runner->getReport(), source);
	return *lastLog;
}

statement::ExpectationStatement& Controller::newExpectation(std::string reason) {
	checkAndReleaseLastExpectation();
	lastExpectation = new Expectation(this, reason);
	return *lastExpectation;
}


statement::ExpectationStatement& Controller::newExpectation(std::string reason, Source source) {
	checkAndReleaseLastExpectation();
	lastExpectation = new Expectation(this, reason, source);
	return *lastExpectation;
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

void Controller::checkAndReleaseLastExpectation() {
	if (lastExpectation != nullptr) {
		if (!lastExpectation->isDefined()) {
			hasUndefinedExpectations = true;
			runner->getReport()->reportExpectation(*lastExpectation);
		}
		releaseLastExpectation();
	}
}

void Controller::releaseLastExpectation() {
	if (lastExpectation != nullptr) {
		delete lastExpectation;
		lastExpectation = nullptr;
	}
}

void Controller::releastLastLog() {
	if (lastLog != nullptr) {
		delete lastLog;
		lastLog = nullptr;
	}

}

} /* namespace stablecode */

