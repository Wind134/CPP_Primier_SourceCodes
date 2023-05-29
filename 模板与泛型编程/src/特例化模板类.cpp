/*
 * 通过这个例子学习对特例化类模板的定义
 * 先定义好一般模板类
 * 再去定义特例化模板类
 * 同时学习到extern关键字
*/ 

#include "compare.h"
#include "Blob.h"

#include <string>
using std::string;


// 模板类一定得先实例化
// 声明为extern，可以在其他文件中使用这个变量
extern template class Blob<string>;  
extern template int compare(const int&, const int&);

int main() {

	Blob<string> sa1, sa2; // instantiation will appear elsewhere

	// Blob<int> and its initializer_list constructor 
	// are instantiated in this file
	Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9}; 
	Blob<int> a2(a1);  // copy constructor instantiated in this file

	int i = compare(a1[0], a2[0]); // instantiation will appear elsewhere

	std::cout << i << std::endl;
	return 0;
}
