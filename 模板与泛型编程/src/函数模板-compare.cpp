/*
 * 初步展示了函数模板的实例化过程
*/ 

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout; using std::endl;

#include "compare.h"

int main()
{
    // 实例化int compare(const int&, const int&)
    cout << compare(1, 0) << endl;       // T是int

    // 实例化了int compare(const vector<int>&, const vector<int>&)
    // 之所以是const是因为已经给定了具体的值
    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T是vector<int>

    long l1, l2;
    int i1, i2;
    compare(i1, i2);      // 实例化了compare(int, int)
    compare(l1, l2);      // 实例化了compare(long, long)
	compare<int>(i1, l2); // 使用compare(int, int)
	compare<long>(i1, l2);// 使用compare(long, long)

    const char *cp1 = "hi", *cp2 = "world";
    cout << compare(cp1, cp2) << endl;          // 调用特定版本，这个可以类比函数重载来理解，编译器会优先选择最匹配的参数
    
    // 在这个环节中，C风格字符串会隐式转化为string类型的字符串
    cout << compare<string>(cp1, cp2) << endl;  // 传递参数到string

    return 0;
}

