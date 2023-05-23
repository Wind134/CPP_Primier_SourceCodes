/* 详细介绍了函数对象类的使用 */

#include <algorithm>
using std::for_each;

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream; using std::ostream;

#include <string>
using std::string; 

#include <vector>
using std::vector;

class PrintString {	// 可调用对象的使用
public:
    PrintString(ostream &o = cout, char c = ' '): 
		os(o), sep(c) { }
    void operator()(const string &s) const { os << s << sep; }
private:
    ostream &os;   // stream on which to write
	char sep;      // character to print after each output
};

class ReadLine {	// 专门用来读取某行的类
public:
	ReadLine() = delete;
	ReadLine(istream &i) : is(i) { }	// 构造函数，参数为一个流对象的引用

	// 下面这行不加强制转换可能会报错
	bool operator()(string &s) const { return static_cast<bool>(getline(is, s)); }
private:
	istream &is;
};

int main()
{
	vector<string> vs;
	ReadLine rl(cin);    // rl绑定了输入流cin
	string s;
	while (rl(s))        // 读取输入s的时候按行读取
		vs.push_back(s);	// 每一行添加进vs，对于s而言，一行才是一个string

	cout << "read : " << vs.size() << " elements" << endl;	// 输出2
	cout << "Now, s.size() = : " << s.size() << endl;	// 输出0
	PrintString printer;   // uses the defaults; prints to cout 
	printer(s);            // prints s followed by a space on cout

	PrintString errors(cerr, '\n');
	errors(s);             // prints s followed by a newline on cerr

	cerr << "for_each printing to cerr" << endl;
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
}

