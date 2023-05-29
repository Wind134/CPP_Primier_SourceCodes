/*
 * 向我们展示，实例化的过程必须包括具体的类型定义
*/ 

#include "Blob.h"
#include "compare.h"

#include <string>
using std::string;

// 实例化对于每一个类型和函数以及其他声明为extern的文件必须提供一个(nonextern)的定义
template int compare(const int&, const int&);
template class Blob<string>; // 实例化类模板的所有成员 
template class Blob<int>;    // 实例化Blob<int>
