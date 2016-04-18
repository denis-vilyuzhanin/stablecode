/*
 * Source.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include "stablecode/Source.h"
#include <utility>

namespace stablecode {
using namespace std;

Source::Source(const std::string& file, int lineNumber):
	file(file), lineNumber(lineNumber){
}

Source::Source(const Source& other):
	file(other.file), lineNumber(other.lineNumber){
}

Source::Source(const Source&& other) NOEXCEPT:
	file(std::move(other.file)), lineNumber(other.lineNumber){
}

Source::Source():lineNumber(-1) {
}

string Source::fileName() {
	unsigned int index = file.find_last_of("/");
	if (index == string::npos || index < 0 || index >= file.length()) {
		index = file.find_last_of("\\");
	}
	return index == string::npos ? file : file.substr(index + 1);
}

bool Source::isUndefined() const {
	return lineNumber < 0;
}


} /* namespace stablecode */

