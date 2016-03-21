/*
 * GeneratedClass.cpp
 *
 *  Created on: Mar 20, 2016
 *      Author: dvily_000
 */

#include "stablecode/GeneratedClass.h"
#include "GeneratedNameParser.h"

namespace stablecode {
using namespace std;

GeneratedClass::GeneratedClass(string declaredName, Module* module, Source source):
		declaredName(declaredName), module(module), source(source) {

}

GeneratedClass::~GeneratedClass() {

}

void GeneratedClass::init() {
	const string& className = getClassName();
	GeneratedNameParser parser;
	while(parser.parseNext(className)) {
		if (parser.type() != "suite") {
			break;
		}
		scope.addLevel(parser.name());
	}
}

const Scope& GeneratedClass::getScope() const{
	return scope;
}


} /* namespace stablecode */

