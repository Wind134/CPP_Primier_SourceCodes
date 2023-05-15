/* istream流的状态 */
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <sstream>
using std::istringstream; 

#include <string>
using std::string;

void read()
{
	// 打开fail以及bad以及eof标志位，就是说，当遇到这些错误，cin的输入无效。而现在，把这些标志位都打开了
	cin.setstate(cin.badbit | cin.eofbit | cin.failbit);
}

void off()
{
	// 关闭failbit和badbit以及当前的错误位，其他不变
	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
} 


int main()
{
	cout << "before read" << endl;
	if (cin.good()) cout << "cin's good" << endl;	// 输出
	if (cin.bad()) cout << "cin's bad" << endl;		// 不输出
	if (cin.fail()) cout << "cin's fail" << endl;	// 不输出
	if (cin.eof()) cout << "cin's eof" << endl;		// 不输出
	
	read();		// 执行read函数
	cout << "after read" << endl;
	if (cin.good()) cout << "cin's good" << endl;	// 不输出
	if (cin.bad()) cout << "cin's bad" << endl;		// 输出
	if (cin.fail()) cout << "cin's fail" << endl;	// 输出
	if (cin.eof()) cout << "cin's eof" << endl;		// 输出
	
	off();		// 执行off函数
	cout << "after off" << endl;
	if (cin.good()) cout << "cin's good" << endl;	// 不输出
	if (cin.bad()) cout << "cin's bad" << endl;		// 不输出
	if (cin.fail()) cout << "cin's fail" << endl;	// 不输出
	if (cin.eof()) cout << "cin's eof" << endl;		// 输出
	return 0;
}
