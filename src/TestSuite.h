/*
 * TestSuite.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_TESTSUITE_H_
#define INCLUDE_STABLECODE_TESTSUITE_H_

#include <list>
#include <string>
#include <map>

#include "Test.h"
#include "Runnable.h"
#include "Id.h"

namespace stablecode {

class TestSuite {
public:
	TestSuite(Id id, std::string name);
	TestSuite(Id id, std::string name, TestSuite* parent);
	virtual ~TestSuite();
public:
	void addTest(Id id, const std::string& name, Test*);
	void addBefore(Id id, Runnable* runnableBefore);
	void addAfter(Id id, Runnable* runnableAfter);
	void addVerify(Id id, Runnable* runnableAfter);
	TestSuite* findOrCreateSuite(Id id, std::string name);
	TestSuite* findByName(const std::string& name);

	void collectWhatMustBeRun(std::list<Runnable*>& before, std::list<Runnable*>& after, std::list<Runnable*>& verify);

	const std::string& getName() const {return name;}
	const std::map<Id, TestSuite*>& getSuites() const {return suites;}
	const std::map<Id, Test*>& getTests() const {return testsByDeclaredOrder;}
	const std::map<Id, Runnable*> getBefores() const {return befores;}
	const std::map<Id, Runnable*> getAfters() const {return afters;}
	const std::map<Id, Runnable*> getVerifies() const {return verifies;}
	TestSuite* getParent() const {return parent;}
private:
	TestSuite* parent = nullptr;
	Id id;
	std::string name;
	std::map<Id, Runnable*> befores;
	std::map<Id, Runnable*> afters;
	std::map<Id, Runnable*> verifies;
	std::map<std::string, Test*> testsByName;
	std::map<Id, Test*> testsByDeclaredOrder;
	std::map<std::string, Id> suitesByName;
	std::map<Id, TestSuite*> suites;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TESTSUITE_H_ */
