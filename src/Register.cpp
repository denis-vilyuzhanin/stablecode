/*
 * Register.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "Register.h"

namespace stablecode {

Register* Register::INSTANCE = 0;


Register::Register() {
}

Register* Register::getInstance() {
	if (INSTANCE == 0) {
		INSTANCE = new Register();
	}
	return INSTANCE;
}

void Register::registerObject(Registerable* newObject) {
	registeredObjects.push_back(newObject);
}

const std::list<Registerable*>& Register::getAllRegisteredObjects() const {
	return registeredObjects;
}

} /* namespace stablecode */

