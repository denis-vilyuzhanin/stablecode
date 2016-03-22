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
	}
}

void Discovery::discoverGeneratedClass(GeneratedClass* generatedClassObject) {
	Module* module = generatedClassObject->getModule();
	TestSuite* suite = findOrCreateRootSuite(module);
	GeneratedNameParser parser(generatedClassObject->getClassName());
	while(parser.parseNextSuite()) {
		suite = suite->findOrCreateSuite(parser.parseId(), parser.parseName());
	}
	const string& type = parser.parseType();
	if (type == "test") {
		suite->addTest(parser.parseId(), parser.parseName(), dynamic_cast<Test*>(generatedClassObject));
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
