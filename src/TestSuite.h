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

#include "stablecode/Test.h"
#include "Id.h"

namespace stablecode {

class TestSuite {
public:
	TestSuite(std::string name);
	virtual ~TestSuite();
public:
	void addTest(Id id, const std::string& name, Test*);
	TestSuite* findOrCreateSuite(Id id, std::string name);
	TestSuite* findByName(const std::string& name);
	const std::string& getName() const {return name;}
	const std::map<Id, std::string>& getSuites() const {return suitesByDeclaredOrder;}
	const std::map<Id, std::string>& getTests() const {return testsByDeclaredOrder;}
private:
	std::string name;
	std::list<Test*> tests;
	std::map<std::string, Test*> testsByName;
	std::map<Id, std::string> testsByDeclaredOrder;
	std::map<std::string, TestSuite*> suitesByName;
	std::map<Id, std::string> suitesByDeclaredOrder;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_TESTSUITE_H_ */
