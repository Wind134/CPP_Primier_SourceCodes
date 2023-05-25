/*
 * 
*/ 

#include <iostream>
using std::cout; using std::endl;

class Base {    // 基类，定义了一个虚函数
public:
    virtual int fcn();
};

int Base::fcn() { cout << "Base::fcn()" << endl; return 0; }    // 基类针对该函数的实现，表明对基类中fcn函数的调用

class D1 : public Base {    // 派生类D1，public代表是公共方式继承，是继承列表中的一个访问说明符
public:
    // 隐藏了基类中的fcn; 该fcn并非虚函数
    // 但D1也会继承Base::fcn()中的定义 
    int fcn(int);      // 因为参数列表不同
	virtual void f2(); // 新的虚函数，返回类型不同
};

int D1::fcn(int) { cout << "D1::fcn(int)" << endl; return 0; }  // 定义fcn(int)
void D1::f2() { cout << "D1::f2()" << endl; }   // 定义f2()

class D2 final : public D1 {    // D2不能再被继承了
public:
    int fcn(int); // 非虚函数，隐藏了D1::fcn(int)
    int fcn();    // 覆盖了基类中的虚函数fcn
	void f2();    // 覆盖了D1中的虚函数f2
};

int D2::fcn(int) { cout << "D2::fcn(int)" << endl; return 0; }  // 实现
int D2::fcn() { cout << "D2::fcn()" << endl; return 0; }    // 实现
void D2::f2() { cout << "D2::f2()" << endl; }      // 实现

int main()
{
    D1 dobj, *dp = &dobj;
    dp->fcn(42); // 静态调用D1::fcn(int)

    Base bobj;  D1 d1obj; D2 d2obj;

    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn(); // 动态调用, 运行时调用Base::fcn
    bp2->fcn(); // 动态调用, 由于D1没有对继承而来的虚函数进行覆盖，因此只能是隐式继承Base的虚函数，因此运行时调用Base::fcn
    bp3->fcn(); // 动态调用, D2对虚函数进行了重新定义，运行时调用D2::fcn

	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
    // D1、D2针对虚函数f2有各自的定义，D2的虚函数对D1进行了覆盖，因此会进行动态绑定
	d1p->f2(); // 动态调用, 运行时调用D1::f2()
	d2p->f2(); // 动态调用, 运行时调用D2::f2()
	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 =  &d2obj;
    // fcn(int)本身非虚函数，基类派生类各自都有定义，因此执行静态绑定
	p2->fcn(42);  // 静态绑定, calls D1::fcn(int)
	p3->fcn(42);  // 静态绑定, calls D2::fcn(int)

    Base* bp = &d1obj; D1 *dp1 = &d2obj; D2 *dp2 = &d2obj;
    // 同上
    dp1->fcn(10); // 静态调用D1::fcn(int)
    dp2->fcn(10); // 静态调用D2::fcn(int)
}

