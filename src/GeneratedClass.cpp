/*
 * GeneratedClass.cpp
 *
 *  Created on: Mar 20, 2016
 *      Author: dvily_000
 */

#include "stablecode/GeneratedClass.h"

namespace stablecode {
using namespace std;

GeneratedClass::GeneratedClass(string declaredName, Module* module, Source source):
		Registerable(module), declaredName(declaredName), module(module), source(source) {

}

GeneratedClass::~GeneratedClass() {

}

} /* namespace stablecode */
