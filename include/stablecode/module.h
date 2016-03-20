/*
 * module.h
 *
 *  Created on: Mar 18, 2016
 *      Author: dvily_000
 */

#ifndef INCLUDE_STABLECODE_MODULE_H_
#define INCLUDE_STABLECODE_MODULE_H_


#include <iostream>
namespace stablecode {

class Module {
public:
	typedef unsigned long long int Id;
public:
	Module(){};
	virtual ~Module(){}
public:
	Id getId() const;
};



} /* namespace stablecode */

static stablecode::Module __STABLECODE_THIS_MODULE__;


#endif /* INCLUDE_STABLECODE_MODULE_H_ */
