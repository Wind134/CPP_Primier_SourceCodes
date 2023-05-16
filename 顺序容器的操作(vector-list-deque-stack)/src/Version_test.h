
#ifndef VERSION_TEST_H
#define VERSION_TEST_H


/* As of the first printing of C++ Primer, 5th Edition (July 2012), 
 * the gcc Version 4.7.0 did not yet support some C++ 11 features.  
 *
 * The code we distribute contains both normal C++ code and 
 * workarounds for missing features.  We use preprocessor variables to
 * determine whether a given features is implemented in a given release
 * of the compiler.  
 * The base version we used to test the code in the book
 * is gcc version 4.7.0 (GCC) 
 *
 * When new releases are available we will update this file which will
 * #define the features implmented in that release.
*/

#if __cplusplus < 201103L 	// 检查环境是否是C++11以上的版本，若不是，则定义下列函数
// base version, future releases of this file will 
// #define these variables as features as they are implemented 

/* Code in this delivery use the following variables to control compilation

   Variable tests           C++ 11 Feature 
HEX_MANIPS               hexfloat and defaultfloat manipulators
REFMEMS                  reference qualified member functions
REGEX                    regular expressions library
STRING_NUMERIC_CONVS     conversions to and from string to numeric
*/
// #endif  // ends compiler version check

#ifndef STRING_NUMERIC_CONVS
// 如果库没有定义to_string 
// 或者没有数值转换函数
// 我们就会定义这些

// Readers can ignore the implemnetations of to_string and stod 
// but can use these functions in their code.

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
// we use sprintf from stdio to implement to_string
#include <cstdio>

inline
std::string to_string(int i)
{
	char buf[100];
	// sprintf 接受一个格式化字符串 format 和一系列的参数，并将格式化后的结果写入字符数组 str
	std::sprintf(buf, "%d", i);	// int -> char
	return buf;
}

inline
double stod(const std::string &s, std::size_t * = 0)
{
	char **buf = 0;
	// strtod 是 C++ 标准库中的一个函数，用于将字符串转换为双精度浮点数
	return std::strtod(s.c_str(), buf);	// buf指向s.c_str()这个C风格字符串的结尾位置
}
#endif   // STRING_NUMERIC_CONVS

#include <iostream>

#ifndef HEX_MANIPS
inline
std::ostream &defaultfloat(std::ostream &os) 
{
	os.unsetf(std::ios_base::floatfield);	// 取消输出格式标志，即默认的float格式
	return os;
}
#endif   // HEX_MANIPS

#endif

#endif  // ends header guard

