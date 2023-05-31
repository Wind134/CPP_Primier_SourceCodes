/*
 * 虚继承的使用，以及析构函数的执行顺序展示
*/ 

#include "Animal_virtual_baseVers.h"
#include <iostream>
using std::cout; using std::endl; using std::ostream;

void dance(const Bear&) 
	{ cout << "dance(const Bear&)" << endl; }

void rummage(const Raccoon&) 
	{ cout << "rummage(const Raccoon&)" << endl; }

ostream& operator<<(ostream&, const ZooAnimal&) 
	{ return cout << "ZooAnimal output operator" << endl; }

int main ()
{
	Panda ying_yang;
	dance(ying_yang);   // 虚继承不影响派生类向基类的转换，因此会正常执行dance函数 
	rummage(ying_yang); // 同上

	cout << ying_yang;  // Panda->ZooAnimals，同样不影响转换机制

	return 0;


	// 退出括号之后要执行析构，先执行Panda自身的析构函数，但是Panda用的是合成的版本
	// 而后对其继承的基类的处理，则是与构造函数的顺序相反，先执行派生类列表中最后一个基类Endangered的析构
	// 执行Raccoon的析构，但是Raccon用的是合成的版本，因此没输出
	// 执行Bear的析构
	// 最后执行ZooAnimal的析构
}
