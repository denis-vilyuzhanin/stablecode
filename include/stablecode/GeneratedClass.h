/*
 * GeneratedClass.h
 *
 *  Created on: Mar 20, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_GENERATEDCLASS_H_
#define INCLUDE_STABLECODE_GENERATEDCLASS_H_

#include <stablecode/Discoverable.h>
#include <string>
#include "Module.h"
#include "Source.h"

namespace stablecode {

class GeneratedClass: public Discoverable {
public:
	virtual ~GeneratedClass();
protected:
	GeneratedClass(std::string declaredName, Module* module, Source source);
protected:
	std::string declaredName;
	Module* module;
	Source source;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_GENERATEDCLASS_H_ */
