/*
 * GeneratedClass.h
 *
 *  Created on: Mar 20, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_GENERATEDCLASS_H_
#define INCLUDE_STABLECODE_GENERATEDCLASS_H_

#include <stablecode/Discoverable.h>
#include <stablecode/statement.h>
#include <string>
#include <list>

#include "Module.h"
#include "Source.h"

namespace stablecode {

class GeneratedClass: public Discoverable {
public:
	typedef void(*Code)(statement::LoggingStatement&,statement::ExpectingStatement&);
public:
	virtual ~GeneratedClass();
public:

	Module* getModule() const {return module;}
	const Source& getSource() const {return source;}
	Code getCode() const {return code;}
protected:
	GeneratedClass(std::string declaredName, Module* module, Code code, Source source);
protected:
	std::string declaredName;
	Module* module;
	Code code;
	Source source;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_GENERATEDCLASS_H_ */
