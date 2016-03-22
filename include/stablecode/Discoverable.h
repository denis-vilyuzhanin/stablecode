/*
 * Registerable.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_DISCOVERABLE_H_
#define INCLUDE_STABLECODE_DISCOVERABLE_H_

#include <list>
#include <string>

#include "Module.h"

namespace stablecode {

class Discoverable {
public:
	virtual ~Discoverable();
	const std::string getClassName() const;

protected:
	Discoverable();

};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_DISCOVERABLE_H_ */
