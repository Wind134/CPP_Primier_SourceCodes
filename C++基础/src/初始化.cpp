#include "Sales_item.h"
#include <iostream>
#include <string>


int main() {

	int v1(1024);    // 函数形式的直接初始化
	int v2{1024};    // 初始化列表形式的直接初始化
	int v3 = 1024;   // 拷贝初始化
	int v4 = {1024}; // 初始化列表形式的拷贝初始化


	// 通过字符串文本初始化字符串
	std::string titleA = "C++ Primer, 5th Ed.";
	std::string titleB("C++ Primer, 5th Ed.");
	std::string all_nines(10, '9');  // all_nines = "9999999999"

	return 0;
}
