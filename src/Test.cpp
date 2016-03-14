/*
 * Test.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/Test.h"

#include "Register.h"
#include "Expectation.h"
#include <iostream>

namespace stablecode {

Test::Test(): Registerable(Registerable::TEST){
}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::run() {
}

ThatStatement& Test::expect(std::string reason) {
	std::cout<<"Expectation: "<<reason<<std::endl;
	Expectation* expectation = new Expectation();
	return *expectation;
}


} /* namespace stablecode */

