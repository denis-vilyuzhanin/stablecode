/*
 * Scope.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: dvily_000
 */

#include <stablecode/Scope.h>

namespace stablecode {

Scope::Scope() {}

void Scope::addLevel(const std::string& nextLevelName) {
	names.push_back(nextLevelName);
}

} /* namespace stablecode */
