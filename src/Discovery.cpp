/*
 * Discovery.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: dvily_000
 */

#include "Discovery.h"

#include "stablecode/GeneratedTest.h"

#include <iostream>

namespace stablecode {
using namespace std;

Discovery::Discovery() {
	// TODO Auto-generated constructor stub

}

Discovery::~Discovery() {
	// TODO Auto-generated destructor stub
}

void Discovery::discover(const list<Registerable*>& objects) {
	for(Registerable* object: objects) {
		GeneratedTest* test = dynamic_cast<GeneratedTest*>(object);
		if (object != nullptr) {
			cout<<"Test: "<<test->getClassName()<<endl;
		}
	}
}

} /* namespace tablecode */
