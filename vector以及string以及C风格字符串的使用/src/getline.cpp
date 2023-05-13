#include <string> 
using std::string; using std::getline;

#include <iostream> 
using std::cin; using std::cout; using std::endl;

int main() 
{
	string line;

	// read input a line at a time until end-of-file
	while (getline(cin, line))	// 以行为单位获取输入流，也会读取行尾的'\n'换行符
		cout << line << endl;

	return 0;
}
