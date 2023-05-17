/* 讲述了逆向迭代器的使用 */
#include <algorithm>
using std::copy; using std::sort;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> vec;
	istream_iterator<int> in(cin), eof;
	copy (in, eof, back_inserter(vec));

	sort(vec.begin(), vec.end()); // sorts vec in ``normal'' order
	vector<int> vec2(vec);        // 拷贝初始化

	// sorts in reverse: puts the smallest element at the end of vec
	sort(vec.rbegin(), vec.rend());

	// prints vec
	ostream_iterator<int> out(cout, " ");
	cout << "vec: ";
	copy(vec.begin(), vec.end(), out);    // 发现了吗？copy函数是交给了一个迭代器位置
	cout << endl;

	// prints vec2
	cout << "vec2: ";
	copy(vec2.begin(), vec2.end(), out);  // forward sort
	cout << endl;

	// it refers to the first element in vec
	auto it = vec.begin();

	// rev_it refers one before the first element in vec
	vector<int>::reverse_iterator rev_it(it);	// 逆向迭代器指向的是其构造所用的正向迭代器所指向元素的前一个位置
	cout << *(rev_it.base()) << endl; // base获取所指向的原始迭代器，打印第一个元素
	
	// ways to print value at beginning of vec through it and rev_it
	cout << *it << endl;	// 第一个元素
	cout << *(rev_it.base()) << endl;  
	cout << *(rev_it - 2) << endl;

	return 0;
}
		
