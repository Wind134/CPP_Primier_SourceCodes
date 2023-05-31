/*
 * 
*/ 

#include <iostream>
using std::cout; using std::endl;

namespace primerLib {	// primerLib命名空间中定义的函数
    void compute() { cout << "primerLib::compute()" << endl; }
    void compute(const void *)	// 参数可以是任意类型的指针，因此设置为void类型 
	   { cout << "primerLib::compute(const void *)" << endl; }
}

// 把comput() and compute(const void*)都带进去了本作用域
using primerLib::compute;

void compute(int) { cout << "compute(int)" << endl; }
void compute(double, double = 3.4)
	   { cout << "compute(double, double)" << endl; }
void compute(char*, char* = 0)
         { cout << "compute(char*, char*)" << endl; }

int main()
{
	int i = 42;
	char c = 'a';
	compute(i);  // 容易理解
	compute(c);  // compute(int)，char->int可以经过隐式转换成功进行，
	compute(&i); // primerLib::compute(const void*)，容易理解，void* 表明可以是任意指针类型
	compute(&c); // compute(char*, char*)，容易理解，因为第二个参数给定了默认
	compute(3.4);// compute(double, double)，容易理解，因为第二个参数给定了默认
	
	return 0;
}
