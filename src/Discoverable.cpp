/*
 * Registerable.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */
#include "stablecode/Discoverable.h"

#include <typeinfo>


#include "Register.h"

namespace stablecode {

Discoverable::Discoverable() {
	Register::getInstance()->registerObject(this);
}


Discoverable::~Discoverable() {

}



const std::string Discoverable::getClassName() const {
	return typeid(*this).name();
}

} /* namespace stablecode */

