/*
 * Register.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_REGISTER_H_
#define SRC_REGISTER_H_

#include "stablecode/Registerable.h"

#include <list>
namespace stablecode {

class TestSuite;
class Test;

class Register {
	friend Registerable;
public:
	static Register* getInstance();

	const std::list<Registerable*>& getAllRegisteredObjects() const;

private:
	Register();
	void registerObject(Registerable* newTest);
private:
	static Register INSTANCE;

	std::list<Registerable*> registeredObjects;
};

} /* namespace stablecode */

#endif /* SRC_REGISTER_H_ */
