/*
 * Registerable.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_REGISTERABLE_H_
#define INCLUDE_STABLECODE_REGISTERABLE_H_

#include <string>

#include "Module.h"

namespace stablecode {

class Registerable {
public:

	class Auto {
	public:
		Auto(Registerable* object);
	};

public:
	virtual ~Registerable();
	const std::string getClassName() const;
	Module* getModule() const {return module;}

protected:
	Registerable(Module* module);

private:
	Module* module;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_REGISTERABLE_H_ */
