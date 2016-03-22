/*
 * GeneratedNameParser.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#include "GeneratedNameParser.h"

namespace stablecode {
using namespace std;

const std::string GeneratedNameParser::START = "__$";
const std::string GeneratedNameParser::END = "$__";
const std::string GeneratedNameParser::DELIMITER = "$";


bool GeneratedNameParser::parseNextSuite(const std::string& generatedName) {
	if (type() == "suite") {
		return parseNext(generatedName) && type() == "suite";
	}
	return false;
}

bool GeneratedNameParser::parseNext(const std::string& generatedName) {
	fragmentBeginOffset = generatedName.find(START, fragmentEndOffset);
	if (fragmentBeginOffset == string::npos) {
		return false;
	}
	fragmentEndOffset = generatedName.find(END, fragmentBeginOffset);
	nextFragment = generatedName.substr(
			fragmentBeginOffset + START.length(), fragmentEndOffset - fragmentBeginOffset - END.length());
	typeOffset = nextFragment.find(DELIMITER, 0) + DELIMITER.length();
	nameOffset = nextFragment.find(DELIMITER, typeOffset) + DELIMITER.length();
	idOffset = nextFragment.find(DELIMITER, nameOffset) + DELIMITER.length();
	return true;
}

std::string GeneratedNameParser::prefix() const {
	return nextFragment.substr(0, typeOffset - DELIMITER.length());
}

std::string GeneratedNameParser::type() const {
	return nextFragment.substr(typeOffset, nameOffset - typeOffset - DELIMITER.length());
}

std::string GeneratedNameParser::name() const {
	return nextFragment.substr(nameOffset, idOffset - nameOffset - DELIMITER.length());
}

Id GeneratedNameParser::id() const {
	return Id(std::stoi(nextFragment.substr(idOffset)));
}

} /* namespace stablecode */
