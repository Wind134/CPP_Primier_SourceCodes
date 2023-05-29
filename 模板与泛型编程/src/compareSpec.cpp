/*
 * 函数模板的特例化应用案例
*/ 

#include <iostream>
using std::cout; using std::endl;

#include <functional>
using std::less;

#include <cstring>
using std::strcmp;

// 指针非指针都可以进行比较
template <typename T> int compare(const T &v1, const T &v2)
{
	cout << "compare(T)" << "\t";

	if (less<T>()(v1, v2)) return -1;
	if (less<T>()(v2, v1)) return 1;

	return 0;
}

template<unsigned N, unsigned M> 
int compare(const char (&p1)[N], const char (&p2)[M])
{
	cout << "compare(const char arrays)" << "\t";

	return strcmp(p1, p2);
}

template<> 
int compare(const char *const& p1, const char *const& p2)
{
	cout << "compare(const char* const)" << "\t";

	return strcmp(p1, p2);
}

int main()
{
	int *p1 = new int(45);
	int *p2 = new int(42);

	// 由于我们所比较的是指针值, 调用的结果随着
    // 每一次程序的运行会发生变化
	// 实例化出来的是T类型
	cout << compare(*p1, *p2) << endl;

	// 下面这个实例化出来的T是int*类型
	cout << compare(p1, p2) << endl;

	cout << strcmp("hi", "mom") << endl;
	cout << compare("hi", "mom") << endl;

	const char *cp1 = "hi", *cp2= "mom";
	cout << compare(cp1, cp2) << endl;
	
	return 0;
}
