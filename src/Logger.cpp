/*
 * Logger.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: dvily_000
 */
#include <iostream>
#include <sstream>

#include "Logger.h"

namespace stablecode {
using namespace std;

Logger::Logger(Report* report): report(report) {
}

Logger::Logger(Report* report, Source source): report(report), source(source) {
}

Logger::~Logger() {

}

void Logger::info(LogStatement::Expression logExpression) {
	stringstream logStream;
	logExpression(logStream);
	report->message(Report::INFO, logStream.str(), source);
}


} /* namespace stablecode */
