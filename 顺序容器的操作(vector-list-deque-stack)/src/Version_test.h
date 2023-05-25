/* 这是一个版本测试的头文件 */
#ifndef VERSION_TEST_H
#define VERSION_TEST_H


/* C++ Primer, 5th Edition (July 2012)第一次出版时, 
 * 4.7.0版本的gcc还不支持一些C++ 11的新特性  
 *
 * 我们分发的代码包含了普通的C++代码和对缺失特性的解决方案
 * 我们使用预处理器变量来确定一个给定版本的编译器是否实现了某个特性。 
 * 我们在书中测试代码时使用的基准版本是gcc4.7.0版本
 *
 * 当有新的版本可用时，我们将更新这个文件，其中会定义在该版本中实现的特性。
*/

#if __cplusplus >= 201103L 	// 检查环境是否是C++11以上的版本，若是，则会定义下列宏
// 基线版本, 将来的版本会将这些变量定义为已实现的特性。

/* 这个发布中的代码使用以下变量来控制编译

   Variable tests           C++ 11 Feature 
HEX_MANIPS               hexfloat and defaultfloat manipulators
REFMEMS                  reference qualified member functions
REGEX                    regular expressions library
STRING_NUMERIC_CONVS     conversions to and from string to numeric
*/

#define HEX_MANIPS
#define REFMEMS
#define REGEX
#define STRING_NUMERIC_CONVS
#endif  // 编译器版本检查结束

#ifndef STRING_NUMERIC_CONVS
// 如果库没有定义to_string 
// 或者没有数值转换函数
// 我们就会定义这些

// 读者可以忽略to_string和stod的实现 
// 但是要会在代码中使用这些函数

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>
// 我们使用stdio中的sprintf来实现to_string
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

#endif  // ends header guard

