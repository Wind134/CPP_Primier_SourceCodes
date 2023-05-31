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
