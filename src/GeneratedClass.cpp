/*
 * GeneratedClass.cpp
 *
 *  Created on: Mar 20, 2016
 *      Author: dvily_000
 */

#include <list>

#include "stablecode/GeneratedClass.h"
#include "GeneratedNameParser.h"

namespace stablecode {
using namespace std;

GeneratedClass::GeneratedClass(string declaredName, Module* module, Code code, Source source):
		declaredName(declaredName), module(module), code(code), source(source) {
}

GeneratedClass::~GeneratedClass() {

}

} /* namespace stablecode */

