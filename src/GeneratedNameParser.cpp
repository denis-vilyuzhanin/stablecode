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

GeneratedNameParser::GeneratedNameParser(const std::string& targetString): targetString(targetString) {

}



bool GeneratedNameParser::parseNextSuite() {
	auto type = parseType();
	if (type == "suite" || type == "") {
		return parseNext() && parseType() == "suite";
	}
	return false;
}

bool GeneratedNameParser::parseNext() {
	fragmentBeginOffset = targetString.find(START, fragmentEndOffset);
	if (fragmentBeginOffset == string::npos) {
		return false;
	}
	fragmentEndOffset = targetString.find(END, fragmentBeginOffset);
	nextFragment = targetString.substr(
			fragmentBeginOffset + START.length(), fragmentEndOffset - fragmentBeginOffset - END.length());
	typeOffset = nextFragment.find(DELIMITER, 0) + DELIMITER.length();
	nameOffset = nextFragment.find(DELIMITER, typeOffset) + DELIMITER.length();
	idOffset = nextFragment.find(DELIMITER, nameOffset) + DELIMITER.length();
	return true;
}

std::string GeneratedNameParser::parsePrefix() const {
	return nextFragment.substr(0, typeOffset - DELIMITER.length());
}

std::string GeneratedNameParser::parseType() const {
	return nextFragment.substr(typeOffset, nameOffset - typeOffset - DELIMITER.length());
}

std::string GeneratedNameParser::parseName() const {
	return nextFragment.substr(nameOffset, idOffset - nameOffset - DELIMITER.length());
}

Id GeneratedNameParser::parseId() const {
	return Id(std::stoi(nextFragment.substr(idOffset)));
}

} /* namespace stablecode */
