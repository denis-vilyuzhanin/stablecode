/*
 * module.h
 *
 *  Created on: Mar 18, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_MODULE_H_
#define INCLUDE_STABLECODE_MODULE_H_



#include "Source.h"

namespace stablecode {

class Module {
public:
	typedef unsigned long long int Id;
public:
	Module(Source source);
public:
	Id getId() const;
	const Source& getSource() const {return source;}
private:
	Source source;
};



} /* namespace stablecode */

static stablecode::Module __STABLECODE_THIS_MODULE__(stablecode::Source(__FILE__, __LINE__));


#endif /* INCLUDE_STABLECODE_MODULE_H_ */
