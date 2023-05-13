#include <iostream>
using std::cout; using std::endl;

int main()
{
	int a = 0;
	decltype(a) c = a;   // 推断a的类型，当作c的类型
	decltype((a)) d = a; // (a)变成了一个左值引用，因此推断出int&类型
	++c;                 // increments c, a (and d) unchanged
	cout << "a: " << a << " c: " << c << " d: " << d << endl;
	++d;                 // increments a through the reference d
	cout << "a: " << a << " c: " << c << " d: " << d << endl;
	
	int A = 0, B = 0;
	decltype((A)) C = A;   // C is a reference to A
	decltype(A = B) D = A; // A = B推断出的类型是A&
	++C;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;
	++D;
	cout << "A: " << A << " C: " << C << " D: " << D << endl;
	
	return 0;
}
