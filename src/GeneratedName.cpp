/*
 * GeneratedName.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */
#include <iostream>

#include "GeneratedName.h"
#include "GeneratedNameParser.h"

namespace stablecode {
using namespace std;


GeneratedName::GeneratedName(const string& generatedName) {
	GeneratedNameParser parser;
	while(parser.parseNext(generatedName)) {

		cout<<parser.prefix()<<"-"<<parser.type()<<"-"<<parser.name()<<"-"<<parser.id()<<"====";

	}
	cout<<endl;

}

GeneratedName::~GeneratedName() {

}

stablecode::GeneratedName::Token::Token(TokenType type, Id id, const string& value):
	type(type), id(id), value(value) {

}


} /* namespace stablecode */

