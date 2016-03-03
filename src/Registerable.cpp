/*
 * Registerable.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#include "stablecode/Registerable.h"
#include "Register.h"

namespace stablecode {

Registerable::Registerable(Type type): type(type) {
	Register::getInstance()->registerObject(this);
}

Registerable::Type Registerable::getType() {
	return type;
}

Registerable::~Registerable() {

}

} /* namespace stablecode */
