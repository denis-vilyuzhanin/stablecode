/*
 * Source.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include "stablecode/Source.h"
#include <utility>

namespace stablecode {

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

}
/* namespace stablecode */

