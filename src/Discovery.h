/*
 * Discovery.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_DISCOVERY_H_
#define SRC_DISCOVERY_H_

#include <stablecode/Discoverable.h>
#include <list>
#include <map>
#include <string>

#include "stablecode/Module.h"
#include "TestSuite.h"

namespace stablecode {


class Discovery {
public:
	Discovery();
	virtual ~Discovery();
public:
	void discover(const std::list<Discoverable*>&);
private:
	struct SuiteKey {
		std::string suiteName;
		Module::Id moduleId;

		bool operator<(const SuiteKey& other) const {
			if (suiteName == other.suiteName) {
				return moduleId < other.moduleId;
			}
			return suiteName < other.suiteName;
		}
	};
private:
	std::map<SuiteKey, TestSuite*> suites;
};

} /* namespace tablecode */

#endif /* SRC_DISCOVERY_H_ */
