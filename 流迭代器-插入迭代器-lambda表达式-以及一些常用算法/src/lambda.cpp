/* lambda传参数方式的详细介绍 */
#include <vector>
#include <string>
#include <iostream>
using std::cout; using std::endl; using std::vector; using std::string;

// 传值->捕获列表
void fcn1()
{
	size_t v1 = 42;  // local variable
	// copies v1 into the callable object named f
	auto f = [v1] { return v1; };
	v1 = 0;
	auto j = f(); // j仍然是42; 因为是传值，是一个复制的过程
	cout << j << endl;
}

// 传引用->捕获列表
void fcn2()
{
	size_t v1 = 42;  // local variable
	// the object f2 contains a reference to v1 
	auto f2 = [&v1] { return v1; };
	v1 = 0;
	auto j = f2(); // j是0; f2是v1的引用;
	cout << j << endl;
}

void fcn3()
{
	size_t v1 = 42;  // local variable
	// f can change the value of the variables it captures
	auto f = [v1] () mutable { return ++v1; };	// lambda函数体一般不改变内容，要改变则加mutable关键字
	v1 = 0;
	auto j = f(); // 依旧是传值，j输出43，f加上()则是一个调用的形式
	cout << j << endl;
}

void fcn4()
{
	size_t v1 = 42;  // local variable
	// v1 is a reference to a nonconst variable
	// we can change that variable through the reference inside f2
	auto f2 = [&v1] { return ++v1; };	// 这里的f2()是43
	v1 = 0;		// 重新赋值
	auto j = f2(); // 仍然是对v1的引用，因此返回的应该是1
	cout << j << endl;
}

void fcn5()
{
    size_t v1 = 42;
	// p is a const pointer to v1
    size_t* const p = &v1;
	// increments v1, the objet to which p points
    auto f = [p]() { return ++*p; };
    auto j = f();  // 通过指针改变值
    cout << v1 << " " << j << endl; // prints 43 43
    v1 = 0;
    j = f();       // 仍然是通过指针，但此时*p变为0，因此返回1
    cout << v1 << " " << j << endl; // prints 1 1
}


int main()
{
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	fcn5();
	return 0;
}
