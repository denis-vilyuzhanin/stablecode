/*
 * Discovery.h
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#ifndef SRC_DISCOVERY_H_
#define SRC_DISCOVERY_H_

#include <list>

#include "stablecode/Registerable.h"

namespace stablecode {


class Discovery {
public:
	Discovery();
	virtual ~Discovery();
public:
	void discover(const std::list<Registerable*>&);
};

} /* namespace tablecode */

#endif /* SRC_DISCOVERY_H_ */
