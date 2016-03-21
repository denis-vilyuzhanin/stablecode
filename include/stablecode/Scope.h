/*
 * Scope.h
 *
 *  Created on: Mar 21, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_SCOPE_H_
#define INCLUDE_STABLECODE_SCOPE_H_

#include <string>
#include <vector>
namespace stablecode {

class Scope {
public:
	typedef std::vector<std::string> Names;
	typedef Names::const_iterator NamesIterator;
public:
	Scope();

	void addLevel(const std::string& nextLevelName);

	NamesIterator begin() const{
		return names.begin();
	}

	NamesIterator end() const {
		return names.end();
	}
private:
	Names names;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_SCOPE_H_ */
