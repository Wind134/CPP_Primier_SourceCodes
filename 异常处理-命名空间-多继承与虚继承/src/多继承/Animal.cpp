/*
 * 一些定义，主要还是针对继承关系的学习
*/ 

#include "Animal.h"
#include <iostream>
using std::ostream; using std::cout; using std::endl;

// 对Panda类的基类的打印
void print(const Bear&) 
{
	cout << "print(const Bear&)" << std::endl;

}
void highlight(const Endangered&)
{
	cout << "highlight(const Endangered&)" << std::endl;
}

ostream& operator<<(ostream &os, const ZooAnimal&)
{
	return os << "ZooAnimal output operator" << endl;
}

int main() {
	Panda ying_yang("ying_yang");	// ying_yang是一个Panda对象
	
	print(ying_yang);     		// Panda是从Bear继承而来，基类部分是Bear
	highlight(ying_yang); 		// Panda也是从Endangered继承而来，基类部分是Endangered
	cout << ying_yang << endl; 	// ZooAnimals重载了运算符，因此输出"ZooAnimal output operator"
	
	// 下面这部分是明显的拷贝构造，我们对这个过程进行分析：
	// 由于最终要退出main函数的作用域，会对ling_ling以及ying_yang执行析构
	// 首先需要释放ling_ling的资源，执行Panda的析构函数；
	// 再去执行它的第二个直接基类Endangered的析构函数；
	// 再去执行第一个直接基类Bear的析构函数
	// 由于Bear又是继承而来，因此还需要去执行Bear的直接基类ZooAnimals的析构函数
	// ying_yang同理
	Panda ling_ling = ying_yang;

	return 0;
}
