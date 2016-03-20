/*
 * Registerable.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */
#include <typeinfo>


#include "stablecode/Registerable.h"
#include "Register.h"

namespace stablecode {

Registerable::Registerable(Module* module): module(module) {
}


Registerable::~Registerable() {

}



const std::string Registerable::getClassName() const {
	return typeid(*this).name();
}

Registerable::Auto::Auto(Registerable* object) {
	Register::getInstance()->registerObject(object);
}


} /* namespace stablecode */

