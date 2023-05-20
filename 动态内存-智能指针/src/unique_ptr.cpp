/* 初步介绍了unique_ptr的使用
// 也了解到了unique_ptr的release用法 
 */
#include <memory>
using std::unique_ptr; using std::shared_ptr;

#include <iostream>
using std::cin, std::cout, std::endl;

void testRelease(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " \n"[i == (n - 1)];
	}
}

int main()
{
	// up points to an array of ten uninitialized ints
	unique_ptr<int[]> up(new int[10]);
	int *p = up.get();	// 临时保存下来这个原始指针以待后续测试
	for (size_t i = 0; i != 10; ++i)
		up[i] = i;  // assign a new value to each of the elements

	// 接下来测试release后原对象是否还存在
	cout << "Before Release: ";
	testRelease(p, 10);	// 对于原始保留的会输出值，因此确实原始对象还存在

	// 更换一种输出方式，以便确认unique_ptr的release函数的返回类型
	int* releasedPtr = up.release();  // 释放up对对象的所有权，并获取原始指针
	cout << "Call release and Output: ";
	testRelease(releasedPtr, 10);  // 一样输出


	delete[] (releasedPtr);

	cout << "After Delete Release: ";
	testRelease(p, 10);	// 不会正常输出值，因为原始空间已被释放
	
	// shared_ptr不直接支持管理动态数组，这一点细节很重要
	// 同时也未定义下标运算符，因此不能通过常规的方式去访问数组中的元素
	shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });	// 传递了一个自行定义的删除器
	// shared_ptrs没有下标运算符
	// and don't support pointer arithmetic
	for (size_t i = 0; i != 10; ++i)
		*(sp.get() + i) = i;  // use get to get a built-in pointer
	sp.reset(); // uses the lambda we supplied 
	            // that uses delete[] to free the array
}
	
