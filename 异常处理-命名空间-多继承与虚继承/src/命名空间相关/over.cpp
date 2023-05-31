/*
 * 基本是遵循函数调用的法则
*/ 

#include <string>
using std::string;

#include <iostream>

namespace libs_R_us {
    extern void print(int) 	// 全局函数
		{ std::cout << "libs_R_us::print(int)" << std::endl; }
    extern void print(double) 
		{ std::cout << "libs_R_us::print(double)" << std::endl; }
}

// ordinary declaration
void print(const std::string &)
{
	std::cout << "print(const std::string &)" << std::endl;
}

// this using directive adds names to the candidate set for calls to print:
using namespace libs_R_us;  

// the candidates for calls to print at this point in the program are:
//     print(int) from libs_R_us
//     print(double) from libs_R_us
//     print(const std::string &) declared explicitly

int main()
{
	int ival = 42;
    print("Value: "); // 调用本作用域中的print函数
    print(ival);      // 调用libs_R_us::print(int)

	return 0;
}

