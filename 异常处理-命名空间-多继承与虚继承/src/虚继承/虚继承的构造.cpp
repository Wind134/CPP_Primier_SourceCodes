/* 这个例子很奇怪，为什么Base会构造两次，这不合理，因为Base已经成为了虚继承了
 * 但不同在于又有一个类以非虚继承的方式执行了，这样会有什么影响
 * 查询了资料：
 * 当一个类以虚继承的方式继承了一个基类，而另一个类以非虚继承的方式继承相同的基类时，会导致两个派生类中存在两个独立的子对象，一个来自虚继承，一个来自非虚继承。

 * 具体影响如下：
 * 虚继承的派生类会包含一个指向虚基类子对象的指针或偏移量。而非虚继承的派生类不会包含这样的指针或偏移量。
 * 虚继承的派生类的构造函数会调用虚基类的构造函数，确保虚基类只被构造一次。非虚继承的派生类的构造函数只负责构造自己的直接基类。
 * 虚继承的派生类的析构函数会调用虚基类的析构函数，确保虚基类只被析构一次。非虚继承的派生类的析构函数只负责析构自己的直接基类。
 * 虚继承的派生类在访问虚基类成员时需要使用作用域解析运算符（::）来指明成员所属的基类。非虚继承的派生类可以直接访问自己的直接基类成员。
 */
#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }
};

class VirtualDerived : public virtual Base {
public:
    VirtualDerived() {
        std::cout << "VirtualDerived constructor" << std::endl;
    }
};

class NonVirtualDerived : public Base {
public:
    NonVirtualDerived() {
        std::cout << "NonVirtualDerived constructor" << std::endl;
    }
};

class FinalDerived : public VirtualDerived, public NonVirtualDerived {
public:
    FinalDerived() {
        std::cout << "FinalDerived constructor" << std::endl;
    }
};

int main() {
    FinalDerived obj;
    return 0;
}
