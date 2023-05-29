/*
 * 可变参数模板的扩充
*/ 

#include <iostream>
using std::cout; using std::endl;

template <typename T>
T accum(const T &t)
{
	return t;
}

template <typename T, typename... Args>		// 模板参数包
T accum(const T &t, Args... args)			// 函数参数包
{
	return t + accum(args...);
}

// 可变参数初始值为42？
int h()
{
	return 42;
}

template <typename ...Args> int h(int t, Args ... args)
{
	return t + h(args...); // sum of all the values in args plus 42
}

// produces the sum of up to 4 integral values
void f(int i, int j = 0, int k = 0, int l = 0)
{
	cout << i << " + " 
	     << j << " + " 
	     << k << " + " 
	     << l << " =  "  
	     << i + j + k + l << endl;
}

// expansion: applies the pattern to each member of the pack
//            using a separator appropriate to the context
template<typename ... Args> void g(Args ... args) {
	cout << sizeof...(Args) << endl;  // 模板参数包的个数
	cout << sizeof...(args) << endl;  // 函数参数包的个数
	// call f passing it the arguments from args
	f(args...);                // f(a1, a2, a3, ..., an)

	// call h passing it the arguments from args
	cout << h(args...) << endl; // 从42开始加，42+1+2+3+4 = 52

	// 函数调用模式是h(x), 
	// 每个参数当h的参数，h的结果又是f的参数
	f(h(args) ...);            // f(h(a1), h(a2), h(a3), ..., h(an))-h(a1) = 42 + 1，h(a2) = 42 + 2，...->f(43 + 44 + 45 + 46)

	// h(1,2,3,4)->42+1+2+3+4 = 52, f(52, 0, 0, 0)->有默认值
	f(h(args ...));            // f(h(a1, a2, a3, ..., an2)

	f(h(5,6,7,8 ) + args ...); // f(h(5,6,7,8) + a1, h(5,6,7,8) + a2,
	                           //   h(5,6,7,8) + a3, ..., h(5,6,7,8) + an)
}

int main()
{
	cout << accum(1,2,3,4) << endl;

	g(1,2,3,4);

	return 0;
}
