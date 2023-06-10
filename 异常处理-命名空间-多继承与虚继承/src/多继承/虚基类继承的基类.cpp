/* 还是会先执行虚基类继承的那个基类的构造函数 */
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
};

class VirtualBase : public Base {
public:
    VirtualBase() {
        std::cout << "VirtualBase constructor" << std::endl;
    }
};

class Derived : public virtual VirtualBase {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
    }
};

int main() {
    Derived d;
    return 0;
}
