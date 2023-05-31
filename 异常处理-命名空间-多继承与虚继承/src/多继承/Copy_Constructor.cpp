#include <iostream>

class Base {
public:
    int baseData;

    Base(int data) : baseData(data) {}

    Base(const Base& other) : baseData(other.baseData) {    // 定义自己版本的拷贝构造
        std::cout << "Base Copy Constructor" << std::endl;
    }

    Base& operator=(const Base& other) {
        if (this != &other) {
            baseData = other.baseData;
            std::cout << "Base Assignment Operator" << std::endl;
        }
        return *this;
    }
};

class Derived : public Base {
public:
    int derivedData;

    Derived(int base, int derived) : Base(base), derivedData(derived) {}

    Derived(const Derived& other)
        : Base(other), derivedData(other.derivedData) {        // 必须要在完整的对象上执行拷贝、移动或赋值操作
        std::cout << "Derived Copy Constructor" << std::endl;  // 所谓在完整对象上就是基类派生类部分分别都执行拷贝构造
    }

    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other);
            derivedData = other.derivedData;
            std::cout << "Derived Assignment Operator" << std::endl;
        }
        return *this;
    }
};

int main() {
    Derived d1(10, 20);
    Derived d2 = d1;  // 调用Derived的拷贝构造函数，同时会调用Base的拷贝构造函数

    Derived d3(30, 40);
    d3 = d2;  // 调用Derived的赋值运算符，同时会调用Base的赋值运算符

    return 0;
}
