/* str中的substr */
#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <stdexcept>
using std::out_of_range;

int main()
{
	try {
		string s("hello world");
		// 都是下标，[s[0], s[5])的这么一个范围
		cout << s.substr(0, 5) << endl;  // prints hello
		// 仅有一个参数，代表[s[6], s.size())的这么一个范围
		cout << s.substr(6) << endl;     // prints world
		// 像第一个示例，指定了范围
		cout << s.substr(6, 11) << endl; // prints world
		// 出错了，越界了
		cout << s.substr(12) << endl;    // throws out_of_range 
	} catch(out_of_range) {cout << "caught out_of_range" << endl; }

	return 0;
}
