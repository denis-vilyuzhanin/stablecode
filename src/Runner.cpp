/*
 * Runner.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: Denys_Viliuzhanin
 */

#include <iostream>

#include "Runner.h"

#include "stablecode/Registerable.h"
#include "stablecode/Test.h"
#include "Register.h"

namespace stablecode {

Runner::Runner() {
	// TODO Auto-generated constructor stub

}

Runner::~Runner() {
	// TODO Auto-generated destructor stub
}

void Runner::discovery() {
	for(Registerable* registeredObject : Register::getInstance()->getAllRegisteredObjects()) {
		Test* test = dynamic_cast<Test*>(registeredObject);
		if(test != 0) {
			std::cout<<test->getClassName()<<std::endl;
			tests.push_back(test);
			test->run();
		}
	}
}

void Runner::runAll() {
}

} /* namespace stablecode */