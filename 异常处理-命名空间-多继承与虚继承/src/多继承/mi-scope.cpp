/*
 * 展示了一个简单的多继承的案例
*/ 

#include <string>
#include <vector>
#include <iostream>

struct Base1 {
    void print(int) const     // struct默认是public的，非虚函数
		{ std::cout << "Base1::print(int) " << ival << std::endl; }
protected:
    int ival = 1;
};

struct Base2 {
    void print(double) const
		{ std::cout << "Base2::print(double) " << ival << std::endl; }
protected:
    int ival = 2;
};

struct Derived : public Base1 {
    void print(std::string) const
		{ std::cout << "Derived::print(string) " << ival << std::endl; }
protected:
	int ival = 3;
};

struct MI : public Derived, public Base2 {
    void print(std::vector<double>)
		{ std::cout << "MI::print(int(vector<double>) " 
			        << ival << std::endl; }
protected:
    int ival = 4;
};

int main()
{
	// 明确到MI继承自Derived以及Base2，而Derived又继承自Base1，因此MI是可以调动到Base1的，这个可以理解
	// 因为派生类的派生类会同样继承它继承的派生类的基类部分
	MI obj;
	obj.Base1::print(0);	// 指定调用Base1的print函数
	obj.Base2::print(3.14);	// 指定调用Base2的print函数
	obj.Derived::print("hi");	// 指定调用Derived的print函数
	obj.print(std::vector<double>());	// 调用自身的print函数
	
	return 0;
}
