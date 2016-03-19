/*
 * GeneratedNameParser.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_GENERATEDNAMEPARSER_H_
#define SRC_GENERATEDNAMEPARSER_H_

#include <string>

namespace stablecode {

class GeneratedNameParser {
public:
	bool parseNext(const std::string& generatedName);

	std::string prefix()const;
	std::string type()const;
	std::string name()const;
	std::string id()const;
private:
	static const std::string START;
	static const std::string END;
	static const std::string DELIMITER;

	size_t fragmentBeginOffset = 0;
	size_t fragmentEndOffset = 0;
	std::string nextFragment;
	size_t typeOffset = 0;
	size_t nameOffset = 0;
	size_t idOffset = 0;
};

} /* namespace stablecode */

#endif /* SRC_GENERATEDNAMEPARSER_H_ */
