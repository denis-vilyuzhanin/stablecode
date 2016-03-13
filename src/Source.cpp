/*
 * Source.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include "stablecode/Source.h"
#include <utility>

namespace stablecode {

Source::Source(const std::string& fileName, int lineNumber):
	fileName(fileName), lineNumber(lineNumber){
}

Source::Source(const Source& other):
	fileName(other.fileName), lineNumber(other.lineNumber){
}

Source::Source(const Source&& other) NOEXCEPT:
	fileName(std::move(other.fileName)), lineNumber(other.lineNumber){
}

} /* namespace stablecode */

