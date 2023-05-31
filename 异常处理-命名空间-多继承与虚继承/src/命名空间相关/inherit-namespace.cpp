/*
 * 展示了namespace命名空间的使用以及类的继承
*/ 

#include <iostream>

namespace NS {
    class Quote { 
	public:
		Quote() { std::cout << "Quote::Quote" << std::endl; } 
	};
    void display(const Quote&) 
		{ std::cout << "display(const Quote&)" << std::endl; }
}

// Bulk_item's base class is declared in namespace NS
class Bulk_item : public NS::Quote { 
public:
	Bulk_item() { std::cout << "Bulk_item::Bulk_item" << std::endl; }
};

int main() {
    Bulk_item book1;    // 先调用了基类中的构造，再调用派生类中的构造，因此会打印两部分东西

    display(book1); // 调用Quote::display，因为Bulk_item并未自行定义display

    return 0;
}

