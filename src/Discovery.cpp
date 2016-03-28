/*
 * Discovery.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#include <iostream>
#include <list>

#include "stablecode/Module.h"

#include "Discovery.h"
#include "GeneratedTest.h"
#include "GeneratedNameParser.h"
#include "GeneratedRunnable.h"

namespace stablecode {
using namespace std;

list<Discoverable*>* Discovery::toBeDiscoveredObjects = nullptr;

Discovery::Discovery() {
	// TODO Auto-generated constructor stub

}

Discovery::~Discovery() {
	// TODO Auto-generated destructor stub
}

void Discovery::discover() {
	for(Discoverable* object: *toBeDiscoveredObjects) {
		GeneratedClass* generatedClass = dynamic_cast<GeneratedClass*>(object);
		if (generatedClass != nullptr) {
			discoverGeneratedClass(generatedClass);
		}
	}
}

void Discovery::discoverGeneratedClass(GeneratedClass* generatedClassObject) {
	Module* module = generatedClassObject->getModule();
	TestSuite* suite = findOrCreateRootSuite(module, generatedClassObject->getSource());
	GeneratedNameParser parser(generatedClassObject->getClassName());
	while(parser.parseNextSuite()) {

		suite = suite->findOrCreateSuite(parser.parseId(), parser.parseName());
	}
	const string& type = parser.parseType();
	if (type == "test") {
		//suite->addTest(parser.parseId(), parser.parseName(), dynamic_cast<Test*>(generatedClassObject));
		Test* generatedTest = new GeneratedTest(parser.parseName(), generatedClassObject->getCode());
		suite->addTest(parser.parseId(), parser.parseName(), generatedTest);
	} else if (type == "before") {
		Runnable* generatedRunnableBefore = new GeneratedRunnable(generatedClassObject->getCode());
		suite->addBefore(parser.parseId(), generatedRunnableBefore);
	} else if (type == "after") {
		Runnable* generatedRunnableAfter = new GeneratedRunnable(generatedClassObject->getCode());
		suite->addAfter(parser.parseId(), generatedRunnableAfter);
	} else if (type == "verify") {
		Runnable* generatedRunnableVerify = new GeneratedRunnable(generatedClassObject->getCode());
		suite->addVerify(parser.parseId(), generatedRunnableVerify);
	}
}

TestSuite* Discovery::findOrCreateRootSuite(Module* module, const Source& source) {
	auto foundRootSuite = suites.find(module->getId());
	if (foundRootSuite == suites.end()) {
		string newTestSuiteName;
		newTestSuiteName.append(source.getFile()).append("@").append(to_string(module->getId()));
		TestSuite* newRootSuite = new TestSuite(newTestSuiteName);
		suites[module->getId()] = newRootSuite;
		return newRootSuite;
	}
	return foundRootSuite->second;
}

void Discovery::toBeDiscovered(Discoverable* object) {
	if (toBeDiscoveredObjects == nullptr) {
		toBeDiscoveredObjects = new list<Discoverable*>();
	}
	toBeDiscoveredObjects->push_back(object);
}



} /* namespace tablecode */
