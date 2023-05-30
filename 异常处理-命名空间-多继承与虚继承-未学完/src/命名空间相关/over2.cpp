/*
 * 使用命名空间的 using 指令可以从不同的命名空间中创建一个函数的重载集合。
*/ 

#include <iostream>

namespace AW {
    int print(int i) 
		{ std::cout << "AW::print(int)" << std::endl; return i; }
}
namespace Primer {
    double print(double d) 
		{ std::cout << "Primer::print(double)" << std::endl; return d; }
}

// 使用命名空间的 using 指令可以从不同的命名空间中创建一个函数的重载集合。
using namespace AW;
using namespace Primer;

long double print(long double);

int main() {
    print(1);   // calls AW::print(int)
    print(3.1); // calls Primer::print(double)

    return 0;
}

