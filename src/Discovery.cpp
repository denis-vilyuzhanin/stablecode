/*
 * Discovery.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#include <iostream>
#include <list>

#include "Discovery.h"

#include "stablecode/GeneratedTest.h"
#include "stablecode/Module.h"
#include "GeneratedName.h"
#include "GeneratedNameParser.h"


namespace stablecode {
using namespace std;

Discovery::Discovery() {
	// TODO Auto-generated constructor stub

}

Discovery::~Discovery() {
	// TODO Auto-generated destructor stub
}

void Discovery::discover(const list<Registerable*>& objects) {
	for(Registerable* object: objects) {
		const string& className = object->getClassName();
		cout<<className<<endl;
		Module::Id sourceModuleId = object->getModule()->getId();
		GeneratedNameParser parser;
		string name = "";
		/*while(parser.parseNext(className)) {
			if (parser.type() != "suite") {
				break;
			}
			name.append(parser.name());
			SuiteKey key;
			key.moduleId = sourceModuleId;
			key.suiteName = name;
			TestSuite* suite;
			auto suitesIter = suites.find(key);
			if (suitesIter != suites.end()) {
				suite = suitesIter->second;
			} else {
				suite = new TestSuite();
				suites[key] = suite;
			}
		}*/
		/*GeneratedTest* test = dynamic_cast<GeneratedTest*>(object);
		if (object != nullptr) {

			GeneratedName testName();

		}*/

		Test* test = dynamic_cast<Test*>(object);
		if (test != nullptr) {
			cout<<sourceModuleId<<"@"<<endl;
			test->run();
		}
	}
}

} /* namespace tablecode */
