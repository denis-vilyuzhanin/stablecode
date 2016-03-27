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
namespace _STABLECODE_UNIQUE_ID_(suite, suiteName)


//======================================================================
// TEST macros
#define TEST(testName) STABLECODE_TEST(testName)
#define STABLECODE_TEST(declaredTestName) \
	_STABLECODE_GENERATED_CLASS_(declaredTestName, \
								 _STABLECODE_UNIQUE_ID_(test, declaredTestName), \
								 _STABLECODE_UNIQUE_ID_(testCode, declaredTestName), \
								 _STABLECODE_UNIQUE_ID_(testObject, declaredTestName))

//======================================================================
// Generated class
#define _STABLECODE_GENERATED_CLASS_($name, $class, $code, $object) \
	template<int N> \
	class $class: public stablecode::GeneratedClass { \
	public: \
		$class(std::string declaredName, stablecode::Module* module, stablecode::GeneratedClass::Code code, stablecode::Source source): \
		GeneratedClass(declaredName, module, code, source){} \
	}; \
	static void $code(); \
	static $class<__LINE__> $object(""#$name, &__STABLECODE_THIS_MODULE__, $code, stablecode::Source(__FILE__, __LINE__)); \
	static void $code()

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

#define _STABLECODE_UNIQUE_ID_(type, name) _STABLECODE_ID_(type, name, __LINE__)
#define _STABLECODE_ID_(type, name, id) _STABLECODE_ID_CONCAT_(stablecode, type, name, id)
#define _STABLECODE_ID_CONCAT_(prefix, type, name, id) __$##prefix##$##type##$##name##$##id##$__

#define MERGE_(a,b)  a##b
#define LABEL_(prefix, id) MERGE_(prefix, id)
#define UNIQUE_ID(prefix) LABEL_(prefix, __LINE__ )


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
