/*
 * exception的使用
*/ 

#include <iostream>
using std::cout; using std::endl;

#include <exception>
using std::exception;

// 下面这个函数还是会compile, 即使它明显违反了其异常规范
void f() noexcept       // 承诺不会抛出异常
{
    throw exception();  // 但又抛出了异常
}

void g() { }
void h() noexcept(noexcept(f())) { f(); }
void i() noexcept(noexcept(g())) { g(); }
int main()
{
    try {
		cout << "f: " << std::boolalpha << noexcept(f()) << endl;
		cout << "g: " << std::boolalpha << noexcept(g()) << endl;
		cout << "h: " << std::boolalpha << noexcept(h()) << endl;
		cout << "i: " << std::boolalpha << noexcept(i()) << endl;
        f();
    } catch (exception &e) {
        cout << "caught " << e.what() << endl;
    }
	
	return 0;
}
