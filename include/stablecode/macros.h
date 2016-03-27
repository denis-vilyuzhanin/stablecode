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
namespace _STABLECODE_SUITE_(suiteName) { \
	static stablecode::Source __THIS_SUITE__(__FILE__, __LINE__);\
} \
namespace _STABLECODE_SUITE_(suiteName)


//======================================================================
// TEST macros
#define TEST(testName) STABLECODE_TEST(testName)
#define STABLECODE_TEST(testName) \
template<int N> \
class _STABLECODE_TEST_CLASS_(testName): public stablecode::GeneratedClass { \
public: \
	_STABLECODE_TEST_CLASS_(testName)(std::string declaredName, stablecode::Module* module, stablecode::GeneratedClass::Code code, stablecode::Source source): \
		GeneratedClass(declaredName, module, code, source){} \
}; \
static void _STABLECODE_TEST_CODE_(testName)();\
static _STABLECODE_TEST_CLASS_(testName)<__LINE__> \
	_STABLECODE_UNIQUE_ID_(testObject, testName)( \
			""#testName, &__STABLECODE_THIS_MODULE__, _STABLECODE_TEST_CODE_(testName), stablecode::Source(__FILE__, __LINE__)); \
static void _STABLECODE_TEST_CODE_(testName)()


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

#define EXPECT(reason) expect(reason"")


//======================================================================
//ID macroses

#define _STABLECODE_SUITE_(name) _STABLECODE_UNIQUE_ID_(suite, name)
#define _STABLECODE_TEST_CLASS_(name)  _STABLECODE_UNIQUE_ID_(test, name)
#define _STABLECODE_TEST_CODE_(name)  _STABLECODE_UNIQUE_ID_(testCode, name)
#define _STABLECODE_UNIQUE_ID_(type, name) _STABLECODE_ID_(type, name, __LINE__)
#define _STABLECODE_ID_(type, name, id) _STABLECODE_ID_CONCAT_(stablecode, type, name, id)
#define _STABLECODE_ID_CONCAT_(prefix, type, name, id) __$##prefix##$##type##$##name##$##id##$__

#define MERGE_(a,b)  a##b
#define LABEL_(prefix, id) MERGE_(prefix, id)
#define UNIQUE_ID(prefix) LABEL_(prefix, __LINE__ )


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
