/* 介绍了参数绑定的使用，以及文件流IO流的使用 */
#include <algorithm>
using std::for_each;

#include <functional>
using std::bind; using namespace std::placeholders;	// placeholders的使用
using std::ref;	// 引用

#include <iterator>
using std::istream_iterator;

#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream; 

#include <fstream>
using std::ifstream; using std::ofstream; 

ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}

int main()
{
	string s;
	vector<string> words;
	while (cin >> s)
		words.push_back(s);

	for_each(words.begin(), words.end(), 
	         bind(print, ref(cout), _1, ' '));	// 打印到标准输出流cout
	cout << endl;

	ofstream os("../data/outFile1");	
	for_each(words.begin(), words.end(), 
	         bind(print, ref(os), _1, ' '));	// 输出到文件流中去，具体就是文件会填充一段内容
	os << endl;

	ifstream is("../data/outFile1");
	istream_iterator<string> in(is), eof;
	for_each(in, eof, bind(print, ref(cout), _1, '\n'));	// 将文件中的信息打印到标准输出流cout
	cout << endl;

	return 0;
}
