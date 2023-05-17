/* 介绍了iostream_iter用法 */
#include <algorithm>
using std::copy; using std::sort; using std::unique_copy;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <fstream>
using std::ofstream;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    istream_iterator<int> int_it(cin); // reads ints from cin
    istream_iterator<int> int_eof;     // end iterator value
	vector<int> v(int_it, int_eof);    // 通过读取cin缓冲区初始化vector数组v

    sort(v.begin(), v.end());
    ostream_iterator<int> out(cout, " "); // write ints to cout，初始cout应该为空
    unique_copy(v.begin(), v.end(), out); // write unique elements to cout(去除了重复)
    cout << endl;                         // write a newline after the output
	ofstream out_file("../data/outFile2");   // writes int to named file
	ostream_iterator<int> out_iter(out_file, " ");
	copy(v.begin(), v.end(), out_iter); 
	out_file << endl;  // 写入换行
    return 0;
}
