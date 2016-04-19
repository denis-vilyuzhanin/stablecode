/*
 * Controller.cpp
 *
 *  Created on: Apr 19, 2016
 *      Author: dvily_000
 */

#include "Controller.h"
#include "Logger.h"

namespace stablecode {

Controller::Controller(Runner* runner, TestRunning* running): runner(runner),running(running) {
}

Controller::~Controller() {

}

LogStatement& Controller::newLog() {
	LogStatement* log = new Logger(runner->getReport());
	return *log;
}

LogStatement& Controller::newLog(Source source) {
	LogStatement* log = new Logger(runner->getReport(), source);
	return *log;
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


} /* namespace stablecode */
