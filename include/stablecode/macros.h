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
// BEFORE macros
#define BEFORE STABLECODE_BEFORE
#define STABLECODE_BEFORE \
	_STABLECODE_GENERATED_CLASS_(before, \
								 _STABLECODE_UNIQUE_ID_(before, before), \
								 _STABLECODE_UNIQUE_ID_(beforeCode, before), \
								 _STABLECODE_UNIQUE_ID_(beforeObject, before))

//======================================================================
// AFTER macros
#define AFTER STABLECODE_AFTER
#define STABLECODE_AFTER \
	_STABLECODE_GENERATED_CLASS_(after, \
								 _STABLECODE_UNIQUE_ID_(after, after), \
								 _STABLECODE_UNIQUE_ID_(afterCode, after), \
								 _STABLECODE_UNIQUE_ID_(afterObject, after))

//======================================================================
// VERIFY macros
#define VERIFY STABLECODE_VERIFY
#define STABLECODE_VERIFY \
	_STABLECODE_GENERATED_CLASS_(verify, \
								 _STABLECODE_UNIQUE_ID_(verify, verify), \
								 _STABLECODE_UNIQUE_ID_(verifyCode, verify), \
								 _STABLECODE_UNIQUE_ID_(verifyObject, verify))


//======================================================================
// Generated class
#define _STABLECODE_GENERATED_CLASS_($name, $class, $code, $object) \
	static int _STABLECODE_UNIQUE_ID_(lineLock, var) = 0;\
	template<int N> \
	class $class: public stablecode::GeneratedClass { \
	public: \
		$class(std::string declaredName, stablecode::Module* module, stablecode::GeneratedClass::Code code, stablecode::Source source): \
		GeneratedClass(declaredName, module, code, source){ \
			_STABLECODE_UNIQUE_ID_(lineLock, var)++; \
		} \
	}; \
	static void $code(stablecode::statement::Log&,stablecode::statement::Expect&); \
	static $class<__LINE__> $object(""#$name, &__STABLECODE_THIS_MODULE__, $code, stablecode::Source(__FILE__, __LINE__)); \
	static void $code(stablecode::statement::Log& log,stablecode::statement::Expect& expect)

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
// Logging
#define INFO($logExpression) STABLECODE_INFO($logExpression)
#define STABLECODE_INFO($logExpression) \
	log(_STABLECODE_SOURCE__).info([&](std::ostream& logOut){logOut<<$logExpression;})

//======================================================================
//ID macroses

#define _STABLECODE_UNIQUE_ID_(type, name) _STABLECODE_ID_(type, name, __LINE__)
#define _STABLECODE_ID_(type, name, id) _STABLECODE_ID_CONCAT_(stablecode, type, name, id)
#define _STABLECODE_ID_CONCAT_(prefix, type, name, id) __$##prefix##$##type##$##name##$##id##$__

#define _STABLECODE_SOURCE__ stablecode::Source(__FILE__, __LINE__)

#define MERGE_(a,b)  a##b
#define LABEL_(prefix, id) MERGE_(prefix, id)
#define UNIQUE_ID(prefix) LABEL_(prefix, __LINE__ )


#endif /* INCLUDE_STABLECODE_MACROS_H_ */
