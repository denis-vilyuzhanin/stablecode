/*
 * Registerable.cpp
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */
#include <typeinfo>

#include "stablecode/Discoverable.h"

#include "Discovery.h"

namespace stablecode {

Discoverable::Discoverable() {
	Discovery::toBeDiscovered(this);
}


Discoverable::~Discoverable() {

}

const std::string Discoverable::getClassName() const {
	return typeid(*this).name();
}

} /* namespace stablecode */

