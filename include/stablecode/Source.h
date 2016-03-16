/*
 * Source.h
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_SOURCE_H_
#define INCLUDE_STABLECODE_SOURCE_H_

#include "configuration.h"

#include<string>

namespace stablecode {

class Source {
public:
	Source();
	Source(const std::string& fileName, int lineNumber);
	Source(const Source& other);
	Source(const Source&& other) NOEXCEPT;
public:
	const std::string& getFileName() const {return fileName;}
	int getLineNumber() const {return lineNumber;}
private:

	std::string fileName;
	int lineNumber;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_SOURCE_H_ */
