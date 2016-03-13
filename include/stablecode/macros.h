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
} _STABLECODE_UNIQUE_ID_(testObject, testName); \
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
// Assertion

#define EXPECT1() expect1(__LINE__)
#define EXPECT() expect()

//======================================================================
//ID macroses

#define _STABLECODE_SUITE_CLASS_(name) _STABLECODE_UNIQUE_ID_(suite, name)
#define _STABLECODE_SUITE_NS_(name) _STABLECODE_UNIQUE_ID_(suiteNS, name)
#define _STABLECODE_TEST_CLASS_(name)  _STABLECODE_UNIQUE_ID_(test, name)
#define _STABLECODE_UNIQUE_ID_(type, name) _STABLECODE_ID_(type, name, __LINE__)
#define _STABLECODE_ID_(type, name, id) _STABLECODE_ID_CONCAT_(stablecode, type, name, id)
#define _STABLECODE_ID_CONCAT_(prefix, type, name, id) __$##prefix##$##type##$##name##$##id##$__

#define MERGE_(a,b)  a##b
#define LABEL_(prefix, id) MERGE_(prefix, id)
#define UNIQUE_ID(prefix) LABEL_(prefix, __LINE__ )


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
