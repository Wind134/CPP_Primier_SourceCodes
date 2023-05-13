#include <cstddef>
using std::size_t;

#include <cassert>
// assert是一个预处理宏，不需要std
// 因此我们需要包含cassert头文件
// 但不需要使用using声明

#include <string> 
using std::string;

#include <iostream> 
using std::endl; using std::cerr; using std::cin;

#include <cstddef>
using std::size_t;

void print(const int ia[], size_t size)
{
#ifndef NDEBUG  // 如果没有定义过NDEBUG，则定义一个NDEBUG
// __func__ 是一个由编译器定义的本地静态变量，代表了当前所在的函数名
cerr << __func__ << ": array size is " << size << endl;
#endif
// . . .
}

int main()
{
    string word = "foo";
    const string::size_type threshold = 5;  // 定义了一个阈值
    if (word.size() < threshold) 
        cerr << "Error: " << __FILE__       // 预定义的源文件名
             << " : in function " << __func__ 
             << " at line " << __LINE__ << endl
             << "       Compiled on " << __DATE__   // 代表此时系统日期
             << " at " << __TIME__ << endl          // 代表系统时间
             << "       Word read was \"" << word 
             << "\":  Length too short" << endl;
    word = "something longer than five chars";
    assert(word.size() > threshold);

    return 0;
}
