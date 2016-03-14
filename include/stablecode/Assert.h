/*
 * Assert.h
 *
 *  Created on: Mar 14, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_ASSERT_H_
#define INCLUDE_STABLECODE_ASSERT_H_

#include<functional>

#include "statement.h"
namespace stablecode {

class Assert {
public:
	typedef statement::ThatStatement& That;
	typedef std::function<statement::LastStatement&(That that)> Expression;
public:
	Assert(Expression expression);
	virtual ~Assert();

public:


};

} /* namespace stablecode */

#endif /* INCLUDE_STABLECODE_ASSERT_H_ */
