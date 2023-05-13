#include <iostream>

// 只为程序展示使用，使用全局变量以及定义一个与全局变量名称相同的变量是一种很糟糕的用法

int reused = 42;  // 全局变量

int main()
{
	int unique = 0; // unique has block scope

	// 输出全局变量以及main函数内部变量
	std::cout << reused << " " << unique << std::endl;   

	int reused = 0; // 一个新的reused，覆盖了全局变量

	// 输出的是覆盖后的值
	std::cout << reused << " " <<  unique << std::endl;  

	// 输出时指定要调用全局变量中的reused
	std::cout << ::reused << " " <<  unique << std::endl;  

	return 0;
}
