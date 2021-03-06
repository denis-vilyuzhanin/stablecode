/*
 * Logger.h
 *
 *  Created on: Apr 18, 2016
 *      Author: dvily_000
 */

#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include "stablecode/statement.h"
#include "stablecode/Source.h"

#include"Report.h"

namespace stablecode {

class Log: public statement::LogStatement {
public:
	Log(Report* report);
	Log(Report* report, Source source);
	virtual ~Log();
public:
	void info(LogStatement::Expression logExpression);
private:
	Report* report;
	Source source;
};

} /* namespace stablecode */

#endif /* SRC_LOGGER_H_ */
