/* 指针的高阶应用：指向数组的指针以及函数指针 */
#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

// code to illustrate declarations of array-related types
int arr[10];          // arr is an array of ten ints
int *p1[10];          // 定义了一个指针数组——>(int *p1)[10]

// 如下定义了一个指向大小为10的数组的指针——(*p2)<=>(arr)
// 而arr又是一个数组，因此p2就是指向数组的那个指针，这么理解就对了
int (*p2)[10] = &arr; 

using arrT = int[10]; // arrT是一个别名，该别名等价于一个大小为10的整型数组

// 其他的三个方式：定义一个指向大小为10的数组的指针
arrT* func(int i);               // arrT是一个类型，很好理解，func返回的就是一个指向arrT的指针
auto func(int i) -> int(*)[10];  // 使用尾置返回类型，表明func的返回类型是(int(*)[10])类型
int (*func(int i))[10];          // func(int i)返回的是一个指针，指针指向array，即函数指针

auto func2(int i) -> int(&)[10]; // 尾置返回类型，返回的不是指针而是引用

// two arrays
int odd[] = {1,3,5,7,9};		// 数组odd，odd是一个指针
int even[] = {0,2,4,6,8};		// 数组even，even是一个指针

// 函数返回一个指针，该指针根据i的值来判断指向，是指向odd还是even
int *elemPtr(int i)
{
	// 返回的指针指向的是数组的第一个元素
	return (i % 2) ? odd : even;  
}
	
// 这里返回的指针指向的是数组本身，切记
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even; // 返回一个指向数组的指针
}

// 返回的是一个数组的引用
int (&arrRef(int i))[5]
{
	return (i % 2) ? odd : even;
}

void test(int a[])	// 测试下数组名指针的地址与指向数组的指针
{
	cout << "Address of the 1th array elements: " << a << endl
	<< "Address of the whole array: " << &a << endl;
}

int main()
{
	int *p = elemPtr(6);         // p指向数组的第一个元素
	int (*arrP)[5] = arrPtr(5);  // arrP指向大小为5的那个数组
	int (&arrR)[5] = arrRef(4);  // arrR是一个引用

	int a[] = {1, 2, 3};
	for (size_t i = 0; i < 5; ++i)
		// p points to an element in an array, which we subscript
		cout << p[i] << " \n"[i == 4];  

	for (size_t i = 0; i < 5; ++i)
		// 指针下的写法
		// we must dereference the pointer to get the array itself
		cout << (*arrP)[i] << " \n"[i == 4];

	for (size_t i = 0; i < 5; ++i)
		// 引用下的写法
		cout << arrR[i] << " \n"[i == 4];

	test(a);	

	return 0;
}
