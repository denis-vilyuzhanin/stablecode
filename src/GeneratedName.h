/*
 * GeneratedName.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_GENERATEDNAME_H_
#define SRC_GENERATEDNAME_H_

#include <string>
#include <list>
namespace stablecode {

class GeneratedName {
public:
	enum class TokenType {
		TEST,
		SUITE
	};
	class Token {
	public:
		typedef int Id;
	public:
		Token(TokenType type, Id id, const std::string& value);
	public:
		TokenType getType() const {return type;}
		const std::string& getValue() const {return value;}
	private:
		TokenType type;
		Id id;
		std::string value;
	};
public:
	GeneratedName(const std::string& generatedName);
	virtual ~GeneratedName();
public:



	const std::list<Token>& getTokens() const {return tokens;}

private:
	std::list<Token> tokens;
};

} /* namespace stablecode */

#endif /* SRC_GENERATEDNAME_H_ */
