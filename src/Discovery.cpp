/*
 * Discovery.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#include <iostream>
#include <list>

#include "Discovery.h"

#include "stablecode/Module.h"
#include "GeneratedNameParser.h"


namespace stablecode {
using namespace std;

list<Discoverable*> Discovery::toBeDiscoveredObjects;

Discovery::Discovery() {
	// TODO Auto-generated constructor stub

}

Discovery::~Discovery() {
	// TODO Auto-generated destructor stub
}

void Discovery::discover() {
	for(Discoverable* object: toBeDiscoveredObjects) {
		GeneratedClass* generatedClass = dynamic_cast<GeneratedClass*>(object);
		if (generatedClass != nullptr) {
			discoverGeneratedClass(generatedClass);
		}
		//Module::Id sourceModuleId = object->getModule()->getId();
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
			//cout<<sourceModuleId<<"@"<<endl;
			test->run();
		}
	}
}

void Discovery::discoverGeneratedClass(GeneratedClass* generatedClassObject) {
	Module* module = generatedClassObject->getModule();
	TestSuite* suite = findOrCreateRootSuite(module);
	GeneratedNameParser parser;
	while(parser.parseNextSuite(generatedClassObject->getClassName())) {
		suite = suite->findOrCreateSuite(parser.id(), parser.name());
	}
	const string& type = parser.type();
	if (type == "test") {
		suite->addTest(parser.id(), parser.name(), dynamic_cast<Test*>(generatedClassObject));
	}
}

TestSuite* Discovery::findOrCreateRootSuite(Module* module) {
	auto foundRootSuite = suites.find(module->getId());
	if (foundRootSuite == suites.end()) {
		TestSuite* newRootSuite = new TestSuite(module->getSource().getFile());
		suites[module->getId()] = newRootSuite;
		return newRootSuite;
	}
	return foundRootSuite->second;
}

void Discovery::toBeDiscovered(Discoverable* object) {
	toBeDiscoveredObjects.push_back(object);
}



} /* namespace tablecode */
