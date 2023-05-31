/*
 * namespace的初步介绍
*/ 

#include <iostream>
using std::cout; using std::endl;

// namespace A and function f are defined at global scope
namespace A {
    int i = 0, j = 42;
}

void f() 
{
    using namespace A; // injects the names from A into the global scope

	// uses i and j from namespace A
    cout << "i: " << i << " j: " << A::j << endl;
}

namespace blip {
    int i = 16, j = 15, k = 23;
	void f() 
		{ cout << "i: " << i << " j: " << j << " k: " << k << endl; }
}

int j = 0;  // ok: 这个是main函数作用域之外所定义的j

int main() 
{
    // using directive; 
	// the names in blip are ``added'' to the global scope
    using namespace blip; // clash between ::j and blip::j
                          // detected only if j is used

    ++i;        // sets blip::i to 17
    ++::j;      // ok: sets global j to 1
    ++blip::j;  // ok: sets blip::j to 16

    int k = 97; // 本地的k隐藏了blip::k
    ++k;        // sets local k to 98

	::f();      // 调用全局作用域中的f(),而f的作用域又包含了A命名空间，也就是说，只调用A部分的i，j  
	blip::f();
	cout << "j: " << ::j << " k: " << k << endl; 

	return 0;
}
