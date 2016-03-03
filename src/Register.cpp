/*
 * Register.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "Register.h"

namespace stablecode {

Register Register::INSTANCE;


Register::Register() {
}

Register* Register::getInstance() {
	return &INSTANCE;
}

void Register::registerObject(Registerable* newObject) {
	registeredObjects.push_back(newObject);
}

const std::list<Registerable*>& Register::getAllRegisteredObjects() const {
	return registeredObjects;
}

} /* namespace stablecode */

