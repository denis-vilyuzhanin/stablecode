/*
 * Registerable.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_REGISTERABLE_H_
#define INCLUDE_STABLECODE_REGISTERABLE_H_

#include <string>

namespace stablecode {

class Registerable {
public:

	class Auto {
	public:
		Auto(Registerable* object);
	};

public:

	const std::string getClassName() const;

protected:
	Registerable();
	virtual ~Registerable();
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_REGISTERABLE_H_ */
