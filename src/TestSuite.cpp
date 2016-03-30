/*
 * TestSuite.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "TestSuite.h"

#include <vector>
namespace stablecode {
using namespace std;
static std::vector<TestSuite*> suites;

TestSuite::TestSuite(string name):name(name) {
}

TestSuite::~TestSuite() {

}

void TestSuite::addTest(Id id, const std::string& name, Test* test) {
	testsByName[name] = test;
	testsByDeclaredOrder[id] = test;
}

TestSuite* TestSuite::findOrCreateSuite(Id id, string name) {
	auto found = suitesByName.find(name);
	if (found == suitesByName.end()) {
		TestSuite* newSuite = new TestSuite(name);
		suitesByName[name] = id;
		suites[id] = newSuite;
		return newSuite;
	}
	return suites[found->second];
}

void TestSuite::addBefore(Id id, Runnable* runnableBefore) {
	befores[id] = runnableBefore;
}

void TestSuite::addAfter(Id id, Runnable* runnableAfter) {
	afters[id] = runnableAfter;
}

void TestSuite::addVerify(Id id, Runnable* runnableVerify) {
	verifies[id] = runnableVerify;
}

TestSuite* TestSuite::findByName(const std::string& name) {
	auto found = suitesByName.find(name);
	return found != suitesByName.end() ? suites[found->second] : nullptr;
}

} /* namespace stablecode */

