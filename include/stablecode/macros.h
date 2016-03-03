/*
 * macros.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_MACROS_H_
#define INCLUDE_STABLECODE_MACROS_H_

#define STABLECODE_SUITE(suiteName) \
namespace _STABLECODE_SUITE_NS_(suiteName) { \
	class _STABLECODE_SUITE_CLASS_(suiteName): public stablecode::TestSuite { \
	} __$suite$__; \
} \
namespace _STABLECODE_SUITE_NS_(suiteName)

#define SUITE(suiteName) STABLECODE_SUITE(suiteName)


#define STARTUP \
static class __$startup_type$__LINE__ { \
public: \
	__$startup_type$__LINE__() {run();} \
	void run(); \
} __$startup_var$__LINE__; \
void __$startup_type$__LINE__::run()

#define _STABLECODE_SUITE_CLASS_(name) _STABLECODE_ID_(suiteClass, name)
#define _STABLECODE_SUITE_NS_(name) _STABLECODE_ID_(suiteNS, name)
#define _STABLECODE_ID_(type, name) __$stablecode$##type##$##name##$__


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
