/* 介绍了istream_iterator */
#include <numeric>
using std::accumulate;

#include <iterator>
using std::istream_iterator;	// C++标准库中的迭代器类型之一，用于从输入流(例如标准输入、文件流)中读取数据。

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	istream_iterator<int> in(cin), eof;	// eof为空，in指的是输入缓冲区的起始点
	cout << accumulate(in, eof, 0) << endl;
	return 0;
}
