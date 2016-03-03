/*
 * macros.h
 *
 *  Created on: Mar 3, 2016
 *      Author: Denys_Viliuzhanin
 */

#ifndef INCLUDE_STABLECODE_MACROS_H_
#define INCLUDE_STABLECODE_MACROS_H_

//======================================================================
// SUITE macros
#define SUITE(suiteName) STABLECODE_SUITE(suiteName)
#define STABLECODE_SUITE(suiteName) \
namespace _STABLECODE_SUITE_NS_(suiteName) { \
	class _STABLECODE_SUITE_CLASS_(suiteName): public stablecode::TestSuite { \
	} __$suite$__; \
} \
namespace _STABLECODE_SUITE_NS_(suiteName)


//======================================================================
// TEST macros
#define TEST(testName) STABLECODE_TEST(testName)
#define STABLECODE_TEST(testName) \
class _STABLECODE_TEST_CLASS_(testName): public stablecode::Test { \
public: \
	void run(); \
} __$##testName##$__; \
void _STABLECODE_TEST_CLASS_(testName)::run()


//======================================================================
//STARTUP macros

#define STARTUP \
static class __$startup_type$__LINE__ { \
public: \
	__$startup_type$__LINE__() {run();} \
	void run(); \
} __$startup_var$__LINE__; \
void __$startup_type$__LINE__::run()

//======================================================================
//ID macroses

#define _STABLECODE_SUITE_CLASS_(name) _STABLECODE_ID_(suite, name)
#define _STABLECODE_SUITE_NS_(name) _STABLECODE_ID_(suiteNS, name)
#define _STABLECODE_TEST_CLASS_(name)  _STABLECODE_ID_(test, name)
#define _STABLECODE_ID_(type, name) __$stablecode$##type##$##name##$__


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
