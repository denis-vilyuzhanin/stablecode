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

TestSuite::TestSuite(Id id, string name):
		id(id), name(name) {
}

TestSuite::TestSuite(Id id, std::string name, TestSuite* parent):
		id(id), name(name), parent(parent) {
	fullName = parent->fullName + "." + parent->name;
}

TestSuite::~TestSuite() {

}

void TestSuite::addTest(Id id, const std::string& name, Test* test) {
	testsByName[name] = test;
	testsByDeclaredOrder[id] = test;
	test->setSuite(this);
}

TestSuite* TestSuite::findOrCreateSuite(Id id, string name) {
	auto found = suitesByName.find(name);
	if (found == suitesByName.end()) {
		TestSuite* newSuite = new TestSuite(id, name, this);
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

void TestSuite::collectWhatMustBeRun(std::list<Runnable*>& before, std::list<Runnable*>& after, std::list<Runnable*>& verify) {
	for(auto afterEntry : befores) {
		after.push_back(afterEntry.second);
	}
	for(auto verifyEntry : verifies) {
		verify.push_back(verifyEntry.second);
	}
	if (parent != nullptr) {
		parent->collectWhatMustBeRun(before, after, verify);
	}
	for(auto beforeEntry : befores) {
		before.push_back(beforeEntry.second);
	}
}

} /* namespace stablecode */

