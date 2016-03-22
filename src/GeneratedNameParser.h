/*
 * GeneratedNameParser.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_GENERATEDNAMEPARSER_H_
#define SRC_GENERATEDNAMEPARSER_H_

#include <string>

#include  "Id.h"

namespace stablecode {

class GeneratedNameParser {

public:
	GeneratedNameParser(const std::string& targetString);
public:

	bool parseNextSuite();

	std::string parsePrefix()const;
	std::string parseType()const;
	std::string parseName()const;
	Id parseId()const;

private:
	bool parseNext();

private:
	static const std::string START;
	static const std::string END;
	static const std::string DELIMITER;

	std::string targetString;
	size_t fragmentBeginOffset = 0;
	size_t fragmentEndOffset = 0;
	std::string nextFragment;
	size_t typeOffset = 0;
	size_t nameOffset = 0;
	size_t idOffset = 0;
};

} /* namespace stablecode */

#endif /* SRC_GENERATEDNAMEPARSER_H_ */
