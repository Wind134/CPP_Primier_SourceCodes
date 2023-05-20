/* 使用allocator */

#include <string>
using std::string; 

#include <memory>
using std::allocator;

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::cout; using std::endl; 

#include <fstream>
using std::ifstream;

int main() 
{
	const size_t n = 100;
	allocator<string> alloc;      // 可以为string类型对象分配空间的对象
	auto p = alloc.allocate(n);   // 连续分100个
	
	auto q = p; // q和p都指向最后一个构造的元素空间之后的位置，也就是分配的空间的起始位置
	alloc.construct(q++);         // *q为空
	cout << *(q-1) << endl;			// 打印测试(因为自增了，所以-1)			
	
	alloc.construct(q++, 10, 'c'); // *q是cccccccccc，因为该构造函数的意义是10个'c'指代一个string
	cout << *(q - 1) << endl;
	
	alloc.construct(q++, "hi");    // *q is hi!
	cout << *(q - 1) << endl;
	
	cout << *p << endl;  // 空字符串
	while (q != p)
		alloc.destroy(--q);  // 逐个析构
	
	alloc.deallocate(p, n);  // 归还allocate的内存
	
	p = alloc.allocate(n);   // 又分配
	string s;
	q = p;                   // q points to the memory for first string
	ifstream in("../data/storyDataFile");
	while (in >> s && q != p + n)
		alloc.construct(q++, s); // 只构造我们需要的个数
	size_t size = q - p;         // 保存我们读取的个数

	// use the array

	cout << "read " << size << " strings" << endl;
	
	for (q = p + size - 1; q != p; --q)
		alloc.destroy(q);         // 都执行析构
	alloc.deallocate(p, n);       // 归还内存

	in.close();		// 关文件
	in.open("../data/storyDataFile");
	p = new string[n];            // 构造n个空字符串
	q = p;                        // q points to the first string
	while (in >> s && q != p + n)
		*q++ = s;                 // 分配新值给*q
	size = q - p;                 // remember how many strings we read

	cout << "read " << size << " strings" << endl;

	// use the array

	delete[] p;  // p points to an array; must remember to use delete[]
}
