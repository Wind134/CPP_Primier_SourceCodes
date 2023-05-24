/* 一个头文件，该头文件设置了一个输出单词复数形式的函数 */
#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#ifndef MAKE_PLURAL_H
#define MAKE_PLURAL_H

// 该函数返回复数版本
inline
string make_plural(size_t ctr, const string &word, 
                               const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

#endif
