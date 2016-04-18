/*
 * Runner.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_RUNNER_H_
#define SRC_RUNNER_H_

#include <list>
#include <functional>

#include "Test.h"
#include "TestPlan.h"
#include "Report.h"

namespace stablecode {

class Runner {
public:
	typedef std::function<void (Runner*)> Action;
public:
	Runner(Report* report, const TestPlan* testPlan);
	virtual ~Runner();
public:
	void run();

	static void executeAction(Runner::Action action);
	Report* getReport() const {return report;}
private:
	Report* report;
	const TestPlan* testPlan;
};

} /* namespace stablecode */

#endif /* SRC_RUNNER_H_ */
