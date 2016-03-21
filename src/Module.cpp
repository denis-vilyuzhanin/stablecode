/*
 * Module.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */


#include "stablecode/Module.h"

namespace stablecode {

Module::Module(Source source): source(source){}

Module::Id Module::getId() const {
	return reinterpret_cast<Module::Id>(this);
}

} /* namespace stablecode */

