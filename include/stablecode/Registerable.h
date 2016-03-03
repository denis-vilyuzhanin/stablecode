/*
 * Registerable.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_REGISTERABLE_H_
#define INCLUDE_STABLECODE_REGISTERABLE_H_

namespace stablecode {

class Registerable {
public:
	enum Type {
			SUITE,
			TEST,
			VERIFY,
			INIT,
			DESTROY
		};
public:
	Type getType();
protected:
	Registerable(Type type);
	virtual ~Registerable();
private:
	Type type;
};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_REGISTERABLE_H_ */
