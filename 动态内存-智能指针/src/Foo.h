
#ifndef FOO_H	// 如果没定义FOO_H，则不定义
#define FOO_H

#include <iostream>

typedef int T;	// int->T
struct Foo {  // 成员默认都是public的
	Foo(T t): val(t) { }
	T val;
};

std::ostream&
print(std::ostream &os, const Foo &f) 
{
	os << f.val;	// 输出val值
	return os;
}

#endif
