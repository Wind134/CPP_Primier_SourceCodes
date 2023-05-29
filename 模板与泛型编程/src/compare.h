/*
 * 针对compare函数模板的定义
*/ 

#ifndef COMPARE_H
#define COMPARE_H
#include <cstring>

// 实现类strcmp-like的通用比较函数 
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <> 
inline
int compare(const int& i1, const int& i2)
{
    if (i1 < i2) return -1;
    if (i2 < i1) return 1;
    return 0;
}

// 针对C风格字符串定义的特定参数类型的版本
// 注意这个参数，是对一个指向常量字符指针的引用，const char* const即为一个指向常量字符的指针
template <>
inline
int compare(const char* const &v1, const char* const &v2)
{
    return std::strcmp(v1, v2);
}

#endif
