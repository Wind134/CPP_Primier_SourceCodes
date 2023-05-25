/*
 * 展示了作用域
 * 以及当派生类中有一个同样的变量时
 * 会覆盖掉基类中的那个变量
 * 除非我们主动调用
*/ 

#include <iostream>
using std::cout; using std::endl;

struct Base {
    Base(): mem(0) { }
protected:
    int mem;    // 派生类可访问
};

struct Derived : Base {
    Derived(int i): mem(i) { } // 初始化Derived::mem为i
	                           // Base::mem会执行默认初始化
    int get_mem() { return mem; }  // 默认返回自身的
    int get_base_mem() { return Base::mem; }
	// . . .
protected:
    int mem;   // 隐藏了基类中的mem
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl;       // 打印 42
    cout << d.get_base_mem() << endl;  // 打印 0
}

