/* 介绍了find，find_first_of， find_first_not_of的用法 */
#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

int main() 
{
	string numbers("0123456789"), name("r2d2");
	// find_first_of函数返回numbers字符集中任何一个字符首次出现在name字符串中的位置
	auto pos = name.find_first_of(numbers);  
	if (pos != string::npos)
		cout << "found number at index: " << pos 	// 这里就会打印出上面的信息来
		     << " element is " << name[pos] << endl;
	else
		cout << "no number in: " << name << endl;
	
	pos = 0;  // 重新定义pos
	// each iteration finds the next number in name
	while ((pos = name.find_first_of(numbers, pos))	// 在这里pos代表numbers中的起始位置
	              != string::npos) {
	    cout << "found number at index: " << pos 
	         << " element is " << name[pos] << endl;
	
	    ++pos; // move to the next character
	}
	
	string river("Mississippi");
	
	auto first_pos = river.find("is");  // 返回1，返回的是匹配子串的首地址
	auto last_pos = river.rfind("is");  // 返回4，反向搜索，返回的仍然是匹配子串的首地址
	cout << "find returned: " << first_pos 
	     << " rfind returned: " << last_pos << endl;
	
	string dept("03714p3");
	// returns 5, which is the index to the character 'p'
	pos = dept.find_first_not_of(numbers);	// find_first_not_of找到第一个不是的....
	cout << "first_not returned: " << pos << endl;
	
	return 0;
}
