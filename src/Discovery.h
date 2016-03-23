/*
 * Discovery.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_DISCOVERY_H_
#define SRC_DISCOVERY_H_

#include <list>
#include <map>
#include <string>


#include "stablecode/Discoverable.h"
#include "stablecode/GeneratedClass.h"
#include "stablecode/Module.h"
#include "TestSuite.h"

namespace stablecode {


class Discovery {
	friend Discoverable;
public:
	Discovery();
	virtual ~Discovery();
public:
	void discover();
	const std::map<Module::Id, TestSuite*>& getDiscoveredSuites()const {return suites;}
private:
	void discoverGeneratedClass(GeneratedClass*);
private:
	static void toBeDiscovered(Discoverable* object);
	TestSuite* findOrCreateRootSuite(Module* module, const Source& source);
private:
	static std::list<Discoverable*>* toBeDiscoveredObjects;

	std::map<Module::Id, TestSuite*> suites;
};

} /* namespace tablecode */

#endif /* SRC_DISCOVERY_H_ */
