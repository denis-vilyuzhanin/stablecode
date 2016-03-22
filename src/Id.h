/*
 * Id.h
 *
 *  Created on: Mar 22, 2016
 *      Author: dvily_000
 */

#ifndef SRC_ID_H_
#define SRC_ID_H_

namespace stablecode {

class Id {
public:
	Id(int value):value(value){}

	int getValue() const {return value;}

	bool operator<(const Id& other) const {
		return this->value < other.value;
	}

	bool operator>(const Id& other) const {
		return this->value > other.value;
	}

	bool operator==(const Id& other) const {
		return this->value == other.value;
	}
private:
	int value;
};

} /* namespace stablecode */

#endif /* SRC_ID_H_ */
