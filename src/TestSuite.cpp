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
		suitesByName[name] = newSuite;
		suitesByDeclaredOrder[id] = newSuite;
		return newSuite;
	}
	return found->second;
}

} /* namespace stablecode */

