/*
 * 一个简单的函数模板的展示
*/ 

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

// 当我们调用print，编译器将会实例化print的一个版本
// 将T替换为参数的元素类型，将N替换为数组的大小
// 这个用法很不错
template <typename T, size_t N>
void print(T (&arr)[N])
{
    for (auto elem : arr)
        cout << elem << endl;
}

int main()
{
	int a1[] = {0,1,2,3,4,5,6,7,8,9};
	int a2[] = {1,3,5};
	string a3[4];

	print(a1);  // instantiates print(int (&arr)[10])

	print(a2);  // instantiates print(int (&arr)[3])

	print(a3);  // instantiates print(string (&arr)[42])

	return 0;
}
