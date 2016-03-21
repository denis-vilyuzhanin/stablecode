/*
 * Register.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef SRC_REGISTER_H_
#define SRC_REGISTER_H_

#include <stablecode/Discoverable.h>
#include <list>
namespace stablecode {

class TestSuite;
class Test;

class Register {
	friend Discoverable;
public:
	static Register* getInstance();

	const std::list<Discoverable*>& getAllRegisteredObjects() const;

private:
	Register();
	void registerObject(Discoverable* newTest);
private:
	static Register* INSTANCE;

	std::list<Discoverable*> registeredObjects;
};

} /* namespace stablecode */

#endif /* SRC_REGISTER_H_ */
