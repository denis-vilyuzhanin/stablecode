/*
 * Logger.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: dvily_000
 */
#include <iostream>
#include <sstream>

#include "Log.h"

namespace stablecode {
using namespace std;

Log::Log(Report* report): report(report) {
}

Log::Log(Report* report, Source source): report(report), source(source) {
}

Log::~Log() {

}

void Log::info(LogStatement::Expression logExpression) {
	stringstream logStream;
	logExpression(logStream);
	report->message(Report::INFO, logStream.str(), source);
}


} /* namespace stablecode */
