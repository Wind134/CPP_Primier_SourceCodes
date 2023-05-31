/*
 * exception的使用
*/ 

#include <iostream>
using std::cout; using std::endl;

#include <exception>
using std::exception, std::logic_error;

// 下面这个函数还是会compile, 即使它明显违反了其异常规范
void f() noexcept       // 承诺不会抛出异常
{
    try {
        throw exception();  // 抛出异常，当没有提供任何参数时，throw也默认会抛出一个名为std::exception的异常对象。
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
}

void g() { }    // 可能存在异常
void h() noexcept(noexcept(f())) { f(); }   // h与f的状态保持一致，因此h()应该也是noexcept的
void i() noexcept(noexcept(g())) { g(); }   // i与g的状态保持一致，因此i()应该不是noexcept的
int main()
{
    try {
		cout << "f: " << std::boolalpha << noexcept(f()) << endl;   // boolalpha代表输出true/false而非1/0，输出ture
		cout << "g: " << std::boolalpha << noexcept(g()) << endl;   // 输出false
		cout << "h: " << std::boolalpha << noexcept(h()) << endl;   // true
		cout << "i: " << std::boolalpha << noexcept(i()) << endl;   // false
        f();
        // 由于f中的函数抛出了异常，因此应该会被catch捕捉，即进入到catch子句
        // 但是throw exception()会直接调用terminate，会直接让程序结束
        // 因此catch部分又不会被执行到
        throw logic_error("try and catch test");    // 加上这行，下面的catch子句就能合理被捕捉了
    } catch (exception &e) {
        cout << "caught " << e.what() << endl;
    }
	
	return 0;
}
