/*
 * Value.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: dvily_000
 */

#include <stablecode/Value.h>

namespace stablecode {

Value::Value(const std::type_info& valueType):valueType(valueType) {


}

Value::~Value() {
	// TODO Auto-generated destructor stub
}

bool Value::compare(Value::Comparator comparator, const Value& other) const {
	return this->valueType == other.valueType && comparator(*this, other);
}

} /* namespace stablecode */
